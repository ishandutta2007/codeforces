#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MN = 1e5+3, MOD = 1e9+7;
int cnt[MN], sz[MN], big[MN], c[MN], ans[MN], st[MN], ed[MN], wot[MN], bit[MN], dist;
vector<pii> queries[MN];
vector<int> adj[MN];
void inc (int i) {
	for(;i<MN;i+=i&-i)
		++bit[i];
}
void dec (int i) {
	for(;i<MN;i+=i&-i)
		--bit[i];
}
int query (int i) {
	int ret = 0;
	for(;i;i^=i&-i)
		ret += bit[i];
	return ret;
}
int dfs_sz (int cur, int p = -1) {
	st[cur] = ++dist;
	wot[dist] = c[cur];
	int mx = -1;
	for (int i : adj[cur]) if (i != p) {
		sz[cur] += dfs_sz(i,cur);
		if (sz[i] > mx) {
			mx = sz[i];
			big[cur] = i;
		}
	}
	ed[cur] = dist;
	return ++sz[cur];
}
void dfs (int cur, int p, bool keep) {
	for (int i : adj[cur]) if (i != p && i != big[cur]) dfs(i,cur,0);
	if (big[cur]) dfs(big[cur],cur,1);
	for (int i : adj[cur]) if (i != p && i != big[cur]) {
		for (int j = st[i]; j <= ed[i]; j++) {
			if (cnt[wot[j]]) dec(cnt[wot[j]]);
			inc(++cnt[wot[j]]);
		}
	}
	if (cnt[c[cur]]) dec(cnt[c[cur]]);
	inc(++cnt[c[cur]]);
	for (pii p : queries[cur]) {
		ans[p.second] = query(MN-1) - query(p.first-1);
	}
	if (!keep) {
		for (int i = st[cur]; i <= ed[cur]; i++) {
			dec(cnt[wot[i]]);
			if (--cnt[wot[i]]) inc(cnt[wot[i]]);
		}
	}
}
int _main() {
	int n,q;
	scanf ("%d %d",&n,&q);
	for (int i = 1; i <= n; i++) scanf ("%d",&c[i]);
	for (int i = 1; i < n; i++) {
		int a,b;
		scanf ("%d %d",&a,&b);
		adj[a].push_back(b); adj[b].push_back(a);
	}
	dfs_sz(1);
	for (int i = 1; i <= q; i++) {
		int a,b;
		scanf ("%d %d",&a,&b);
		queries[a].emplace_back(b,i);
	}
	dfs(1,-1,1);
	for (int i = 1; i <= q; i++) printf ("%d\n",ans[i]);
	return 0;
}
int main () {
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
		clock_t start = clock();
	#endif
	assert(!_main());
	#ifdef LOCAL
		printf ("Time elapsed: %.3f\n",(clock()-start)/double(CLOCKS_PER_SEC));
	#endif
	return 0;
}