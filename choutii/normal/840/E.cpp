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
typedef vector<int> VI;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}

int read() {
	int x = 0, f = 1;char ch;
	for (ch = getchar(); !isdigit(ch); ch = getchar())
		if (ch == '-') f = -1;
	for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int MaxN = 50005, s = 8;

int n, q, a[MaxN], par[MaxN], dep[MaxN]; VI e[MaxN];

int f[MaxN][1 << s], up[MaxN];
void dfs(int x, int fa) {
	for (auto y : e[x]) 
		if(y != fa)
			dep[y] = dep[x] + 1, par[y] = x, dfs(y, x);
	if(dep[x] >= (1 << s)) {
		int t = x;
		for (int i = 0; i < (1 << s); i++, t = par[t])
			cmax(f[x][(((i ^ a[t]) >> 8) ^ 255)], (255 << s) | (i ^ a[t]));
		up[x] = t; 
		for (int d = 0; d < s; d++)
			for (int i = 0; i < (1 << s); i++)
				if(f[x][i] < 0 && f[x][i ^ (1 << d)] >= 0)	
					f[x][i] = f[x][i ^ (1 << d)] ^ (256 << d);
	}
}

int main() {
	memset(f, -1, sizeof(f));
	n = read(); q = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i < n; i++) {
		int u = read(), v = read();
		e[u].pb(v); e[v].pb(u);
	}
	dep[1] = 1; dfs(1, 0);
	while(q--) {
		int u = read(), v = read(), d = dep[v] - dep[u] + 1;
		d >>= s; int t = v, ans = -1;
		for (int i = 0; i < d; i++, t = up[t])
			cmax(ans, f[t][i]);	
		d <<= s;
		for (int i = d; i < dep[v] - dep[u] + 1; i++)
			cmax(ans, a[t] ^ i), t = par[t];
		printf("%d\n", ans);
	}
	return 0;
}