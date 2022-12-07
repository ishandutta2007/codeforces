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

const int MaxN = 201234, M = 65, P = 1e9 + 7;

int n, m; vector <pii> e[MaxN]; int t[M], ans[M], res[M], fac[MaxN];

int id[MaxN], n1, n2, un, u[M << 1], v[M << 1], w[M << 1];

void dfs(int x) {
	if(x <= n)
		id[x] = ++n1;
	else
		id[x] = ++n2; 
	for (int i = 0; i < SZ(e[x]); i++) {
		if(!id[e[x][i].fi])
			dfs(e[x][i].fi);
		if(x <= n) {
			++un; u[un] = id[x]; v[un] = id[e[x][i].fi]; w[un] = e[x][i].se; 
		}
	}
}

int f[1 << M / 3], g[1 << M / 3];
void bitmask() {
	if(n1 < n2) {
		swap(n1, n2);
		for (int i = 1; i <= un; i++)
			swap(u[i], v[i]);
	}
	for (int i = 1; i <= un; i++)
		for (int j = i + 1; j <= un; j++)
			if(u[i] > u[j])
				swap(u[i], u[j]), swap(v[i], v[j]), swap(w[i], w[j]);
	memset(f, 0, sizeof(f));
	f[0] = 1;
	int up = 1 << n2;
	for (int i = 1; i <= un; i++) {
		int x = u[i]; 
		for (int s = 0; s < up; s++)
			g[s] = f[s];
		while(i <= un && u[i] == x) {
			int y = v[i] - 1;
			for (int s = 1; s < up; s++)
				if(s >> y & 1)
					f[s] = (f[s] + (LL) g[s ^ (1 << y)] * w[i]) % P; 
			i++;
		}
		i--;
	}
	for (int i = 0; i <= m; i++)
		res[i] = 0;
	for (int s = 0; s < up; s++) 
		(res[__builtin_popcount(s)] += f[s]) %= P;
	int t[M];
	for (int i = 0; i <= m; i++)
		t[i] = ans[i], ans[i] = 0;
	for (int i = 0; i <= m; i++)
		for (int j = 0; i + j <= m; j++)
			ans[i + j] = (ans[i + j] + (LL) t[i] * res[j]) % P;
}

int used[MaxN];
void dfs(int x, int fa) {
	used[x] = 1; id[x] = ++n1;
	for (int i = 0; i < SZ(e[x]); i++) {
		int y = e[x][i].fi;
		if(!used[y])
			dfs(y, x);
		else
			if(y != fa && x <= n) {
				++un; u[un] = x; v[un] = y; w[un] = e[x][i].se; 
			}
	}
}

int dp[M << 1][M][2], c[M], siz[MaxN];

void trans(int x, int y, int w) {
	for (int l = siz[x] + siz[y] >> 1; l >= 0; l--)
		for (int r = min(l - 1, siz[x]); r >= 0; r--) {
			dp[x][l][0] = (dp[x][l][0] + (LL) dp[x][r][0] * (dp[y][l - r][0] + dp[y][l - r][1])) % P;
			dp[x][l][1] = (dp[x][l][1] + (LL) dp[x][r][1] * (dp[y][l - r][0] + dp[y][l - r][1])) % P;
			dp[x][l][1] = (dp[x][l][1] + (LL) dp[x][r][0] * dp[y][l - r - 1][0] % P * w) % P;
		}
}

void dfs2(int x) {
	int u = id[x];
	memset(dp[u], 0, sizeof(dp[u]));
	dp[u][0][c[u]] = 1; siz[u] = 1; used[u] = 1;
	for (int i = 0; i < SZ(e[x]); i++) {
		int y = e[x][i].fi; if(!used[id[y]]) {
			dfs2(y);
			trans(u, id[y], e[x][i].se);
			siz[u] += siz[id[y]];
		}
	}
}

void tree(int x) {
	memset(used, 0,sizeof(used));
	n1 = un = 0;
	dfs(x, 0);
	int up = 1 << un;
	int t[M];
	for (int i = 0; i <= m; i++)
		t[i] = ans[i], ans[i] = 0;
	for (int s = 0; s < up; s++) {
		memset(c, 0, sizeof(c));
		LL tv = 1, loved = 0;
		for (int i = 1; i <= un; i++) {
			if(s >> (i - 1) & 1) {
				tv = (LL) tv * w[i] % P;
				if(c[id[u[i]]] || c[id[v[i]]])
					loved = 1;
				c[id[u[i]]] = c[id[v[i]]] = 1;
			}
		}
		if(loved) continue;
		for (int i = 0; i < 100; i++)
			used[i] = 0;
		dfs2(x);
		for (int i = 0; i < n1; i++) {
			int cnt = __builtin_popcount(s);
			for (int k = i + cnt; k <= m; k++) {
				ans[k] = (ans[k] + (LL) (dp[1][i][0] + dp[1][i][1]) * t[k - i - cnt] % P * tv) % P;
			}
		}
	} 
}
int main() {
	n = read(); m = read();
	for (int i = 0; i < m; i++) {
		int u = read(), v = read() + n, w = read() - 1;
		e[u].pb(mp(v, w)); e[v].pb(mp(u, w));
	}
	
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = (LL) fac[i - 1] * i % P;
		 
	ans[0] = 1; 
	int lim = m / 3; 
	for (int i = 1; i <= n; i++) {
		if(!id[i] && SZ(e[i])) {
			n1 = n2 = un = 0;
			dfs(i);
			int n = min(n1, n2);
			if(n <= lim) 
				bitmask();
			else 
				tree(i);
		}
	}
	int Ans = 0;
	for (int i = 0; i <= min(n, m); i++)
		Ans = (Ans + (LL) fac[n - i] * ans[i]) % P;
	printf("%d ", Ans);
	return 0;
}