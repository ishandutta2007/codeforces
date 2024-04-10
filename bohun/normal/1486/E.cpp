#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = b; i >= a; --i)
#define all(x) x.begin(), x.end()
 
using ll = long long;
using namespace std;

const int N = 1 << 18;
const int M = 55;
const ll INF = 1e18;

int n, m;
vector<pair<int, int>> g[N];
ll dp[N][M][2];
set<tuple<ll, int, int, int>> T;
 
int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, m) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		g[a].pb({b, c});
		g[b].pb({a, c});
	}
	rep(i, 1, n) rep(j, 0, 50) rep(k, 0, 1) dp[i][j][k] = INF;
	dp[1][0][0] = 0;
	T.insert({0, 1, 0, 0});
	while (!T.empty()) {
		auto [cost, v, lst, id] = *T.begin();
		T.erase(T.begin());
		for (auto [u, w] : g[v]) {
			ll ncost = cost + (id ? (lst + w) * (lst + w) : 0);
			ll nlst = (id ? 0 : w);
			if (dp[u][nlst][!id] > ncost) {
				T.erase({dp[u][nlst][!id], u, nlst, !id});
				dp[u][nlst][!id] = ncost;
				T.insert({ncost, u, nlst, !id});
			}
		}
	}
	rep(i, 1, n) printf("%lld ", dp[i][0][0] == INF ? -1 : dp[i][0][0]);
	return 0;
}