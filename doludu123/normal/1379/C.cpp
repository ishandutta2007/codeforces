#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto y : a) cout << y << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 200087, logN = 17, K = 350;

void solve() {
	int n, m;
	cin >> n >> m;
	vector <pll> v(m);
	vector <lli> vv(m);
	fop (i,0,m) {
		cin >> v[i].X >> v[i].Y;
		vv[i] = v[i].X;
	}
	sort(all(v), [](pll a, pll b) {
		return a.X > b.X;
	});
	sort(all(vv));
	lli ans = 0, mx = 0, sz = 0, pre[m + 1];
	pre[0] = 0;
	fop (i,0,m) {
		ans = max(ans, v[i].X + v[i].Y * (n - 1));
		pre[i + 1] = pre[i] + v[i].X;
	}/*
	5 2
	4 2
	3 1
 	*/
	fop (i,0,m) {
		if (mx <= v[i].Y) {
			mx = v[i].Y;
			sz = m - (lower_bound(all(vv), mx) - vv.begin());
			if (sz >= i) sz = i;
			if (n - 1 >= sz) ans = max(ans, pre[sz] + v[i].X + mx * (n - sz - 1));
		} else if (v[i].X > mx) {
			if (n - 1 >= i) ans = max(ans, pre[i + 1] + mx * (n - i - 1));
		}
	}
	cout << ans << endl;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int ta;
    cin >> ta;
    while (ta--) {
    	solve();
	}
}