#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+10;
ll n,q,maxx,mx[2][maxn],deg[maxn];
bool vis[maxn];
struct edge {
	ll v,w,next;
} e[maxn<<1];
ll eid,p[maxn];
void insert(ll u,ll v,ll w) {
	e[++eid]= {v,w,p[u]};
	p[u]=eid;
}
ll fa[maxn],w[maxn],d[maxn],dis[maxn];
vector<ll>a;
void dfs(ll u,ll f) {
	fa[u]=f;
	for(ll i=p[u]; i; i=e[i].next) {
		ll v=e[i].v;
		if(v==f)continue;
		dfs(v,u);
		w[v]=e[i].w;
	}
}
ll siz[maxn];
void dfs1(ll u,ll f) {
	siz[u]=1;
	for(ll i=p[u]; i; i=e[i].next) {
		ll v=e[i].v;
		if(v==f||vis[v])continue;
		dfs1(v,u);
		d[u]=max(d[u],d[v]+e[i].w);
		siz[u]+=siz[v];
	}
}
int main() {
	cin>>n>>q;
	for(ll i=1; i<n; ++i) {
		ll u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		++deg[u],++deg[v];
		insert(u,v,w);
		insert(v,u,w);
	}
	dfs(n,0);
	ll x=1,cnt=0;
	while(x)a.push_back(x),vis[x]=1,x=fa[x];
	cnt=a.size();
	for(ll i=0; i<cnt; ++i)
		dfs1(a[i],0),dis[i+1]=w[a[i]];
	ll sum=0;
	for(ll i=0; i<cnt; ++i) {
		mx[0][i]=max(sum+d[a[i]],mx[0][max(0ll,i-1)]);
		sum+=dis[i+1];
	}
	sum=0;
	for(ll i=cnt-1; i>=0; --i) {
		mx[1][i]=max(sum+d[a[i]],mx[1][i+1]);
		sum+=dis[i];
	}
	sum+=dis[0];
	for(ll i=0; i<cnt-1; ++i) {
		if(deg[a[i]]+(i==0)==2&&deg[a[i+1]]+(i==cnt-2)==2) {
			if(i==0)continue;
			maxx=max(maxx,mx[0][i-1]+mx[1][i+1]);
		} else maxx=max(maxx,mx[0][i]+mx[1][i+1]);
	}
	if(siz[1]>2||siz[n]>2) maxx=1e18;
	while(q--) {
		ll ss;
		scanf("%lld",&ss);
		printf("%lld\n",min(sum,maxx+ss));
	}
	return 0;
}