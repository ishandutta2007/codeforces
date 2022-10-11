#include <iostream>
using namespace std;

long long a, b, c; bool flag;

int main() {
	cin >> a >> b >> c;
	for (int i = 1; i <= 1000000; i++) {
		a *= 10;
		if (a / b == c) { cout << i << endl; flag = true; break; }
		a %= b;
	}
	if (flag == false) cout << "-1" << endl;
	return 0;
}