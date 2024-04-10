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
#define lc ind<<1
#define rc ind<<1|1
const int MN = 1e5+4, MOD = 1e9+7, BASE = 31, SQRT = 500;
vector<int> adj[MN], comp[MN], srt[MN]; int cmp[MN], d[MN], ecc[MN], cc, down[MN], down2[MN], which[MN], up[MN]; vector<ll> ssa[MN];
map<int,double> ree[MN];
void dfs (int cur, int p = -1) {
	cmp[cur] = cc; comp[cc].push_back(cur);
	for (int i : adj[cur]) if (i != p) {
		dfs(i,cur);
		if (down[i] + 1 > down[cur]) {
			down2[cur] = down[cur];
			down[cur] = down[i] + 1;
			which[cur] = i;
		} else down2[cur] = max(down2[cur],down[i]+1);
	}
	d[cc] = max(d[cc],down[cur]+down2[cur]);
}
void dfs2 (int cur, int p = -1) {
	if (~p) up[cur] = max(up[p] + 1, (which[p]==cur?down2[p]:down[p]) + 1);
	ecc[cur] = max(down[cur],up[cur]);
	srt[cc].push_back(ecc[cur]+1);
	for (int i : adj[cur]) if (i != p) dfs2(i,cur);
}
int main () { 
	int n,m,q;
	scanf ("%d %d %d",&n,&m,&q);
	while (m--) {
		int a,b;
		scanf ("%d %d",&a,&b);
		adj[a].push_back(b); adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) if (!cmp[i]) {
		++cc;
		dfs(i);
		dfs2(i);
		sort(all(srt[cc])); ssa[cc].resize(srt[cc].size()+1);
		for (int j = (int)srt[cc].size()-1; ~j; j--) {
			ssa[cc][j] = ssa[cc][j+1] + srt[cc][j];
		}
		srt[cc].push_back(1e9);
	}
	for (int i = 1; i <= cc; i++) if (comp[i].size() > SQRT) {
		for (int j = i+1; j <= cc; j++) if (comp[j].size() > SQRT) {
			ll tot = (ll)comp[i].size() * (ll)comp[j].size(), ret = 0;
			if (comp[i].size() > comp[j].size()) swap(i,j);
			int mx = max(d[i],d[j]);
			for (int k : comp[i]) {
				int go = ecc[k];
				int ind = upper_bound(all(srt[j]),mx-go) - srt[j].begin();
				ret += ind * 1LL * mx;
				ret += ssa[j][ind] + go * 1LL * ((int)comp[j].size()-ind);
			}
			ree[i][j] = ree[j][i] = (double) ret / tot;
		}
	}
	while (q--) {
		int a,b;
		scanf ("%d %d",&a,&b); a = cmp[a]; b = cmp[b];
		if (a == b) {printf ("-1\n"); continue;}
		if (comp[a].size() > comp[b].size()) swap(a,b);
		if (ree[a].count(b)) {printf ("%.9f\n",ree[a][b]);continue;}
		ll tot = (ll)comp[a].size() * (ll)comp[b].size(), ret = 0;
		int mx = max(d[a],d[b]);
		for (int k : comp[a]) {
			int go = ecc[k];
			int ind = upper_bound(all(srt[b]),mx-go) - srt[b].begin();
			ret += ind * 1LL * mx;
			ret += ssa[b][ind] + go * 1LL * ((int)comp[b].size()-ind);
		}
		printf ("%.9f\n",(double) ret / tot);
	}
	return 0;
}