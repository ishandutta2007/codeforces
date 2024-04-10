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

const int INF = 1e9 + 7, N = 2e5 + 7;

unordered_set<int> G[N];

signed main()
{
	IO_OP;

	int n, m, q;
	cin >> n >> m >> q;
	bool exchange = false;
	if(n > m)  {
		swap(n, m);
		exchange = true;
	}
	for(int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		if(exchange) swap(a, b);
		a--, b--;
		G[a].insert(b);
	}
	int K = m / n + 50 + 3;
	V<vi> dp(n, vi(K, -1));
	dp[0][0] = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < K - 1; j++) if(dp[i][j] != -1) {
			int k = dp[i][j];
			int money = i + k + 2 + int(G[i].count(k)) - 1;
			if(k + 1 < m)
				dp[i][j + 1] = max(dp[i][j + 1], min(money, m - 1));
			if(i + 1 < n)
				dp[min(money, n - 1)][j + 1] = max(dp[min(money, n - 1)][j + 1], k);
		}
	}
	for(int i = 0; i < K; i++)
		if(dp[n - 1][i] == m - 1) {
			cout << i << '\n';
			return 0;
		}

}