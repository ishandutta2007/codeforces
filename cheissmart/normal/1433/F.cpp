#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << (x) << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 72;

int a[N][N];

signed main()
{
	IO_OP;
	
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	vi dp1(k, -INF);
	dp1[0] = 0;
	for(int i = 0; i < n; i++) {
		V<vi> dp(k, vi(m / 2 + 1, -INF));
		dp[0][0] = 0;
		for(int j = 0; j < m; j++) {
			int x = a[i][j];
			V<vi> nwdp = dp;
			for(int l = 1; l < m / 2 + 1; l++) {
				for(int kk = 0; kk < k; kk++) {
					nwdp[kk][l] = max(nwdp[kk][l], dp[((kk-x)%k+k)%k][l - 1] + x);
				}
			}
			swap(nwdp, dp);
		}
		vi dp2(k, -INF);
		for(int j = 0; j < k; j++) {
			for(int l = 0; l < k; l++) {
				dp2[(j + l) % k] = max(dp2[(j + l) % k], dp1[j] + *max_element(ALL(dp[l])));	
			}
		}
		swap(dp1, dp2);
	}
	cout << dp1[0] << endl;
	
}