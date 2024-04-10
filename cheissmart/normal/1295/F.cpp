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

const int INF = 1e9 + 7, N = 55, M = 998244353;

int l[N], r[N], dp[N*2][N], C[N*2][N];

int qpow(int a, int b) {
	if(b == 0) return 1;
	int t = qpow(a, b/2);
	t = t * t % M;
	if(b & 1) return t * a % M;
	else return t;
}

int inv(int a) {
	return qpow(a, M - 2);
}

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	vi v({-INF});
	for(int i=n;i>=1;i--) {
		cin >> l[i] >> r[i];
		r[i]++;
		v.PB(l[i]), v.PB(r[i]);
	}
	sort(ALL(v));
	v.resize(unique(ALL(v))-v.begin());
	for(int i=1;i<v.size()-1;i++) {
		int len = v[i + 1] - v[i];
		C[i][0] = 1;
		for(int j=1;j<=n;j++)
			C[i][j] = C[i][j-1] * (len + j - 1) % M * inv(j) % M;
	}
	dp[0][0] = 1;
	for(int i=1;i<v.size()-1;i++) {
		int len = v[i + 1] - v[i];
		dp[i][0] = 1;
		for(int j = 1; j <= n; j++) {
			dp[i][j] = dp[i-1][j];
			for(int k = j; k >= 1; k--) {
				if(!(l[k] <= v[i] && v[i] < r[k])) break;
				dp[i][j] += dp[i-1][k - 1] * C[i][j - k + 1] % M;
			}
			dp[i][j] %= M;
		}
	}
	int di = 1;
	for(int i=1;i<=n;i++) di = di * (r[i] - l[i]) % M;
	cout << dp[v.size()-2][n] * inv(di) % M << endl;
}