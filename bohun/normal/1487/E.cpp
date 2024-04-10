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

const int N = 1 << 20;
const ll INF = 1e18;

int n[5];
int c[5][N];
ll dp[5][N];
vector<int> g[5][N];

int main() {
	rep(i, 1, 4) scanf("%d", n + i);
	rep(i, 1, 4) rep(j, 1, n[i]) scanf("%d", &c[i][j]), dp[i][j] = c[i][j];
	rep(i, 1, 3) {
		int m;
		scanf("%d", &m);
		while (m--) {
			int a, b;
			scanf("%d%d", &a, &b);
			g[i + 1][b].pb(a);
		}
	}
	rep(i, 2, 4) {
		multiset<ll> T;
		rep(j, 1, n[i - 1]) T.insert(dp[i - 1][j]);
		rep(j, 1, n[i]) {
			for (auto x : g[i][j])
				T.erase(T.find(dp[i - 1][x]));
			dp[i][j] += (T.empty() ? INF : *T.begin());
			for (auto x : g[i][j])
				T.insert(dp[i - 1][x]);
		}
	}
	ll ans = INF;
	rep(i, 1, n[4]) ans = min(ans, dp[4][i]);
	printf("%lld\n", ans < INF ? ans : -1);
	return 0;
}