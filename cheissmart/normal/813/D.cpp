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

const int INF = 1e9 + 7, N = 5005;

int a[N], dp[N][N], pre[N];
int mxdp1[100005];

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	for(int i = 1; i <= n; i++) {
		pre[i] = 1;
		for(int j = 1; j < i; j++)
			if(abs(a[j] - a[i]) == 1 || a[j] % 7 == a[i] % 7)
				pre[i] = max(pre[i], pre[j] + 1);
 	}
 	memset(mxdp1, 0xc0, sizeof mxdp1);

	int mx = 0;
	for(int i = 1; i <= n; i++) {
		vi mxdp2(7, -INF);
		for(int j = 1; j <= n; j++) {
			if(i == j) {
				dp[i][j] = -INF;
				continue;
			}
			if(i < j) {
				dp[i][j] = pre[i] + 1;
				dp[i][j] = max(dp[i][j], mxdp1[a[j] + 1] + 1);
				dp[i][j] = max(dp[i][j], mxdp1[a[j] - 1] + 1);
				dp[i][j] = max(dp[i][j], mxdp2[a[j] % 7] + 1);
			} else {
				dp[i][j] = dp[j][i];
			}
			if(mxdp1[a[j]] < dp[i][j])
				mxdp1[a[j]] = dp[i][j];
			mxdp2[a[j] % 7] = max(mxdp2[a[j] % 7], dp[i][j]);
			mx = max(mx, dp[i][j]);
		}
		for(int j = 1; j <= n; j++)
			mxdp1[a[j]] = -INF;
	}
	cout << mx << '\n';

}