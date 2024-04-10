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

const int INF = 1e9 + 7, N = 505;

int dp[N][N], a[N];
int dp1[N];

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];	
	for(int i=1;i<=n;i++) dp[i][i] = a[i];
	for(int len=2;len<=n;len++) {
		for(int i=1;i+len-1<=n;i++) {
			int j = i + len - 1;
			for(int k=i;k<j;k++) {
				if(dp[i][k] != 0 && dp[k+1][j] != 0 && dp[i][k] == dp[k+1][j]) {
					dp[i][j] = dp[i][k] + 1;
				}
			}
		}
	}
	memset(dp1, 0x3f, sizeof dp1);
	dp1[0] = 0;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=i;j++) {
			if(dp[j][i]) {
				dp1[i] = min(dp1[i], dp1[j-1] + 1);
			}
		}
	}
	cout << dp1[n] << endl;

}