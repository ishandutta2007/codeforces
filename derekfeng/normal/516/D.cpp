#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mkp make_pair
#define fi first
#define se second
int n,q;
ll L;
vector<pii>g[100004];
ll d[100004],f[100004];
vector<pair<ll,int> >v;
void dfs(int x,int p){
	for(auto y:g[x])if(y.fi!=p)
		dfs(y.fi,x),d[x]=max(d[x],d[y.fi]+y.se);
}
void dfs1(int x,int p,ll D){
	f[x]=max(D,d[x]);
	v.push_back(mkp(f[x],x));
	ll D1=D,D2=0;
	for(auto y:g[x])if(y.fi!=p){
		ll t=d[y.fi]+y.se;
		if(D1<t)D2=D1,D1=t;
		else if(D2<t)D2=t;
	}
	for(auto y:g[x])if(y.fi!=p){
		ll t=d[y.fi]+y.se;
		dfs1(y.fi,x,(t!=D1?D1:D2)+y.se);
	}
}
int rt[100004],cnt[100004];
int Frt(int x){
	return rt[x]==x?x:rt[x]=Frt(rt[x]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		g[u].push_back(mkp(v,w)),g[v].push_back(mkp(u,w));
	}
	dfs(1,0);
	dfs1(1,0,0);
	sort(v.begin(),v.end());
	scanf("%d",&q);
	while(q--){
		scanf("%lld",&L);
		for(int i=1;i<=n;i++)rt[i]=i,cnt[i]=1;
		int r=n-1,ans=0;
		for(int l=n-1;~l;l--){
			while(v[r].fi-v[l].fi>L)cnt[Frt(v[r].se)]--,r--;
			int x=v[l].se;
			for(auto y:g[x])if(f[x]<=f[y.fi]){
				int X=Frt(x),Y=Frt(y.fi);
				if(X!=Y)rt[Y]=X,cnt[X]+=cnt[Y];
			}
			ans=max(ans,cnt[Frt(x)]);
		}
		printf("%d\n",ans);
	}
}