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
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 0x3f3f3f3f3f3f3f3f;

int a[102][102], dp[102][102], dp2[102][102];

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
 				cin >> a[i][j];
 			}
		}
		int ans = INF;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				for(int k = 0; k <= n + 1; k++) {
					for(int l = 0; l <= m + 1; l++) {
						dp[k][l] = dp2[k][l] = INF;
					}
				}
				auto w = [&] (int x, int y) {
					int want = a[i][j] - (i - x) - (j - y);
					if(a[x][y] >= want) return a[x][y] - want;
					else return INF;
				};
				for(int k = 1; k <= i; k++) {
					for(int l = 1; l <= j; l++) {
						if(k == 1 && l == 1) {
							dp[k][l] = w(k, l);
						} else {
							dp[k][l] = min(dp[k - 1][l], dp[k][l - 1]) + w(k, l);
							dp[k][l] = min(dp[k][l], INF);
						}
					}
				}
				auto v = [&] (int x, int y) {
					int want = a[i][j] + (x - i) + (y - j);
					if(a[x][y] >= want) return a[x][y] - want;
					else return INF;
				};
				for(int k = n; k >= i; k--) {
					for(int l = m; l >= j; l--) {
						if(k == n && l == m) {
							dp2[k][l] = v(k, l);
						} else{
							dp2[k][l] = min(dp2[k + 1][l], dp2[k][l + 1]) + v(k, l);
							dp2[k][l] = min(dp2[k][l], INF);
						}
					}
				}
				ans = min(ans, dp[i][j] + dp2[i][j]);
			}
		}
		cout << ans << '\n';
	}
	
}