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

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;

	array<int, 4> n;
	for(int i = 0; i < 4; i++) cin >> n[i];
	array<vi, 4> a;
	array<vi, 4> dp;
	array<V<vi>, 3> no;
	for(int i = 0; i < 4; i++) {
		a[i].resize(n[i]);
		for(int j = 0; j < n[i]; j++)
			cin >> a[i][j];
	}
	for(int i = 0; i < 3; i++) {
		int m;
		cin >> m;
		no[i] = V<vi>(n[i + 1]);
		for(int j = 0; j < m; j++) {
			int x, y;
			cin >> x >> y;
			x--, y--;
			no[i][y].PB(x);
		}
	}
	dp[0] = a[0];
	multiset<int> dps;
	for(int i:dp[0]) dps.insert(i);
	for(int i = 1; i < 4; i++) {
		dp[i] = vi(n[i], INF);
		for(int j = 0; j < n[i]; j++) {
			vi undo;
			for(int k:no[i - 1][j]) {
				int val = dp[i - 1][k];
				undo.PB(val);
				assert(dps.find(val) != dps.end());
				dps.erase(dps.find(val));
			}
			if(dps.size()) {
				dp[i][j] = *dps.begin() + a[i][j];
			}
			for(int val:undo)
				dps.insert(val);
		}
		dps.clear();
		for(int val:dp[i])
			dps.insert(val);
	}
	int ans = *dps.begin();
	if(ans >= INF) ans = -1;
	cout << ans << '\n';
}