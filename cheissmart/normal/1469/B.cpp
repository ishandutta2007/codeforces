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

const int INF = 1e9 + 7, N = 102;

int a[N], b[N], dp[N][N];

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i - 1];
		cin >> m;
		for(int i = 1; i <= m; i++) cin >> b[i], b[i] += b[i - 1];
		for(int i = 0; i <= n; i++) {
			for(int j = 0; j <= m; j++) {
				dp[i][j] = a[i] + b[j];
				if(i) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
				if(j) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
			}
		}
		cout << dp[n][m] << endl;
	}

}