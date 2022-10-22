#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using pib = pair<int,bool>;
using ll = long long;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#ifdef fread_unlocked
#define fread fread_unlocked
#define fwrite fwrite_unlocked
#endif
#define mp make_pair
#define lc ind<<1
#define rc ind<<1|1
const int MN = 1e5+5, MK = 6e4 + 5, MOD = 1e9+7, BASE = 31, MASK = (1 << 10) - 1;
ll a[MN], b[MN],need[MN];
vector<pii> adj[MN];
ll dfs (int cur, int p = -1, int dist = 1) {
	for (pii pp : adj[cur]) if (pp.first != p) {
		ll ree = dfs(pp.first,cur,pp.second);
		if ((ld)a[cur] + ree > 1e18) {printf ("NO\n"); exit(0);}
		a[cur] += ree;
	}
	if (a[cur] >= b[cur]) {
		if ((ld)(a[cur]-b[cur]) * dist > 1e18) {printf ("NO\n"); exit(0);}
		return (a[cur] - b[cur]) * dist;
	}
	else return a[cur] - b[cur];
}
int main () {
	int n;
	scanf ("%d",&n);
	for (int i = 1; i <= n; i++) scanf ("%lld",&b[i]);
	for (int i = 1; i <= n; i++) scanf ("%lld",&a[i]);
	for (int i = 2; i <= n; i++) {
		int p,w;
		scanf ("%d %d",&p,&w);
		adj[p].emplace_back(i,w);
	}
	printf(dfs(1) > 0 ? "NO\n" : "YES\n");
	return 0;
}