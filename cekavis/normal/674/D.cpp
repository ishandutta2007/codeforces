#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 100005;
const ll inf = 5e18;
int n, q, a[N], d[N];
ll b[N], c[N], e[N], f[N], mx[N], mn[N];
bool vis[N];
multiset<ll> smx, smn, g[N];
ll min(const multiset<ll> &s){ return s.empty()?inf:*s.begin();}
ll max(const multiset<ll> &s){ return s.empty()?0:*--s.end();}
void change(int x, ll y){
	g[a[x]].erase(g[a[x]].find(c[x])), g[a[x]].insert(c[x]+=y);
}
void del(int x){
	if(vis[x]) return;
	vis[x]=1, smx.erase(smx.find(mx[x]+f[x])), smn.erase(smn.find(mn[x]+f[x]));
}
void ins(int x){
	if(!vis[x]) return;
	vis[x]=0, smx.insert((mx[x]=max(g[x]))+f[x]), smn.insert((mn[x]=min(g[x]))+f[x]);
}
int main() {
	scanf("%d%d", &n, &q);
	for(int i=1; i<=n; ++i) scanf("%lld", b+i);
	for(int i=1; i<=n; ++i) scanf("%d", a+i), ++d[a[i]], d[i]+=2;
	for(int i=1; i<=n; ++i) e[i]=b[i]/d[i], c[a[i]]+=e[i], c[i]+=b[i]%d[i]+e[i];
	for(int i=1; i<=n; ++i) c[i]+=e[a[i]];
	for(int i=1; i<=n; ++i) g[a[i]].insert(c[i]);
	for(int i=1; i<=n; ++i) smx.insert(mx[i]=max(g[i])), smn.insert(mn[i]=min(g[i]));
	while(q--){
		int opt, u, x, y;
		scanf("%d", &opt);
		if(opt==3) printf("%lld %lld\n", min(smn), max(smx));
		else if(opt==2) scanf("%d", &u), printf("%lld\n", c[u]+f[a[u]]);
		else if(opt==1){
			scanf("%d%d", &u, &y), x=a[u];
			if(x==y) continue;
			del(x), del(y), del(a[x]), del(a[y]), del(a[a[x]]), del(a[a[y]]);

			change(x, b[x]%(d[x]-1)-b[x]%d[x] + b[x]/(d[x]-1)-e[x] - e[u]);
			change(y, b[y]%(d[y]+1)-b[y]%d[y] + b[y]/(d[y]+1)-e[y] + e[u]);
			change(a[x], b[x]/(d[x]-1)-e[x]), change(a[y], b[y]/(d[y]+1)-e[y]);
			g[x].erase(g[x].find(c[u])), g[y].insert(c[u]+=f[x]-f[y]+e[y]-e[x]);
			--d[x], ++d[y];
			f[x]+=b[x]/d[x]-e[x], e[x]=b[x]/d[x];
			f[y]+=b[y]/d[y]-e[y], e[y]=b[y]/d[y];

			ins(x), ins(y), ins(a[x]), ins(a[y]), ins(a[a[x]]), ins(a[a[y]]);
			a[u]=y;
		}
	}
	return 0;
}