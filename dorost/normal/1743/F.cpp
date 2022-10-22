/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
#define F first
#define S second
#define mk make_pair
#define int long long
const int N = 301234, M = 998244353;
vector <int> sta[N], en[N];

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
 
void solve() {
	int n, ans = 0;
	cin >> n;
	set <int> st;
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		sta[l].push_back(i + 1);
		en[r].push_back(i + 1);
	}
	for (int i = 0; i < N; i++) {
		for (int j : sta[i])
			st.insert(j);
		if (i)
			for (int j : en[i - 1])
				st.erase(j);
		int l = 0, x = 0;
		if (st.size())
			l = (*st.rbegin());
		if (l == 0)
			x = 0;
		else if (l == 1)
			x = 1;
		else 
			x = (2 * tav(3, l - 2)) % M;
		ll wef = (ll)x * tav(2, n - l);
		wef %= M;
		ans += wef;
		if (ans >= M)
			ans -= M;
	}
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}