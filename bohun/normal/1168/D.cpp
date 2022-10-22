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

const int N = 150005;

int n, q, a, par[N], lit[N], rep[N], up[N], cnt[N][27], dp[N][27], bad[N], h[N], H;
vector <int> g[N];
char c;

int id(char x) {
	if ('a' <= x && x <= 'z')
		return x - 'a';
	return 26;
}

void dfs(int v) {
	for (auto it : g[v]) 
		dfs(it);
	if (ss(g[v]) == 1 && v != 1) {
		rep[v] = rep[g[v][0]];
		up[rep[v]] = v;
	}
	else {
		rep[v] = v;
		up[v] = v;
	}
	if (ss(g[v]) == 0 && h[v] != H) {
		rep(i, 1, q)
			printf ("Fou\n");
		exit(0);
	}
}

int notok = 0;

void oblicz(int v) {
	if (bad[v]) notok--;
	bad[v] = false;
	for (auto it : g[v])
		if (bad[rep[it]]) {
			bad[v] = true;
			notok++;
			return;
		}
	if (ss(g[v]) == 0) return;
	if (ss(g[v]) == 1) {
		int u = rep[g[v][0]];
		rep(i, 0, 26)
			dp[v][i] = dp[u][i] + cnt[u][i];
		return;
	}
	int u1 = rep[g[v][0]], u2 = rep[g[v][1]], s = 0;
	rep(i, 0, 25) {
		dp[v][i] = max(dp[u1][i] + cnt[u1][i], dp[u2][i] + cnt[u2][i]);
		s += dp[v][i];
	}
	dp[v][26] = (H - h[v]) - s;
	if (dp[v][26] < 0) {
		bad[v] = true;
		notok++;
	}
}
	

void dfs2(int v) {
	for (auto it : g[v]) 
		dfs2(rep[it]);
	oblicz(v);
}

int main() {
	scanf ("%d%d", &n, &q);
	rep(i, 2, n) {
		scanf ("%d %c", par + i, &c);
		h[i] = h[par[i]] + 1;
		H = max(H, h[i]);
		g[par[i]].pb(i);
		lit[i] = id(c);
	}
	dfs(1);
	rep(i, 1, n)
		cnt[rep[i]][lit[i]]++;
	dfs2(1);
	while (q--) {
		scanf ("%d %c", &a, &c);
		cnt[rep[a]][lit[a]]--;
		lit[a] = id(c);
		cnt[rep[a]][lit[a]]++;
		a = par[up[rep[a]]];
		while (a) {
			oblicz(a);
			a = par[up[a]];
		}
		if (notok) {
			printf ("Fou\n");
			continue;
		}
		int res = 0;
		rep(i, 0, 25) 
			res += (i + 1) * (dp[1][i] + dp[1][26]);
		printf ("Shi %d\n", res);
	}
	
	
	return 0;
}