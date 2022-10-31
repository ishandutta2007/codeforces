#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 105;
int dp[N][N*N]={};
const ll M = 1e9+7;

ll pw(ll a, ll b) {
	if(!b) return 1;
	if(b&1) return a * pw(a,b-1) % M;
	ll t = pw(a,b/2);
	return t * t % M;
}

ll ncr[N][N];

int main() {
	ncr[0][0] = 1;
	for(int n = 1; n < N; ++n) {
		ncr[n][0] = ncr[n][n] = 1;
		for(int r = 1; r < n; ++r)
			ncr[n][r] = (ncr[n-1][r-1] + ncr[n-1][r]) % M;
	}
	ios::sync_with_stdio(0), cin.tie(0);
	ll n,m,k;
	cin >> n >> m >> k;
	dp[0][0] = 1;
	for(int i = 1; i <= n; ++i) {
		ll a = m/n + ((i-1) < m%n);
		for(int j = n; j >= 0; --j) {
			ll pwa = pw(ncr[n][j],a);
			for(int s = i*n; s >= j; --s)
				dp[i][s] = (dp[i][s] + pwa * dp[i-1][s-j]) % M;
		}
	}
	cout << dp[n][k] << endl;
}