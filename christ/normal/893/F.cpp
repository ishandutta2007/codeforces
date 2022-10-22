#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 1e5+3;
int v[MN], depth[MN], st[MN], ed[MN], which[MN], tt;
vector<pii> tree[MN << 1];
vector<int> psa[MN << 1];
vector<int> adj[MN];
int lr[MN<<1], rr[MN<<1];
void dfs(int cur, int p = -1) {
	which[st[cur] = ++tt] = cur;
	for (int i : adj[cur]) if (i^p){
		depth[i] = depth[cur] + 1;
		dfs(i,cur);
	}
	ed[cur] = tt;
}
int main () {
	int n, r;
	scanf ("%d %d",&n,&r);
	for (int i = 1; i <= n; i++) scanf ("%d",&v[i]);
	for (int i = 1; i < n; i++) {
		int a,b;
		scanf ("%d %d",&a,&b);
		adj[a].push_back(b); adj[b].push_back(a);
	}
	depth[r] = 1;
	dfs(r);
	for (int i = n; i < (n << 1); i++) tree[i] = {{depth[which[i-n+1]],v[which[i-n+1]]}}, lr[i]=rr[i]=i-n+1, psa[i] = {tree[i][0].second};
	for (int i = n-1; i; i--) {
		lr[i] = min(lr[i<<1],lr[i<<1|1]); rr[i]=max(rr[i<<1],rr[i<<1|1]);
		tree[i].resize(tree[i<<1].size()+tree[i<<1|1].size());
		merge(tree[i<<1].begin(),tree[i<<1].end(),tree[i<<1|1].begin(),tree[i<<1|1].end(),tree[i].begin());
		psa[i].resize(tree[i].size());
		psa[i][0] = tree[i][0].second;
		for (int j = 1; j < tree[i].size(); j++) psa[i][j] = min(psa[i][j-1],tree[i][j].second);
	}
	int q;int last = 0;
	scanf ("%d",&q);
	while (q--) {
		int a,b;
		scanf ("%d %d",&a,&b);
		a = (a+last)%n+1; b = (b+last)%n;
		int l = st[a], r = ed[a];
		int high = depth[a] + b; int ret = INT_MAX;
		for (l += n-1, r += n; l < r; l>>=1, r>>=1) {
			if (l&1) {
				int ind = upper_bound(all(tree[l]),pii{high,INT_MAX})-tree[l].begin()-1;
				if (ind >= 0) ret = min(ret,psa[l][ind]);
				++l;
			}
			if (r&1) {
				--r;
				int ind = upper_bound(all(tree[r]),pii{high,INT_MAX})-tree[r].begin()-1;
				if (ind >= 0) ret = min(ret,psa[r][ind]);
			}
		}
		last = ret;
		printf ("%d\n",ret);
	}
	return 0;
}