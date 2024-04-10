#include <iostream>
using namespace std;

long long n, k;

int main() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		if (n % 10 == 0) n /= 10;
		else n--;
	}
	cout << n << endl;
	return 0;
}