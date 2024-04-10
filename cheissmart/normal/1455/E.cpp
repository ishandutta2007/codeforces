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
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

void solve() {
	pi a[4];
	for(int i = 0; i < 4; i++)
		cin >> a[i].F >> a[i].S;
	vi p({0, 1, 2, 3});
	int ans = 1e18;
	do {
		int x1 = a[p[0]].F, y1 = a[p[0]].S;
		int x2 = a[p[1]].F, y2 = a[p[1]].S;
		int x3 = a[p[2]].F, y3 = a[p[2]].S;
		int x4 = a[p[3]].F, y4 = a[p[3]].S;
		pi xl = {min(x1, x2), max(x1, x2)};
		pi xr = {min(x3, x4), max(x3, x4)};
		pi yl = {min(y1, y4), max(y1, y4)};
		pi yr = {min(y3, y2), max(y3, y2)};
		pi seg1 = {xr.F - xl.S, xr.S - xl.F};
		pi seg2 = {yr.F - yl.S, yr.S - yl.F};
		int cost = abs(x1 - x2) + abs(x3 - x4) + abs(y1 - y4) + abs(y3 - y2);
		// debug(cost);
		if(max(seg1.F, seg2.F) <= min(seg1.S, seg2.S)) {
			ans = min(ans, cost);
		} else {
			if(seg1.F > seg2.F) swap(seg1, seg2);
			cost += (seg2.F - seg1.S) * 2;
			ans = min(ans, cost);
		}
	} while(next_permutation(ALL(p)));
	cout << ans << endl;
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