#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7, N = 404, M = 1e9 + 7;

int dp[N][N]; // dp[i][j]: # of ways to partition i things into j groups
int dp2[N][N]; // dp2[i][j]: # of ways to partition i things into j groups s.t. no group has size = 1
int comb[N][N], C[N], inv[N];

void add(int& a, int b) {
	a += b;
	if(a >= M) a -= M;
}

int ans[N];

signed main()
{
	IO_OP;

	inv[1] = 1;
	for(int i = 2; i < N; i++) inv[i] = M - (ll) M / i * inv[M % i] % M;

	comb[0][0] = 1;
	for(int i = 1; i < N; i++) {
		comb[i][0] = 1;
		for(int j = 1; j <= i; j++)
			comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % M;
	}

	dp[0][0] = 1;
	for(int i = 1; i < N; i++)
		for(int j = 1; j <= i; j++)
			add(dp[i][j], (dp[i - 1][j - 1] + (ll) dp[i - 1][j] * (i - 1) % M) % M);

	dp2[0][0] = 1;
	for(int i = 1; i < N; i++)
		for(int j = 1; j <= i; j++) {
			dp2[i][j] = dp[i][j];
			for(int k = 1; k <= j; k++)
				add(dp2[i][j], M - (ll) dp2[i - k][j - k] * comb[i][k] % M);
		}

	int n, k;
	cin >> n >> k;

	for(int i = 0; i < N; i++) { // C[i] = C(n, i)
		int ans = 1;
		for(int j = 0; j < i; j++) ans = (ll) ans * (n - j) % M;
		for(int j = 1; j <= i; j++) ans = (ll) ans * inv[j] % M;
		C[i] = ans;
	}

	ans[0] = 1;
	for(int i = 1; i <= k; i++) {
		for(int j = i + 1; j <= min(i * 2, n); j++)
			add(ans[i], (ll) dp2[j][j - i] * C[j] % M);
		if(i - 2 >= 0) add(ans[i], ans[i - 2]);
		cout << ans[i] << ' ';
	}

}