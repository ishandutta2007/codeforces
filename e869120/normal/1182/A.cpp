#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

int main() {
	int n; cin >> n;
	if (n % 2 == 1) cout << "0" << endl;
	else cout << (1 << (n / 2)) << endl;
	return 0;
}