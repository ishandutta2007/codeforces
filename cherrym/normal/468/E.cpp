#include <bits/stdc++.h>

template <class T>
inline void read(T &res) {
  res = 0; bool bo = 0; char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-');
  if (c == '-') bo = 1; else res = c - 48;
  while ((c = getchar()) >= '0' && c <= '9')
    res = (res << 3) + (res << 1) + (c - 48);
  if (bo) res = ~res + 1;
}

const int N = 1e5 + 5, M = N << 1, Z = 55, C = (1 << 18) + 5, RX = 1e9 + 7;

int n, k, fac[N], res[Z], ans, ecnt, nxt[N], adj[M], go[N], val[N],
tot, a[N], b[N], c[N], dep[M], tot1, p1[N], tot2, p2[N], cnt, is[M],
f[M][Z], g[M][Z], sze[M], xf[Z], xg[Z], cur[Z], h[Z][C], id[M];
std::vector<int> son[M], sonv[M];
bool vis[M], occ[M];

void add_edge(int u, int v, int w) {
  nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v; val[ecnt] = w;
  nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u; val[ecnt] = w;
}

void dfs(int u) {
  vis[u] = 1;
  (u <= n ? p1[++tot1] : p2[++tot2]) = u;
  for (int e = adj[u], v; e; e = nxt[e])
    if (!vis[v = go[e]]) dep[v] = dep[u] + 1, dfs(v),
	  son[u].push_back(v), sonv[u].push_back(val[e]), cnt++;
    else if (dep[u] < dep[v])
	  a[++tot] = u, b[tot] = v, c[tot] = val[e], cnt++;
}

void dp(int u) {
  sze[u] = 1; f[u][0] = 0; g[u][0] = 1;
  for (int i = 0; i < son[u].size(); i++) {
  	int v = son[u][i], w = sonv[u][i]; dp(v);
  	for (int i = 0; i <= (sze[u] + sze[v] >> 1); i++)
  	  xf[i] = xg[i] = 0;
  	for (int i = 0; i <= (sze[u] >> 1); i++)
  	  for (int j = 0; j <= (sze[v] >> 1); j++) {
  	  	xf[i + j] = (1ll * f[u][i] * (f[v][j] + g[v][j]) + xf[i + j]) % RX;
  	  	xg[i + j] = (1ll * g[u][i] * (f[v][j] + g[v][j]) + xg[i + j]) % RX;
		if (!is[u] && !is[v]) xf[i + j + 1] = (1ll * g[u][i] *
		  g[v][j] % RX * w + xf[i + j + 1]) % RX;
	  }
	sze[u] += sze[v];
	for (int i = 0; i <= (sze[u] >> 1); i++)
	  f[u][i] = xf[i], g[u][i] = xg[i];
  }
}

void jiejuediao(int st) {
  memset(cur, 0, sizeof(cur));
  tot1 = tot2 = tot = cnt = 0; dfs(st);
  if (tot <= cnt / 3)
    for (int S = 0; S < (1 << tot); S++) {
      bool can = 1; int prod = 1, sz = 0;
      for (int i = 1; i <= tot; i++)
        if ((S >> i - 1) & 1) is[a[i]]++, is[b[i]]++,
          can &= is[a[i]] == 1 && is[b[i]] == 1,
		    prod = 1ll * prod * c[i] % RX, sz++;
      if (can) {
      	dp(st);
      	for (int i = 0; i <= (sze[st] >> 1); i++)
      	  cur[i + sz] = (1ll * (f[st][i] + g[st][i])
			* prod + cur[i + sz]) % RX;
	  }
      for (int i = 1; i <= tot; i++)
        if ((S >> i - 1) & 1) is[a[i]]--, is[b[i]]--;
	}
  else {
  	if (tot1 < tot2) {
  	  for (int i = 1; i <= tot2; i++) std::swap(p1[i], p2[i]);
  	  std::swap(tot1, tot2);
    }
  	for (int i = 1; i <= tot2; i++) id[p2[i]] = i;
  	for (int S = 0; S < (1 << tot2); S++) h[0][S] = !S;
  	for (int i = 1; i <= tot1; i++) {
  	  int u = p1[i];
  	  for (int S = 0; S < (1 << tot2); S++) {
  	    h[i][S] = h[i - 1][S];
  	    for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
  	      if ((S >> id[v] - 1) & 1)
  	        h[i][S] = (1ll * val[e] * h[i - 1][S ^ (1 << id[v] - 1)]
			  + h[i][S]) % RX;
      }
	}
	for (int S = 0; S < (1 << tot2); S++) {
	  int cnt = 0;
	  for (int i = 1; i <= tot2; i++) if ((S >> i - 1) & 1) cnt++;
	  cur[cnt] = (cur[cnt] + h[tot1][S]) % RX;
	}
  }
  memset(xf, 0, sizeof(xf));
  for (int i = 0; i <= k; i++)
    for (int j = 0; i + j <= k; j++)
      xf[i + j] = (1ll * cur[i] * res[j] + xf[i + j]) % RX;
  for (int i = 0; i <= k; i++) res[i] = xf[i];
}

int main() {
  int x, y, z;
  read(n); read(k);
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % RX;
  for (int i = 1; i <= k; i++) read(x), read(y), read(z),
    add_edge(x, y + n, (z + RX - 1) % RX);
  res[0] = 1;
  for (int i = 1; i <= (n << 1); i++) if (!vis[i])
    jiejuediao(i);
  for (int i = 0; i <= k && i <= n; i++)
    ans = (1ll * fac[n - i] * res[i] + ans) % RX;
  return std::cout << ans << std::endl, 0;
}