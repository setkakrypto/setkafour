#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void Show();
void BuyMenu();
void Money();

unsigned long long balance = 0;
int bussnes_end, busness_start, bis_small_timer_start, bis_small_timer_end, passiv = 3000;
int zavod_timer_start, zavod_timer_end;
string zavod = "Не куплен";
string bis_small = "Не куплен";

void Money() {
	zavod_timer_end = clock();
	bis_small_timer_end = clock();
	bussnes_end = clock();
	balance = (bussnes_end - busness_start) / CLOCKS_PER_SEC * passiv + balance;

	if (zavod == "Куплен") {
		balance = balance + (zavod_timer_end - zavod_timer_start) / CLOCKS_PER_SEC * 20000;
	}
	if (bis_small == "Куплен") {
		balance = balance + (bis_small_timer_end - bis_small_timer_start) / CLOCKS_PER_SEC * 5000;
	}

	busness_start = clock();
	bis_small_timer_end = clock();
	zavod_timer_start = clock();
}
void Show() {
	Money();
	cout << "Ваш баланс составляет " << balance << "$" << endl;
	cout << "Показать баланс повторно(1)" << endl;
	cout << "Вызвать меню покупки(2)" << endl;

	int b;
	cin >> b;
	switch (b) {
	case 1:
		Show();
		break;
	case 2:
		BuyMenu();
		break;
	}
}

void BuyMenu() {
	cout << endl << "Малый бизнесс		Доход:5000$		Статус: " << bis_small << endl;
	cout << "Завод              Доход:20000$    Статус: " << zavod << endl;

	cout << "Желаете приобрести один из бизнесов? (y/n)" << endl;
	char p;
	cin >> p;

	if (p == 'n')
		Show();

	if (balance < 5000) {
		cout << "\nУ вас недостаточно баланса" << endl;
		Show();
	}
	
	cout << "\nКакой бизнесс вы хотите приобрести?";
	cout << "Малый бизнесс (1) Завод (2)\n";

	int r;
	cin >> r;
	if (r != 1 && r != 2) {
		cout << "Некорректное значение !\n";
	}
	if (r == 1) {
		Money();
		bis_small = "Куплен";
		balance -= 5000;
		bis_small_timer_start = clock();
		Show();
	}
	else if (r == 2) {
		Money();
		if (balance < 20000) {
			cout << "У вас недостаточно баланса\n";
			Show();
		}
		zavod = "Куплен";
		balance -= 20000;
		zavod_timer_start = clock();
		Show();
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));

	busness_start = clock();
	Show();
	
}