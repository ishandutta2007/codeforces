#include <iostream>
using namespace std;

int main() {
	long long n, m; cin >> n >> m;
	cout << (m * (n / m) * (n / m - 1) / 2 + n / m * (n % m)) << ' ';
	cout << ((n - m) * (n - m + 1) / 2);
	return 0;
}