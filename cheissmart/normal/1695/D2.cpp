#include <bits/stdc++.h>
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

const int INF = 1e9 + 7;

void cmin(int& a, int b) { a = min(a, b); }

void solve() {
	int n;
	cin >> n;
	V<vi> G(n);
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v, u--, v--;
		G[u].PB(v);
		G[v].PB(u);
	}
	if(n <= 2) {
		cout << n - 1 << '\n';
		return;
	}

	V<array<array<int, 2>, 2>> dp(n); // has, need up
	function<void(int, int)> dfs = [&] (int u, int p) {
		dp[u] = {(array<int, 2>){INF, INF}, (array<int, 2>){INF, INF}};

		vi c;
		for(int v:G[u]) if(v != p) {
			dfs(v, u);
			c.PB(v);
		}
		array<array<int, 2>, 2> DP = {(array<int, 2>){INF, INF}, (array<int, 2>){INF, INF}}; // number of empty, need up
		DP[0][0] = 0;

		for(int _ = 0; _ < SZ(c); _++) {
			array<array<int, 2>, 2> nDP = {(array<int, 2>){INF, INF}, (array<int, 2>){INF, INF}};
			int v = c[_];
			for(int i = 0; i < 2; i++) {
				bool has = i < _;
				for(int j = 0; j < 2; j++) {
					for(int k = 0; k < 2; k++) if(i + (k == 0) < 2) {
						for(int l = 0; l < 2; l++) {
							if((j && k == 0) || (l && !has))
								cmin(nDP[i + (k == 0)][1], DP[i][j] + dp[v][k][l]);
							else
								cmin(nDP[i + (k == 0)][0], DP[i][j] + dp[v][k][l]);
						}
					}
				}
			}
			swap(DP, nDP);
		}

		// no
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < 2; j++) {
				cmin(dp[u][i < SZ(c)][j | i], DP[i][j]);
			}
		}
		// yes
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < 2; j++) {
				cmin(dp[u][1][i], DP[i][j] + 1);
			}
		}
	};
	int r = -1;
	for(int i = 0; i < n; i++)
		if(SZ(G[i]) == 1) {
			r = i;
			break;
		}
	assert(r != -1);
	dfs(G[r][0], r);
	int ans = INF;
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++)
			cmin(ans, dp[G[r][0]][i][j] + j);
	cout << ans << '\n';
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		solve();
	}

}