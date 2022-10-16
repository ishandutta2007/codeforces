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

const int INF = 1e9 + 7, N = 605;

int a[N], dp[N][N];

signed main()
{
	IO_OP;

	int q;
	cin >> q;
	while(q--) {
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		sort(a + 1, a + n + 1);
		memset(dp, 0x3f, sizeof dp);
		dp[0][0] = 0;
		int ans = INF;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n * 3; j++) {
				for(int k = 0; k < j; k++) {
					dp[i][j] = min(dp[i][j], dp[i - 1][k] + abs(j - a[i]));
				}
			}
		}
		for(int i = 1; i <= n * 3; i++) ans = min(ans, dp[n][i]);
		cout << ans << '\n';
	}

}