#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;
const int MN = 53;
int deg[MN];
vector<int> adj[MN];
pll ans[MN];
void dfs (int cur, ll x, ll y, int dir, int p, int pw) {
	ans[cur] = {x,y};
	int d = -1;
	for (int i : adj[cur]) if (i != p) {
		++d; d%=4;
		if (d == (dir^1)) ++d, d%=4;
		if (d == 0) dfs(i,x+(1LL<<pw),y,d,cur,pw-1);
		if (d == 1) dfs(i,x-(1LL<<pw),y,d,cur,pw-1);
		if (d == 2) dfs(i,x,y+(1LL<<pw),d,cur,pw-1);
		if (d == 3) dfs(i,x,y-(1LL<<pw),d,cur,pw-1);
	}
}
int main () {
	int n,a,b;
	scanf ("%d",&n);
	for (int i = 1; i < n; i++) {
		scanf ("%d %d",&a,&b);
		++deg[a]; ++deg[b];
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) if (deg[i] > 4) return !printf ("NO\n");
	printf ("YES\n");
	dfs(1,0,0,-1,-1,55);
	for (int i = 1; i <= n; i++) printf ("%lld %lld\n",ans[i].first,ans[i].second);
    return 0;
}