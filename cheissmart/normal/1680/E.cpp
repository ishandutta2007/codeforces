#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(v) int((v).size())
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

void cmin(int& a, int b) {
	a = min(a, b);
}

void solve() {
	int n;
	cin >> n;
	V<string> a(n);
	for(int _ = 0; _ < 2; _++) for(int i = 0; i < n; i++) {
		char c; cin >> c;
		a[i].PB(c);
	}
	auto go = [&] () {
		V<array<array<int, 2>, 2>> res;
		array<array<int, 2>, 2> dp;
		dp[0][0] = dp[0][1] = dp[1][0] = dp[1][1] = 0;
		bool flag = false;
		for(int i = 0; i < n; i++) {
			array<array<int, 2>, 2> ndp;
			ndp[0][0] = ndp[0][1] = ndp[1][0] = ndp[1][1] = INF;

			bool nflag = flag || a[i][0] == '*' || a[i][1] == '*';
			if(!nflag) {
				ndp[0][0] = ndp[0][1] = ndp[1][0] = ndp[1][1] = 0;
			} else {
				int cost[2][2] = {};
				if(a[i][0] == '*' && a[i][1] == '*')
					cost[0][0] = INF, cost[0][1] = cost[1][0] = 1, cost[1][1] = 0;
				else if(a[i][0] == '*')
					cost[0][0] = INF, cost[1][0] = 0, cost[0][1] = 1, cost[1][1] = INF;
				else if(a[i][1] == '*')
					cost[0][0] = INF, cost[0][1] = 0, cost[1][0] = 1, cost[1][1] = INF;
				else
					cost[0][0] = 0, cost[0][1] = cost[1][0] = cost[1][1] = INF;
				if(!flag) {
					cmin(ndp[0][0], cost[0][0]);
					cmin(ndp[0][0], cost[1][0]);
					cmin(ndp[1][0], cost[0][0]);
					cmin(ndp[1][0], cost[0][1]);
					ndp[0][1] = ndp[1][1] = 0;
				} else {
					cmin(ndp[0][0], dp[0][0] + cost[0][0] + 1);
					cmin(ndp[0][0], dp[0][0] + cost[1][0] + 1);
					cmin(ndp[1][0], dp[0][0] + cost[0][1] + 2);
					cmin(ndp[1][0], dp[0][0] + cost[1][1] + 2);

					cmin(ndp[1][0], dp[1][0] + cost[0][0] + 1);
					cmin(ndp[1][0], dp[1][0] + cost[0][1] + 1);
					cmin(ndp[0][0], dp[1][0] + cost[1][0] + 2);
					cmin(ndp[0][0], dp[1][0] + cost[1][1] + 2);

					
					cmin(ndp[0][1], dp[0][0] + min(cost[0][0], cost[0][1]) + 1);
					cmin(ndp[0][1], dp[0][0] + min(cost[1][0], cost[1][1]) + 1);
					cmin(ndp[1][1], dp[0][0] + min(cost[0][1], cost[1][1]) + 2);

					cmin(ndp[1][1], dp[1][0] + min(cost[0][0], cost[1][0]) + 1);
					cmin(ndp[1][1], dp[1][0] + min(cost[0][1], cost[1][1]) + 1);
					cmin(ndp[0][1], dp[1][0] + min(cost[1][0], cost[1][1]) + 2);
				}
			}
			dp = ndp;
			flag = nflag;
			res.PB(dp);
		}
		return res;
	};
	auto dpl = go();
	reverse(ALL(a));
	auto dpr = go();
	reverse(ALL(dpr));
	int ans = INF;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 2; j++) {
			ans = min(ans, dpl[i][j][0] + dpr[i][j][1]);
			ans = min(ans, dpl[i][j][1] + dpr[i][j][0]);
		}
	}
	cout << ans << '\n';
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