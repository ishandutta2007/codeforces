#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const ll MOD = 1000000007;

ll dp[100100];

vector<vector<ll>> mult(const vector<vector<ll>>& a, const vector<vector<ll>>& b) {
	int n = a.size();
	int m = b[0].size();
	vector<vector<ll>> c(n, vector<ll>(m));
	for(int i=0;i<n;++i) {
		for(int j=0;j<m;++j) {
			c[i][j] = 0;
			for(int k=0;k<n;++k) {
				c[i][j] = (c[i][j] + a[i][k]*b[k][j])%MOD;
			}
		}
	}
	return c;
}

vector<vector<ll>> pow(vector<vector<ll>> b, ll p) {
	int n = b.size();
	vector<vector<ll>> ans(n, vector<ll>(n, 0));
	for(int i=0;i<n;++i) ans[i][i] = 1;
	while(p > 0) {
		if(p&1) ans = mult(ans, b);
		//cerr << " " << (p&1) << endl;
		b = mult(b, b);
		p >>= 1;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	map<vector<ll>, int> foll;
	ll n, m;
	cin >> n >> m;
	dp[0] = 1;
	for(int i=1;i<=m*2;++i) {
		dp[i] = dp[i-1];
		if(i-m >= 0) {
			dp[i] += dp[i-m];
			if(dp[i] > MOD) dp[i] -= MOD;
		}
	}
	vector<vector<ll>> M(m, vector<ll>(m, 0));
	for(int i=0;i<m-1;++i) {
		M[i][i+1] = 1;
	}
	M[m-1][0] = 1;
	M[m-1][m-1] = 1;
	auto Q = pow(M, n);
	for(int i=0;i<m;++i) {
		for(int j=0;j<m;++j) {
			//cerr << M[i][j] << " ";
		}
		//cerr << endl;
	}
	vector<vector<ll>> b(m, vector<ll>(1, 1));
	Q = mult(Q, b);
	cout << Q[0][0] << endl;
	
	return 0;
}