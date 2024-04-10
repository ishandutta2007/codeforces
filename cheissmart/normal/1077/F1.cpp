#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(c) c.begin(),c.end()
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int dp[202][202], a[202];
const int INF = 1e15+87;

signed main()
{
	IO_OP;

	int n, k, x;
	cin >> n >> k >> x;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=x;i++)
		dp[0][i] = -INF;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<=x;j++) {
			if(i/k > j || j > i) {
				dp[i][j] = -INF;
				continue;
			}
			if(j == 0) {
				dp[i][j] = 0;
				continue;
			}
			for(int l=i;l>=max(1LL, i-k+1);l--) {
				dp[i][j] = max(dp[i][j], dp[l-1][j-1]+a[l]);
			}
		}
	}
	if(dp[n][x] < 0) cout << -1 << endl;
	else cout << dp[n][x] << endl;
}