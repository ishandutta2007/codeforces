#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int dp[1024][10004], c[10004], cost[10004];

int32_t main()
{
	IO_OP;
	
	int n, w, b, x;
	cin >> n >> w >> b >> x;
	for(int i=1;i<=n;i++)
		cin >> c[i];
	for(int i=1;i<=n;i++)
		cin >> cost[i];
	
	memset(dp, 0xff, sizeof dp);
	dp[0][0] = w;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<10004;j++) {
			for(int k=0;k<=c[i];k++) {
				if(j >= k && dp[i-1][j-k] != -1)
					dp[i][j] = max(dp[i][j], min(dp[i-1][j-k] + x, w + (j-k) * b) - cost[i] * k);
			}
		}
	}
	int ans = 0;
	for(int j=0;j<10004;j++) {
		if(dp[n][j] >= 0)
			ans = j;
	}
	cout << ans << endl;
}