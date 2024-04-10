#include<iostream>
using namespace std;
int n, x;
int main() {
	cin >> n >> x;
	while (n % 6 != 0) {
		if (n % 2 == 0) { if (x == 1)x = 2; else if (x == 2)x = 1; }
		if (n % 2 == 1) { if (x == 1)x = 0; else if (x == 0)x = 1; }
		n--;
	}
	cout << x << endl;
	return 0;
}