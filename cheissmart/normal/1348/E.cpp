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
#define ckmax(a, b) (a) = max(a, b)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 505;

ll dp[N][N], a[N], b[N];

signed main()
{
	IO_OP;
	
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
	memset(dp, -1, sizeof dp);
	dp[0][0] = 0;
	int sum = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < k; j++) {
			if(dp[i][j] < 0) continue;
			int jj = (sum - j + k) % k;
			// case1
			ckmax(dp[i+1][(j + a[i]) % k], dp[i][j] + (j + a[i]) / k + (jj + b[i]) / k);
			// case2
			for(int takea = 1; takea < k; takea++) {
				int takeb = k - takea;
				if(takea <= a[i] && takeb <= b[i]) {
					int lefta = a[i] - takea, leftb = b[i] - takeb;
					ckmax(dp[i+1][(j + lefta) % k], dp[i][j] + (j + lefta)/k + (jj + leftb)/k + 1);
				}
			}
		}
		sum += a[i] + b[i];
		sum %= k;
	}
	ll mx = 0;
	for(int i = 0; i < k; i++)
		mx = max(mx, dp[n][i]);
	cout << mx << endl;
}