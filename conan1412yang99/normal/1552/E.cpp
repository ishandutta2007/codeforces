#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;

	int n, k;
	cin >> n >> k;
	vi pos(n, -1), vis(n);
	V<pi> tt;
	vi a(n * k);
	V<pi> ans(n, {-INF, -INF});
	for(int i = 0; i < n * k; i++) {
		int x;
		cin >> x;
		x--;
		a[i] = x;
		if(vis[x]) continue;
		if(pos[x] == -1) {
			pos[x] = i;
		} else {
			vis[x] = 1;
			tt.EB(pos[x] + 1, i + 1);
		}
		if(int(tt.size()) == (n + k - 2) / (k - 1)) {
			for(pi p:tt) ans[a[p.F - 1]] = p;
			tt.clear();
			pos = vi(n, -1);
		}
	}

	for(pi p:tt) ans[a[p.F - 1]] = p;

	for(int i = 0; i < n; i++) {
		assert(ans[i] != MP(-INF, -INF));
		cout << ans[i].F << ' ' << ans[i].S << '\n';
	}

}