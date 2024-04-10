#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int M = 998244353;

int inv[100005], dp[55][55][55][55], a[55], w[55], ans[55];

int32_t main()
{
	IO_OP;
	
	inv[1] = 1;
	for(int i=2;i<100005;i++)
		inv[i] = (M - M/i) * inv[M % i] % M;
	int n, m, p = 0, q = 0;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<n;i++) {
		cin >> w[i];
		if(a[i]) p += w[i];
		else q += w[i];
	}
	int s = p + q;
	for(int i=0;i<n;i++)
		dp[0][0][i][0] = 1;
	for(int i=0;i<=m;i++) {
		for(int j=0;j+i<=m&&j<=q;j++) {
			for(int k=0;k<n;k++) {
				for(int l=0;l<=(a[k]?i:j);l++) {
					if(i == 0 && j == 0 && l == 0) continue;
					int & d = dp[i][j][k][l];
					if(i)
						d += dp[i-1][j][k][l] * (p+i-1-(a[k]?w[k]+l:0)) % M * inv[s+i-1-j] % M;
					if(j)
						d += dp[i][j-1][k][l] * (q-(j-1)-(!a[k]?w[k]-l:0)) % M * inv[s+i-j+1] % M;
					int ii = i - a[k], jj = j - !a[k];
					if(ii >= 0 && jj >= 0 && l > 0)
						d += dp[ii][jj][k][l-1] * (w[k]+(l-1)*(2*a[k]-1)) % M * inv[s+ii-jj] % M;
					d %= M;
				}
			}
		}
	}
	for(int i=0;i<=m;i++)
		for(int k=0;k<n;k++)
			for(int l=0;l<=(a[k]?i:m-i);l++) {
				ans[k] += dp[i][m-i][k][l] * max(w[k]+l*(a[k]*2-1), 0ll) % M;
				ans[k] %= M;
			}
	for(int i=0;i<n;i++)
		cout << ans[i] << endl;
}