#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)

using namespace std;

const int nax = 2e5 + 111;

int n, a, b;
vector <int> v[nax];

int h[nax];
int skok[nax][18];

void dfs(int u, int p) {
	h[u] = h[p] + 1;
	skok[u][0] = p;
	rep(j, 1, 17)
		skok[u][j] = skok[skok[u][j - 1]][j - 1];
		
	for (auto it : v[u])
		if (it != p)
			dfs(it, u);
}

int lca(int x, int y) {
	if (h[x] < h[y]) swap(x, y);
	per(i, 0, 17)
		if (h[x] - (1 << i) >= h[y])	
			x = skok[x][i];
	if (x == y) return x;
	per(i, 0, 17)
		if (skok[x][i] != skok[y][i]) {
			x = skok[x][i];
			y = skok[y][i];
		}
	return skok[x][0];
}

int dis(int a, int b) {
	return h[a] + h[b] - 2 * h[lca(a, b)];
}

int main() {	
	scanf ("%d", &n);
	rep(i, 1, n - 1) {
		scanf ("%d%d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1, 0);
		
	int q;
	scanf ("%d", &q);
	while (q--) {
		int x, y, k;
		scanf ("%d%d%d%d%d",&x, &y, &a, &b, &k);
		
		if (dis(a, b) <= k && dis(a, b) % 2 == k % 2) {
			printf ("YES\n");
			continue;
		}
		int z = dis(a, x) + 1 + dis(y, b);
		if (z <= k && z % 2 == k % 2) {
			printf ("YES\n");
			continue;
		}
		z = dis(a, y) + 1 + dis(x, b);
		if (z <= k && z % 2 == k % 2) {
			printf ("YES\n");
			continue;
		}
		printf ("NO\n");
	}
		

	
	
	
	return 0;
}