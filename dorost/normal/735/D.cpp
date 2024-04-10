/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

bool is_prime(int x) {
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return (x > 1);
}

int32_t main() {
	int n;
	cin >> n;
	if (n == 2 || n == 3) {
		cout << 1;
	} else if (n % 2 == 0) {
		cout << 2;
	} else {
		if (is_prime(n)) {
			cout << 1;
		} else if (is_prime(n - 2)) {
			cout << 2;
		} else {
			cout << 3;
		}
	}
}