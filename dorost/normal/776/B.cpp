/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N], f[N];

bool is_prime(int x) {
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return (x > 1);
}

void solve() {
	int n, mx = 0;
	cin >> n;
	if (n < 3) {
		cout << 1 << '\n';
	} else {
		cout << 2 << '\n';
	}
	for (int i = 2; i <= n + 1; i++) {
		cout << (1 - is_prime(i)) + 1 << ' ';
	}
}

int32_t main() {
	solve();
}