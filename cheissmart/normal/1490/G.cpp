#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 2e5 + 7;

void solve() {
	int n, m;
	cin >> n >> m;
	vi a(n);
	V<ll> p(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		p[i] = a[i];
		if(i) p[i] += p[i - 1];
	}
	V<ll> stk;
	vi idx;
	for(int i = 0; i < n; i++)
		if(stk.empty() || p[i] > stk.back()) {
			stk.PB(p[i]);
			idx.PB(i);
		}
	while(m--) {
		int x;
		cin >> x;
		ll ans = 0;
		if(x > stk.back()) {
			ll more = x - stk.back();
			if(p[n - 1] <= 0) {
				cout << -1 << ' ';
				continue;
			}
			ll pass = more / p[n - 1];
			more %= p[n - 1];
			if(more != 0) more = more - p[n - 1], pass++;
			ans += (ll) n * pass;
			x = stk.back() + more;
		}
		assert(x <= stk.back());
		int pos = lower_bound(ALL(stk), x) - stk.begin();
		ans += idx[pos];
		cout << ans << ' ';
	}
	cout << '\n';
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		solve();
	}

}