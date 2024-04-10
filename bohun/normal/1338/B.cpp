#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
 
using namespace std;

const int nax = 2e5 + 100;
const int mod = 1e9 + 7;

int n, a, b;
vector <int> g[nax];
int c[nax];
int t[2];
int ans;

void dfs(int v, int p) {
	c[v] = !c[p];
	int pp = 0;
	for (auto it : g[v]) {
		if (it != p) {
			dfs(it, v);
			if (ss(g[it]) == 1) pp++;
		}
	}
	if (pp > 0) ans -= pp - 1;
}

int main() {
	scanf ("%d", &n);
	ans = n - 1;
	rep(i, 1, n - 1) {
		scanf ("%d%d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	int root = 0;
	rep(i, 1, n) if (ss(g[i]) > 1) {
		root = i;
		break;
	}
	//cat(root);
	dfs(root, 0);
	rep(i, 1, n) 
		if (ss(g[i]) == 1)
			t[c[i]]++;
	if (t[0] && t[1]) printf ("3 ");
	else printf ("1 ");
	printf ("%d\n", ans);
	
	return 0;
}