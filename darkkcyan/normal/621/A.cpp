#include <iostream>
#include <climits>
using namespace std;

int main() {
	int n; cin >> n;
	#define long long long 
	long sum = 0;
	long mi = LLONG_MAX;
	bool isOddOdd = 0;
	for (long a, i = 0; i < n; ++i) {
		cin >> a;
		if (a < mi and a & 1) {
			mi = a;
		}
		isOddOdd ^= a & 1;
		sum += a;
	}
	cout << (sum - isOddOdd * mi);
	return 0;
}