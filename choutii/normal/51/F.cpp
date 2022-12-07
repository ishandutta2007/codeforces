#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int) (x).size())
#define ALL(x) x.begin(), x.end()

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int read() {
	int x = 0, f = 1;char ch;
	for (ch = getchar(); !isdigit(ch); ch = getchar())
		if (ch == '-') f = -1;
	for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int MaxN = 201234;

int n, m;
vector <int> e[MaxN], g[MaxN];

int bel[MaxN], dfn[MaxN], low[MaxN], s[MaxN], ins[MaxN], deg[MaxN], siz[MaxN], ind, dn, sn, scc;

void dfs(int x, int fa = 0) {
	dfn[x] = low[x] = ++dn; s[++sn]= x;
	for (auto y : e[x]) {
		if(y == fa) continue;
		if(!dfn[y])
		 	dfs(y, x), cmin(low[x], low[y]);
		else
			cmin(low[x], dfn[y]);
	}
	
	if(dfn[x] == low[x]) {
		++scc;
		int cur = -1;
		while(cur != x && sn) {
			cur = s[sn--];
			++siz[scc];
			bel[cur] = scc;
		}
	}
}

map<pair<int, int> , int> hav;

int used[MaxN], d[MaxN], cur, cp;
void dfs2(int x, int fa = 0) {
	used[x] = 1;
	if(cmax(cur, d[x]))
		cp = x;
	for (auto y : g[x]) {
		if(y == fa) continue;
		d[y] = d[x] + 1;
		dfs2(y, x);
	} 
}

int main() {
//	freopen("merge.in", "r", stdin);
//	freopen("merge.out", "w", stdout);
	n = read(); m = read();
	for (int i = 1; i <= m; i++) {
		int u = read(), v = read();
		e[u].pb(v); e[v].pb(u);
	}
	for (int i = 1; i <= n; i++)
		if(!dfn[i])
			dfs(i);
	for (int x = 1; x <= n; x++)
		for (auto y : e[x]) {
			if(!hav.count(mp(bel[x], bel[y])) && bel[x] != bel[y]) {
				g[bel[x]].pb(bel[y]); 
				hav[mp(bel[x], bel[y])] = 1;
			}
		}
	
	int ans = n - 1;
	for (int x = 1; x <= scc; x++) {
		if(used[x]) continue;
		cur = 0; d[x] = 1;
		dfs2(x);
		cur = 0; d[cp] = 1;
		dfs2(cp);
		if(cur != 1) ans -= (cur - 3);
	}
	
	for (int x = 1; x <= scc; x++) {
		ans -= (SZ(g[x]) == 1);
	}
	cout << ans << endl;
	return 0;
}