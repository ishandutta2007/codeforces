/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int M, a[N];
bool vis[N];

int tav(ll x, int n) {
	ll ans = 1;
	while (n) {
		if (n & 1) 
			ans = (ans * x) % M;
		n >>= 1;
		x = (x * x) % M;
	}
	return ans;
}
 
int inv(int x) {
	return tav(x, M - 2);
}

bool is_prime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0)
			return false;
	}
	return (x > 1);
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n;
	cin >> n;
	if (n == 1) {
		cout << "YES\n1";
	} else if (n == 4) {
		cout << "YES\n1\n3\n2\n4";
	} else if (!is_prime(n)) {
		cout << "NO\n";
	} else {
		M = n;
		a[1] = 1;
		a[n] = n;
		for (int i = 2; i < n; i++) {
			a[i] = ((ll)(i) * (ll)inv(i - 1)) % M;
		}
		cout << "YES\n";
		for (int i = 1; i <= n; i++) {
			cout << a[i] << '\n';
		}
	}
}