#include <iostream>
using namespace std;

int n;

void solve_1() {
	if (n <= 5) {
		cout << "-1" << endl;
	}
	else {
		cout << "1 2" << endl;
		cout << "1 3" << endl;
		cout << "1 4" << endl;
		for (int i = 5; i <= n; i++) cout << "2 " << i << endl;
	}
}
void solve_2() {
	for (int i = 1; i <= n - 1; i++) cout << i << " " << i + 1 << endl;
}

int main() {
	cin >> n;
	solve_1();
	solve_2();
	return 0;
}