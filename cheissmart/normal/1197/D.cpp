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

const int INF = 1e17 + 7;

int a[300005], dp[300005][11];

int32_t main()
{
	IO_OP;
	
	int n, m, k;
	cin >> n >> m >> k;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			dp[i][j] = -INF;
	dp[0][0] = 0;
	dp[0][1] = a[0] - k;
	int ans = max(dp[0][0], dp[0][1]);
	if(m == 1) {
		for(int i=1;i<n;i++) {
			dp[i][1] = max(dp[i-1][1], 0LL) + a[i] - k;
			ans = max(ans, dp[i][1]);
		}
	} else {	
		for(int i=1;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(j == 1) {
					dp[i][j] = dp[i-1][0]-k+a[i];
				} else if(j == 0) {
					dp[i][j] = max(dp[i-1][m-1]+a[i], 0LL);
				} else {
					dp[i][j] = dp[i-1][j-1]+a[i];
				}
				ans = max(ans, dp[i][j]);
			}
		}
	}
	cout << ans << endl;

}