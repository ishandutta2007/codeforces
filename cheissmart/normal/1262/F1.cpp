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

const int M = 998244353, N = 2005;

int dp[N][N*2], a[N];

signed main()
{
	IO_OP;
	
	int n, k;
	cin >> n >> k;
	if(n == 1 || k == 1) return cout << 0 << endl, 0;
	for(int i=0;i<n;i++) cin >> a[i];
	if(a[0] == a[1]) dp[0][0+N] = k;
	else dp[0][0+N] = k - 2, dp[0][1+N] = dp[0][-1+N] = 1;
	for(int i=1;i<n;i++) {
		for(int j=-(i+1);j<=i+1;j++) {
			if(a[i] == a[(i+1)%n]) {
				dp[i][j+N] = k * dp[i-1][j+N] % M;
			} else {
				dp[i][j+N] = ((k - 2) * dp[i-1][j+N] + dp[i-1][j-1+N] + dp[i-1][j+1+N]) % M;
			}
		}
	}
	int ans = 0;
	for(int i=1;i<=n;i++) ans += dp[n-1][i+N];
	cout << ans % M << endl;
}