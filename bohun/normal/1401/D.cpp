#include <bits/stdc++.h>
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define cat(x) cerr << #x << " = " << x << endl
#define ss(x) (int) x.size()
using ll = long long;

using namespace std;

const int N = 1e5 + 9;
const int MOD = 1e9 + 7;

int n, m, a[N], c;
ll b[N], w[N];
vector <int> G[N];

int dfs(int v, int p) {
	int siz = 1;
	
	for (auto u : G[v])
		if (u != p) {
			siz += dfs(u, v);
		}
	b[++c] = 1LL * siz * (n - siz);
	return siz;
}		

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d", &n);
		for (int i = 1; i <= n; ++i) G[i].clear();
		for (int i = 1; i < n; ++i) {
			int u, v;
			scanf ("%d%d", &u, &v);
			G[u].pb(v);
			G[v].pb(u);
		}
		scanf ("%d", &m);
		for (int i = 1; i <= m; ++i)
			scanf ("%d", a + i);
		sort(a + 1, a + m + 1);
		
		c = 0;
		dfs(1, 0);
		
		sort(b + 1, b + n);
		
		if (m <= n - 1) {
			for (int i = m + 1; i < n; ++i) a[i] = 1;
			sort(a + 1, a + n);
		}
		
		for (int i = 1; i < n; ++i)
			w[i] = 1LL * a[i] * b[i] % MOD;
			
		for (int i = n; i <= m; ++i)
			w[n - 1] = 1LL * w[n - 1] * a[i] % MOD;
			
		ll out = 0;
		for (int i = 1; i < n; ++i) out = (out + w[i]) % MOD;
		printf ("%lld\n", out);
	}
	return 0;
}