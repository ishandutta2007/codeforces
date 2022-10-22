/* 	* In the name of GOD  */

#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;
#define int long long

typedef
tree<
  pair<int,int>,
  null_type,
  less<pair<int,int>>,
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234, M = 998244353;
int fac[N], inv[N];
int cnt[N], b[N], a[N], cnt2[N];
vector <int> v[N];

int tav(int x, int n) {
	if (n == 0)
		return 1;
	ll ans = tav(x, n / 2);
	ans = ans * ans;
	ans %= M;
	if (n % 2) {
		ans *= x;
		ans %= M;
	}
	return ans;
}
 
int invf(int x) {
	return tav(x, M - 2);
}

int C(int k, int n) {
	if (k > n)
		return 0;
	ll ans = fac[n];
	ans *= inv[k];
	ans %= M;
	ans *= inv[n - k];
	ans %= M;
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	fac[0] = 1;
	inv[0] = invf(1);
	for (int i = 1; i < N; i++) {
		fac[i] = ((ll)fac[i - 1] * (ll)i) % M;
		inv[i] = invf(fac[i]);
	}
	int n, m;
	cin >> n >> m;
	ordered_set st;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		st.insert(make_pair(a[i], i));
		cnt[a[i]]++;
	}
	for (int i = 0; i < n; i++) {
		v[a[i]].push_back(i);
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	ll ans = 0;
	ll in = 1, on = fac[n];
	for (int i = 0; i < N; i++) {
		on *= inv[cnt[i]];
		on %= M;
	}
	int x = (st.order_of_key(make_pair(b[0], -1)));
	ll y = on * invf(n);
	y %= M;
	y *= x;
	y %= M;
	ans += y;
	for (int i = 1; i <= m; i++) {
		if (v[b[i - 1]].empty()) {
			break;
		}
		st.erase(make_pair(b[i - 1], v[b[i - 1]].back()));
		v[b[i - 1]].pop_back();
		on *= invf(n - i + 1);
		on %= M;
		on *= (cnt[b[i - 1]] - cnt2[b[i - 1]]);
		on %= M;
		x = (st.order_of_key(make_pair(b[i], -1)));
		if (st.size() == 0) {
			if (m > n) {
				ans += 1;
				ans %= M;
				continue;
			}
		}
		y = on * invf(n - i);
		y %= M;
		y *= x;
		y %= M;
		ans += y;
		ans %= M;
		cnt2[b[i - 1]]++;
	}
	cout << (ans % M) << '\n';
}