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

const int INF = 1e9 + 7, N = 2005;

int a[N], b[N], dp[2][N];

signed main()
{
	IO_OP;
	
	int n, h, l, r;
	cin >> n >> h >> l >> r;
	for(int i=1;i<=n;i++) cin >> a[i], b[i] = b[i-1] + a[i];
	for(int i=0;i<=n;i++) dp[0][i] = -INF;
	dp[0][0] = 0;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<=n;j++) {
			dp[i&1][j] = dp[(i&1)^1][j] + (l <= (b[i]-j) % h && (b[i]-j) % h <= r);
			if(j > 0) {
				dp[i&1][j] = max(dp[i&1][j], dp[(i&1)^1][j-1] + (l <= (b[i]-j) % h && (b[i]-j) % h <= r));
			}
		}
	}
	int mx = -INF;
	for(int i=0;i<=n;i++) mx = max(mx, dp[n&1][i]);
	cout << mx << endl;
}