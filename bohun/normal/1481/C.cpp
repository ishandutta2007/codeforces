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

const int N = 1 << 17;

int n, m, p[N], a[N], b[N], c[N], ans[N];
vector<int> g[N];

void solve() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) {
		g[i].clear();
		p[i] = 0;
	}
	rep(i, 1, n) scanf("%d", a + i);
	rep(i, 1, n) scanf("%d", b + i), g[b[i]].pb(i);
	rep(i, 1, m) scanf("%d", c + i);
	rep(i, 1, n)
		sort(g[i].begin(), g[i].end(), [&](int x, int y) {
			return (a[x] == b[x]) > (a[y] == b[y]);
		});
	if (g[c[m]].empty()) return printf("NO\n"), void(0);
	rep(i, 1, m) {
		int x = c[i];
		if (g[x].empty()) {
			ans[i] = g[c[m]].back();
			a[ans[i]] = x;
		}
		else {
			while (p[x] + 1 < sz(g[x]) && a[g[x][p[x]]] == b[g[x][p[x]]])
				p[x]++;
			ans[i] = g[x][p[x]];
			a[ans[i]] = x;
		}
	}
	rep(i, 1, n) if (a[i] != b[i]) return printf("NO\n"), void(0);
	puts("YES");
	rep(i, 1, m)
		printf("%d ", ans[i]);
	puts("");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}