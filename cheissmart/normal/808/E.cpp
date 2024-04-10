#include <bits/stdc++.h>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define V vector
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "LINE(" << __LINE__ << ") -> " << #x << " is " << x << endl
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;
 
const int INF = 1e9 + 7, N = 3e5 + 7;
 
signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);
 
	mt19937 rng(time(0));
 
	int n, m;
	// n = 1000, m = 2000;
	cin >> n >> m;
	V<ll> a, b, c;
	for(int i = 0; i < n; i++) {
		int w, C;
		cin >> w >> C;
		// w = rng() % 3 + 1, C = rng() % 1000000000 + 1;
		if(w == 1) a.PB(C);
		else if(w == 2) b.PB(C);
		else c.PB(C);
	}
	sort(ALL(a), greater<int>());
	sort(ALL(b), greater<int>());
	sort(ALL(c), greater<int>());
	while(a.size() < m) a.PB(0);
 
	auto psum = [&] (V<ll>& a) {
		for(int i = 1; i < a.size(); i++) {
			a[i] += a[i - 1];
		}
	};
	psum(a), psum(b), psum(c);
 
	auto go_ab = [&] (int m) {
		int lb = 0, rb = min(m / 2, (int) b.size());
		auto cost = [&] (int take2) {
			assert(take2 <= m / 2 && take2 <= b.size());
			ll res = 0;
			if(take2) res += b[take2 - 1];
			int have = m - take2 * 2;
			if(have) res += a[have - 1];
			return res;
		};
		while(lb < rb) {
			int m1 = lb + (rb - lb) / 3, m2 = rb - (rb - lb) / 3;
			assert(m1 < m2);
			ll c1 = cost(m1), c2 = cost(m2);
			if(c1 < c2) {
				lb = m1 + 1;
			} else {
				rb = m2 - 1;
			}
		}
		assert(lb == rb);
		return cost(lb);
	};
 
	ll ans = 0;
 
	for(int tc = 0; tc <= min(m / 3, (int)c.size()); tc++) {
		ll cost = 0;
		if(tc) cost += c[tc - 1];
		int have = m - 3 * tc;
		cost += go_ab(have);
		ans = max(ans, cost);
	}
	cout << ans << '\n';
 
}