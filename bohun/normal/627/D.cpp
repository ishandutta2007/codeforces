#include <bits/stdc++.h>
#define ll long long
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

const int N = 2e5 + 10;

int n, k, a, b, val[N], dp[N], full[N], now, jest, sum[N], gdzie[N], good[N];
vector <int> g[N], op[N], pref[N], suf[N];

void dfs1(int v, int p) {
	good[v] = (val[v] >= now);
	if (ss(g[v]) == 1 && v != 1) {
		// lisc
		sum[v] = 0;
		full[v] = good[v];
		dp[v] = 0;
		return;
	}
	
	sum[v] = 0;
	dp[v] = 0;
	full[v] = 1;
	op[v].clear();
	pref[v].clear();
	suf[v].clear();
	
	for (auto it : g[v]) {
		if (it == p) continue;
		dfs1(it, v);
		
		if (!full[it]) full[v] = 0;
		if (full[it]) sum[v] += sum[it] + 1;
		
		if (!full[it]) {
			gdzie[it] = ss(op[v]);
			op[v].pb(dp[it]);
		}
	}
	
	pref[v].resize(ss(op[v]));
	suf[v].resize(ss(op[v]));
	
	rep(i, 0, ss(op[v]) - 1) {
		pref[v][i] = op[v][i];
		if (i) pref[v][i] = max(pref[v][i], pref[v][i - 1]);
	}
	
	per(i, 0, ss(op[v]) - 1) {
		suf[v][i] = op[v][i];
		if (i + 1 != ss(op[v]))
			suf[v][i] = max(suf[v][i], suf[v][i + 1]);
	}
	
	if (good[v])
		dp[v] = 1 + sum[v] + (!op[v].empty() ? pref[v].back() : 0);
	else {
		dp[v] = 0;
		full[v] = 0;
		sum[v] = 0;
	}
}

int daj(int a, vector <int> &x) {
	if (0 <= a && a < ss(x))
		return x[a];
	return 0;
}

void dfs2(int v, int p) {
	if (v != 1) {
		if (good[v]) {
			if (full[p] && p > 0)
				sum[v] += 1 + sum[p];
			full[v] &= full[p];
			dp[v] = sum[v] + 1;
			dp[v] += max((!pref[v].empty() ? pref[v].back() : 0), (!full[p] ? dp[p] : 0));
		}
	}
	if (good[v]) 
		jest |= (dp[v] >= k);
	
	for (auto it : g[v]) {
		if (it == p) continue;
		
		int F = full[v];
		int S = sum[v];
		int D = dp[v];
		
		if (good[v]) {
			full[v] = (full[p] & (ss(op[v]) == 0 || (ss(op[v]) == 1 && !full[it])));	
			sum[v] -= (full[it] == 1 ? sum[it] + 1 : 0);
			dp[v] = 0;
			if (!full[p])
				dp[v] = dp[p];
			if (gdzie[it] != -1) {
				dp[v] = max(dp[v], daj(gdzie[it] - 1, pref[v]));
				dp[v] = max(dp[v], daj(gdzie[it] + 1, suf[v]));
			}
			dp[v] += sum[v] + 1;
		}	
			
		
		dfs2(it, v);
		
		full[v] = F;
		sum[v] = S;
		dp[v] = D;
	}
}
 
int main() {
	full[0] = 1;
	scanf ("%d%d", &n, &k);
	rep(i, 1, n)
		scanf ("%d", val + i);
	rep(i, 1, n - 1) {
		scanf ("%d%d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	int l = 1, r = 1e6;
	while (l < r) {
		int m = (l + r + 1) / 2;
		now = m;
		jest = 0;
		rep(i, 1, n) gdzie[i] = -1;
		dfs1(1, 0);
		dfs2(1, 0);
		if (jest == 1)
			l = m;
		else
			r = m - 1;
	}
	printf ("%d\n", l);
	return 0;
}