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

const int INF = 1e9 + 7, N = 4004, M = 998244353;

int dp[N][N][2];

int qpow(int a, int b) {
	if(b == 0) return 1;
	ll t = qpow(a, b / 2);
	t = t * t % M;
	if(b & 1) return t * a % M;
	else return t;
}

int fact(int n) {
	if(n == 0) return 1;
	return (ll) n * fact(n - 1) % M;
}

void add(int& a, int b) {
	a += b;
	if(a >= M) a -= M;
}

signed main()
{
	IO_OP;

	int n, k, l;
	cin >> n >> k >> l;
	dp[0][0][0] = 1;
	for(int i = 1; i <= 2 * n + 1; i++) {
		for(int j = 0; j <= n; j++) {
			if(j + 1 <= n) add(dp[i][j][0], (ll) (j + 1) * dp[i - 1][j + 1][0] % M);
			if(j - 1 >= 0) add(dp[i][j][0], dp[i - 1][j - 1][0]);
			if(j >= k) add(dp[i][j][1], dp[i - 1][j][0]);
			if(j + 1 <= n) add(dp[i][j][1], (ll) (j + 1) * dp[i - 1][j + 1][1] % M);
			if(j - 1 >= 0) add(dp[i][j][1], dp[i - 1][j - 1][1]);
		}
	}
	int ans = (ll) dp[n * 2 + 1][0][1] * qpow(2, n) % M * fact(n) % M * qpow(fact(n * 2 + 1), M - 2) % M * l % M;
	cout << ans << endl;
	
}