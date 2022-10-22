/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

bool is_prime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0)
			return false;
	}
	return (x > 1);
}

int rnd(int x) {
#ifdef ONLINE_JUDGE
	return (rand() << 16 + rand()) % x;
#endif
	return (rand()) % x;
}

int ask(int a, int b) { // gcd(a, x + b)
	cout << "? " << a + b << ' ' << b << endl;
	int y;
	cin >> y;
	return y;
}

void solve() {
	int x = 0, ans = 0;
	for (int i = 0; i < 30; i++) {
		bool f = ((ask((1 << (i + 1)), x + (1 << i))) == (1 << (i + 1)));
		if (f) {
			ans += (1 << i);
			x -= (1 << i);
		}
	}
	cout << "! " << ans << endl;
}

int32_t main() {
	srand(time(NULL));
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}