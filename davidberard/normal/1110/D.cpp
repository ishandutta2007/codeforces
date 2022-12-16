#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const int NMAX = 1001000;
const int INF = 0x3f3f3f3f;

int s[NMAX];
int m[NMAX];
int e[NMAX];
int t[NMAX];
int f[NMAX];
int dp[NMAX][3][3];
int base = 0;

int M, N;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> M >> N;
	for(int i=0;i<=N;++i) {
		for(int j=0;j<3;++j) {
			for(int k=0;k<3;++k) {
				dp[i][j][k] = -INF;
			}
		}
	}
	for(int i=0;i<M;++i) {
		int a;
		cin >> a;
		++f[a];
	}
	dp[0][0][0] = 0;
	for(int i=1;i<=N;++i) {
		for(int j=0;j<3;++j) {
			for(int k=0;k<3;++k) {
				for(int l=0;l<(i > N-2 ? 1 : 3);++l) {
					int extra = f[i]-j-k-l;
					if(extra < 0) continue;
					extra /= 3;
					////cerr << "   prev " << i-1 << " " << j << " " << k << ": " << dp[i-1][j][k] << endl;
					dp[i][k][l] = max(dp[i][k][l], dp[i-1][j][k]+l+extra);
					////cerr << "!! " << i << " " << k << " " << l << ": " << dp[i][k][l] << endl;
				}
			}
		}
	}
	int ans = -INF;
	for(int j=0;j<9;++j) {
		for(int k=0;k<9;++k) {
			ans = max(ans, dp[N][j][k]);
		}
	}
	cout << ans << endl;
	return 0;
}