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

const int N = pow(27, 4) + 100;

int n, m, k, top, vis[N];
int id[N], ans[N], res[N];
char s[10];
vector<int> g[N];

void dfs(int v) {
	vis[v] = 1;
	for (auto u : g[v])
		if (!vis[u])
			dfs(u);
	ans[v] = n - top++;
}

void solve() {
	scanf("%d%d%d", &n, &m, &k);
	rep(i, 1, n) {
		scanf("%s", s);
		int mask = 0;
		rep(j, 0, k - 1) 
			mask = mask * 27 + (s[j] == '_' ? 26 : s[j] - 'a');
		id[mask] = i;
	}
	bool ok = 1;
	rep(i, 1, m) {
		int z;
		scanf("%s%d", s, &z);
		bool ok2 = 0;
		rep(mask, 0, (1 << k) - 1) {
			int cur = 0;
			rep(j, 0, k - 1) {
				if (mask >> j & 1) 
					cur = cur * 27 + (s[j] - 'a');
				else
					cur = cur * 27 + 26;
			}
			if (id[cur] != 0) {
				ok2 |= id[cur] == z;
				g[z].pb(id[cur]);
			}
		}
		ok &= ok2;
	}
	if (!ok) return printf("NO\n"), void(0);
	rep(i, 1, n)
		if (!vis[i])
			dfs(i);
	rep(i, 1, n) {
		res[ans[i]] = i;
		for (auto j : g[i])
			if (ans[i] > ans[j])
				return printf("NO\n"), void(0);
	}
	printf("YES\n");
	rep(i, 1, n)
		printf("%d ", res[i]);
	puts("");
}

int main() {
	int t = 1;
	//~ scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}