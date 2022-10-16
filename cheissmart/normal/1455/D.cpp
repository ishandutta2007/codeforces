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

const int INF = 1e9 + 7, N = 505;

int dp[N][N][N], a[N];
/*
	dp[i][x][at_least]
*/

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		int n, x;
		cin >> n >> x;
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = n - 1; i >= 0; i--) {
			for(int j = 0; j <= 500; j++) {
				for(int k = 0; k <= 500; k++) {
					dp[i][j][k] = INF;
					if(i == n - 1) {
						if(a[i] >= k) dp[i][j][k] = 0;
					} else {
						if(a[i] > a[i + 1]) { 
							if(j < k) continue;
							if(j > a[i + 1]) continue;
							assert(a[i] > j);
							dp[i][j][k] = dp[i + 1][a[i]][j] + 1;
						} else {
							if(a[i] >= k) dp[i][j][k] = min(dp[i][j][k], dp[i + 1][j][a[i]]);
							if(j < a[i] && j >= k) {
								dp[i][j][k] = min(dp[i][j][k], dp[i + 1][a[i]][j] + 1);
							}
						}
					}
				}
			}
		}
		int ans = dp[0][x][0];
		if(ans > 1e8) ans = -1;
		cout << ans << endl;
	}
}