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

const int INF = 1e9 + 7, N = 2e5 + 7;

int deg[N], dp[N];
vi G[N];

signed main()
{
	IO_OP;

	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		G[v].PB(u);
		deg[u]++;
	}

	for(int i = 1; i <= n; i++)
		dp[i] = INF;

	priority_queue<pi, V<pi>, greater<pi>> pq;

	dp[n] = 0;
	pq.push({dp[n], n});

	while(pq.size()) {
		auto[val, u] = pq.top(); pq.pop();
		if(val > dp[u]) continue;
		for(int v:G[u]) {
			deg[v]--;
			if(dp[u] + deg[v] + 1 < dp[v]) {
				dp[v] = dp[u] + deg[v] + 1;
				pq.push({dp[v], v});
			}
		}
	}

	cout << dp[1] << '\n';

}