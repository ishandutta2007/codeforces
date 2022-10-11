#include <iostream>
#include <cmath>
using namespace std;
#pragma warning (disable: 4996)

int X, Y, Z, T1, T2, T3;

int main() {
	cin >> X >> Y >> Z >> T1 >> T2 >> T3;
	int A1 = abs(X - Y) * T1;
	int A2 = T3 * 3 + abs(X - Z) * T2 + abs(X - Y) * T2;

	if (A1 >= A2) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}