#include <bits/stdc++.h>

#define fast_cin() ios_base::sync_with_stdio(0); cin.tie(0)
#define pb push_back
 
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int M = 30;

ll cnt[M], pref[M], fact[M];

ll solve(int p, int n);

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		memset(cnt, 0, sizeof(cnt));
		ll k; cin >> k;
		ll p = 2;
		while (k) {
			++cnt[k % p];
			k /= p;
			++p;
		}
		ll ans = solve(p - 2, p - 2);
		if (cnt[0]) {
			--cnt[0];
			ans -= solve(p - 2, p - 3);
		}
		cout << ans - 1 << '\n';
	}
}

ll solve(int p, int n) {
	pref[0] = cnt[0];
	for (int i = 1; i <= p; ++i) {
		pref[i] = pref[i - 1] + cnt[i];
	}
	ll ans = 1;
	for (int i = 1; i <= n; ++i) {
		ans *= (pref[i] - (i - 1));
	}
	fact[0] = 1;
	for (int i = 1; i <= p; ++i) {
		fact[i] = (i * fact[i - 1]);
	}
	for (int i = 0; i <= p; ++i) {
		ans /= fact[cnt[i]];
	}
	return ans;
}