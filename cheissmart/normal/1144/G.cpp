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

const int INF = 1e9 + 7, N = 2e5 + 7;

int a[N], dp[N][2], pre[N][2];

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	dp[0][0] = INF, dp[0][1] = -INF;
	for(int i=1;i<n;i++) dp[i][0] = -INF, dp[i][1] = INF;
	for(int i=1;i<n;i++) {
		// dp[i][0]
		if(a[i] > a[i-1] && dp[i][0] < dp[i-1][0]) {
			dp[i][0] = dp[i-1][0];
			pre[i][0] = 0;
		}
		if(dp[i-1][1] < a[i] && a[i-1] > dp[i][0]) {
			dp[i][0] = a[i-1];
			pre[i][0] = 1;
		}
		// dp[i][1]
		if(a[i] < a[i-1] && dp[i-1][1] < dp[i][1]) {
			dp[i][1] = dp[i-1][1];
			pre[i][1] = 1;
		}
		if(dp[i-1][0] > a[i] && a[i-1] < dp[i][1]) {
			dp[i][1] = a[i-1];
			pre[i][1] = 0;
		}
		// cout << i << ": "  << dp[i][0] << " " << dp[i][1] << endl;
	}
	if(dp[n-1][0] == -INF && dp[n-1][1] == INF) {
		cout << "NO" << endl;
	}else {
		cout << "YES" << endl;
		int j = 0;
		if(dp[n-1][0] == -INF) j = 1;
		vi v;
		for(int i=n-1;i>=0;i--) {
			v.PB(j);
			j = pre[i][j];
		}
		reverse(ALL(v));
		for(int e:v) cout << e << " ";
	}
	
}