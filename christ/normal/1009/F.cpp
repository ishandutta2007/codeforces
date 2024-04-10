#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 1e6+3, MOD = 1e9+7;
vector<int> adj[MN];
int dfreq[MN], sz[MN], depth[MN], big[MN], st[MN], ed[MN], dat[MN], ans[MN], tt, mx;
int getsz (int cur, int p = -1) {
	dat[st[cur] = ++tt] = depth[cur];
	for (int i : adj[cur]) if (i != p) {
		depth[i] = depth[cur] + 1;
		int d = getsz(i,cur);
		sz[cur] += d;
		if (d > sz[big[cur]]) big[cur] = i;
	}
	ed[cur] = tt;
	return ++sz[cur];
}
struct cmp {
	bool operator() (const pii &a, const pii &b) const {
		return a.second > b.second || (a.second == b.second && a.first < b.first);
	}
};
set<pii,cmp> s;
void add (int d) {
	s.erase({d,dfreq[d]});
	s.insert({d,++dfreq[d]});
}
void sub (int d) {
	s.erase({d,dfreq[d]});
	s.insert({d,--dfreq[d]});
}
void dfs (int cur, int p, bool keep) {
	for (int i : adj[cur]) if (i != p && i != big[cur]) dfs(i,cur,0);
	if (big[cur]) dfs(big[cur],cur,1);
	for (int i : adj[cur]) if (i != p && i != big[cur]) 
		for (int j = st[i]; j <= ed[i]; j++) add(dat[j]);
	add(depth[cur]);
	ans[cur] = s.begin()->first;
	if (!keep) for (int i = st[cur]; i <= ed[cur]; i++) sub(dat[i]);
}
int main() {
	int n;
	scanf ("%d",&n);
	for (int i = 1; i < n; i++) {
		int a,b;
		scanf ("%d %d",&a,&b);
		adj[a].push_back(b); adj[b].push_back(a);
	}
	getsz(1);
	dfs(1,-1,1);
	for (int i = 1; i <= n; i++) printf ("%d\n",ans[i]-depth[i]);
    return 0;
}