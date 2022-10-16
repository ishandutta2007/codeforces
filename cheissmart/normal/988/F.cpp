#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 0x3f3f3f3f, W = 1e5 + 7, N = 2003;

int dp[N][N], b[N], p[N], ub[N];

signed main()
{
	IO_OP;
	
	int a, n, m;
	cin >> a >> n >> m;
	for(int i=0;i<n;i++) {
		int l, r;
		cin >> l >> r;
		b[l]++, b[r]--;
	}
	for(int i=1;i<=a;i++) b[i] += b[i-1];
	for(int i=1;i<=m;i++) {
		int x;
		cin >> x >> p[i];
		if(!ub[x]) ub[x] = i;
		else if(p[ub[x]] > p[i]) ub[x] = i;
	}
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	dp[0][ub[0]] = 0;
	for(int i=1;i<=a;i++) {
		int to = INF;
		if(b[i-1]) {
			for(int j=1;j<=m;j++)
				to = min(to, dp[i-1][j] + p[j]);
		} else {
			for(int j=0;j<=m;j++)
				to = min(to, dp[i-1][j] + p[j]);
		}
		dp[i][0] = to;
		for(int j=1;j<=m;j++) {
			if(ub[i] == j) {
				dp[i][j] = min(dp[i][j], to);
			} else {
				dp[i][j] = min(dp[i][j], dp[i-1][j] + p[j]);
			}
		}
	}
	int ans = dp[a][0];
	if(ans == INF) ans = -1;
	cout << ans << endl;
}