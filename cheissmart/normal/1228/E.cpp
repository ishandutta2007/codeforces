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

const int M = 1e9 + 7;

int dp[255][255], pw[255], pww[255*255], inv[255], f[255], fi[255], n, K;

int c(int x, int y) {
	return f[x] * fi[y] % M * fi[x-y] % M;
}

void init() {
	pw[0] = 1;
	for(int i=1;i<255;i++)
		pw[i] = pw[i-1] * K % M;
	pww[0] = 1;
	for(int i=1;i<255*255;i++)
		pww[i] = pww[i-1] * (K-1) % M;
	f[0] = 1;
	for(int i=1;i<255;i++)
		f[i] = f[i-1] * i % M;
	inv[1] = 1;
	for(int i = 2; i < 255; i++)
	    inv[i] = (M - (M/i) * inv[M%i] % M) % M;
	fi[0] = 1;
	for(int i=1;i<255;i++)
		fi[i] = fi[i-1] * inv[i] % M;
}

int32_t main()
{
	IO_OP;

	cin >> n >> K;	
	if(K == 1) {
		cout << 1 << endl;
		return 0;
	}
	init();
	for(int i=1;i<=n;i++)
		dp[i][1] = 1;
	for(int j=2;j<=n;j++) {
		for(int i=1;i<=n;i++) {
			for(int k=1;k<i;k++) {
				(dp[i][j] += dp[k][j-1] * c(i, k) % M * pw[k] % M * pww[(i-k)*(j-1)] % M) %= M;
				// cout << dp[k][j-1] * c(i, k) % M * pw[k] % M << endl;
			}
			(dp[i][j] += dp[i][j-1] % M * ((pw[i]+M-pww[i])%M) % M) %= M;
			// cout << i << " " << j << ": " << dp[i][j] << endl;
		}
	}
	cout << dp[n][n] << endl;
}