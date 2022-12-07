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

int n, m, h, u[MaxN];

int bel[MaxN], dfn[MaxN], low[MaxN], s[MaxN], ins[MaxN], deg[MaxN], siz[MaxN], ind, sn, scc;

vector <int> e[MaxN];
void dfs(int x) {
	dfn[x] = low[x] = ++ind;
	ins[s[++sn] = x] = 1;
	for(auto y : e[x]) 
		if(!dfn[y])
		 	dfs(y), cmin(low[x], low[y]);
		else
			if(ins[y])
				cmin(low[x], dfn[y]);
	if(dfn[x] == low[x]) {
		++scc;
		int cur = -1;
		while(cur != x && sn) {
			ins[cur = s[sn--]] = 0;
			++siz[scc];
			bel[cur] = scc;
		}
	}
}

int main() {
	n = read(); m = read(); h = read();
	for (int i = 1; i <= n; i++)
		u[i] = read();
	for (int i = 1; i <= m; i++) {
		int x = read(), y = read();
		if(u[x] == (u[y] + 1) % h)
			e[y].pb(x);
		swap(x, y);
		if(u[x] == (u[y] + 1) % h)
			e[y].pb(x);
	}
	
	for (int i = 1; i <= n; i++)
		if(!dfn[i]) 
			dfs(i);
	for (int i = 1; i <= n; i++)
		for (auto j : e[i])
			if(bel[i] != bel[j])
				++deg[bel[i]];
	int p = 0;
	for (int i = 1; i <= scc; i++)
		if(!deg[i]) 
			if(!p || siz[i] < siz[p])
				p = i;
	printf("%d\n", siz[p]);
	for (int i = 1; i <= n; i++)
		if(bel[i] == p)
			printf("%d ", i);
	return 0;
}