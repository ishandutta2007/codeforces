#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
long long n;
int main() {
	cin >> n; long long r = 1;
	if (n == 1 || n == 2) { cout << "-1" << endl; return 0; }
	while (n % 2 == 0) {
		r *= 2; n /= 2;
	}
	if (n >= 3) {
		long long R1 = n*n / 2, R2 = R1 + 1;
		cout << R1*r << ' ' << R2*r << endl;
	}
	if (n == 1) {
		cout << r * 3 / 4 << ' '  << r * 5 / 4 << endl;
	}
	return 0;
}