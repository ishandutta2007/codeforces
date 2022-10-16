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

const int INF = 1e17 + 7, N = 1e5 + 7;

pi a[N];
int b[N][10], dp[N][1<<7];

signed main()
{
	IO_OP;
	
	int n, p, k;
	cin >> n >> p >> k;
	for(int i=1;i<=n;i++) cin >> a[i].F, a[i].S = i;
	for(int i=1;i<=n;i++)
		for(int j=0;j<p;j++)
			cin >> b[i][j];
	sort(a+1, a+n+1, greater<pi>());
	for(int i=0;i<(1<<p);i++) dp[0][i] = -INF;
	dp[0][0] = 0;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<(1<<p);j++) {
			dp[i][j] = dp[i-1][j];
			if(i - __builtin_popcount(j) <= k) dp[i][j] += a[i].F;
			for(int l=0;l<p;l++) {
				if(j >> l & 1) {
					dp[i][j] = max(dp[i][j], dp[i-1][j^(1<<l)] + b[a[i].S][l]);
				}
			}
		}
	}
	cout << dp[n][(1<<p)-1] << endl;
}