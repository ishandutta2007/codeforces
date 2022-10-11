#include <iostream>
using namespace std;

long long n, sum;

int main() {
	cin >> n;
	for (int i = 2; i < n; i++) sum += 1LL * i*(i + 1);
	cout << sum << endl;
	return 0;
}