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

const int INF = 1e9 + 7, N = 1e5 + 7;

int a[N];

int dp[N][66];

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)cin >> a[i];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 66; j++) {
			dp[i][j] = -INF;
		}
	}
	int ans = 0;
	dp[0][a[0]+30] = a[0];
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < 66; j++) {
			int jj = j - 30;
			if(jj == a[i]) {
				dp[i][j] = jj;
				for(int k = 0; k <= j; k++) {
					dp[i][j] = max(dp[i][j], dp[i - 1][k] + jj);
				}
			} else if(jj > a[i]) {
				dp[i][j] = dp[i - 1][j] + a[i];
			}
			ans = max(ans, dp[i][j] - jj);
		}
	}
	cout << ans << endl;
}