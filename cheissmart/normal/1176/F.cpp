#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int dp[200005][10];

int32_t main()
{
	IO_OP;
	
	int n;
	cin >> n;
	memset(dp, 0xff, sizeof dp);
	dp[0][0] = 0;
	for(int i=1;i<=n;i++) {
		int k;
		cin >> k;
		vi x, y, z;
		for(int i=0;i<k;i++) {
			int c, d;
			cin >> c >> d;
			if(c == 1) x.PB(d);
			else if(c == 2) y.PB(d);
			else z.PB(d);
		}
		sort(ALL(x), greater<int>());
		sort(ALL(y), greater<int>());
		sort(ALL(z), greater<int>());
		for(int j=0;j<10;j++)
			dp[i][j] = dp[i-1][j];
		for(int j=0;j<10;j++) {
			if(dp[i-1][j] < 0) continue;
			if(x.size() >= 3) {
				if(j+3 < 10) dp[i][j+3] = max(dp[i][j+3], dp[i-1][j] + x[0] + x[1] + x[2]);
				else dp[i][j-7] = max(dp[i][j-7], dp[i-1][j] + x[0] + x[0] + x[1] + x[2]);
			}
			if(x.size() >= 2){
				if(j+2 < 10) dp[i][j+2] = max(dp[i][j+2], dp[i-1][j] + x[0] + x[1]);
				else dp[i][j-8] = max(dp[i][j-8], dp[i-1][j] + x[0] + x[0] + x[1]);
			}
			if(x.size() >= 1){
				if(j+1 < 10) dp[i][j+1] = max(dp[i][j+1], dp[i-1][j] + x[0]);
				else dp[i][j-9] = max(dp[i][j-9], dp[i-1][j] + x[0] + x[0]);
			}
			if(y.size() >= 1){
				if(j+1 < 10) dp[i][j+1] = max(dp[i][j+1], dp[i-1][j] + y[0]);
				else dp[i][j-9] = max(dp[i][j-9], dp[i-1][j] + y[0] + y[0]);
			}
			if(z.size() >= 1){
				if(j+1 < 10) dp[i][j+1] = max(dp[i][j+1], dp[i-1][j] + z[0]);
				else dp[i][j-9] = max(dp[i][j-9], dp[i-1][j] + z[0] + z[0]);
			}
			if(x.size() >= 1 && y.size() >= 1){
				if(j+2 < 10) dp[i][j+2] = max(dp[i][j+2], dp[i-1][j] + x[0] + y[0]);
				else dp[i][j-8] = max(dp[i][j-8], dp[i-1][j] + x[0] + y[0] + max(x[0], y[0]));
			}
		}
	}	
	int ans = 0;
	for(int i=0;i<10;i++)
		ans = max(ans, dp[n][i]);
	cout << ans << endl;
}