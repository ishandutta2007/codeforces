/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012;
bool f[N];

bool is_prime(int x) {
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return (x > 1);
}

int32_t main() {
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		if (is_prime(i)) {
			for (int j = i; j <= n; j *= i) {
				f[j] = true;
			}
		}
	}
	int x = 0;
	for (int i = 1; i <= n; i++) {
		if (f[i]) {
			x++;
		}
	}
	cout << x << '\n';
	for (int i = 1; i <= n; i++) {
		if (f[i]) {
			cout << i << ' ';
		}
	}
}