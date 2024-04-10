#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(v) int((v).size())
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

const int INF = 1e9 + 7, N = 5005;

namespace mod {
	int M;

	inline void add(int& a, int b) {
		a += b;
		if(a >= M) a -= M;
	}
	inline int ad(int a, int b) {
		return add(a, b), a;
	}
	inline int mu(int a, int b) {
		return int(1LL * a * b % M);
	}
	inline void mul(int& a, int b) {
		a = mu(a, b);
	}

	int comb[N][N];

	void init() {
		for(int i = 0; i < N; i++) {
			comb[i][0] = 1;
			for(int j = 1; j <= i; j++)
				comb[i][j] = ad(comb[i - 1][j - 1], comb[i - 1][j]);
		}
	}

	int C(int n, int k) {
		return comb[n][k];
	}
}

using namespace mod;

// tree
int dp[N][3];
int dpp[N][2];
int ddp[N];

/*
0: self
1: someone
2: waiting for someone
*/

// jellyfish
int dp2[N][2][2];
int aux[N], bad[N];

// functional graph
int dp3[N];
	
signed main()
{
	IO_OP;

	int n;
	cin >> n >> M;

	mod::init();

	dp[1][0] = 1;
	dp[1][2] = 1;

	for(int i = 2; i <= n; i++) {
		for(int nw = 1; nw < i; nw++) {
			int old = i - nw;
			int ways = mu(C(i - 2, nw - 1), nw);
			add(dp[i][0], 1LL * dp[nw][1] * dp[old][0] % M * ways % M);
			add(dp[i][1], 1LL * (dp[nw][0] + dp[nw][1]) * dp[old][1] % M * ways % M);
			int val = 1LL * (dp[nw][0] + dp[nw][1]) * dp[old][2] % M * ways % M;
			add(dp[i][2], val);
			add(dp[i][1], val);
		}
	}
	for(int i = 1; i <= n; i++) {
		dpp[i][0] = dp[i][0];
		dpp[i][1] = ad(dp[i][1], dp[i][2]);
	}
	for(int s = 0; s < 2; s++)
		dp2[1][s][s] = dpp[1][s];
 
	for(int i = 2; i <= n; i++) {
		for(int nw = 1; nw < i; nw++) {
			int old = i - nw;
			int ways = mu(C(i - 1, nw), nw);
			int pre[] = {mu(dpp[nw][0], ways), mu(dpp[nw][1], ways)};
			for(int s = 0; s < 2; s++) {
 				add(dp2[i][s][0], mu(dp2[old][s][1], pre[0]));
 				add(dp2[i][s][1], 1LL * (dp2[old][s][1] + dp2[old][s][0]) * pre[1] % M);
			}
		}
		for(int s = 0; s < 2; s++) for(int t = (s == 0); t < 2; t++)
			add(aux[i], dp2[i][s][t]);
		for(int s = 0; s < 2; s++)
			add(dp2[i][s][s], mu(dpp[i][s], i));
	}

	for(int i = 1; i <= n; i++)
		ddp[i] = mu(dp[i][2], i);

	bad[1] = ddp[1];
	for(int i = 2; i <= n; i++) {
		for(int j = 1; j < i; j++)
			add(bad[i], mu(bad[i - j], mu(ddp[j], C(i - 1, j))));
		add(aux[i], M - bad[i]);
		add(bad[i], ddp[i]);
	}

	dp3[0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= i; j++) {
			add(dp3[i], mu(mu(dp3[i - j], aux[j]), C(i - 1, j - 1)));
		}
	}

	cout << dp3[n] << '\n';

}