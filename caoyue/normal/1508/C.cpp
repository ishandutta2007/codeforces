#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<time.h>
#include<bitset>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
namespace MST{
	const ll N=755;
	const ll INF=1e16+7;
	ll n;
	ll to[N][N],vl[N];
	bool vis[N];
	ll prim(){
		rep(i,n)vl[i]=(i==1)?0:INF;
		rep(i,n)vis[i]=0;
		ll ss=0;
		rep(i,n){
			ll mn=INF,id=0;
			rep(j,n){
				if(vis[j])continue;
				if(vl[j]<mn){
					mn=vl[j];
					id=j;
				}
			}
			ss+=mn;
			vis[id]=1;
			rep(k,n)vl[k]=min(vl[k],to[id][k]);
		}
		return ss;
	}
}
const ll N=5e5+7;
const ll M=755;
const ll INF=1e16+7;
ll n,m,Xr=0,sb=0;
ll U[N],V[N],W[N],f[N],dg[N],vl[N],er[N];
struct Edge{ll x,y;}E[N];
map<ll,ll>Es[N];
set<ll>S;
bool vis[N];
struct pir{
	ll x,v;
	friend bool operator < (pir a,pir b){return a.v>b.v;}
};
priority_queue<pir>Q;
ll ff(ll x){return (f[x]==x)?x:f[x]=ff(f[x]);}
bool to[M][M];
void work(ll l,ll r){
	set<ll>::iterator o=S.lower_bound(l);
	if(o==S.end())return;
	ll cc=0;
	while(o!=S.end()){
		if((*o)>r){
			rep(i,cc)S.erase(er[i]);
			return;
		}
		er[++cc]=(*o);
		if(vl[(*o)]>0){
			vl[(*o)]=0;
			Q.push((pir){(*o),0});
		}
		o++;
	}
	rep(i,cc)S.erase(er[i]);
}
void solve(){
	rep(i,n)Es[i].clear();
	rep(i,n)dg[i]=vis[i]=0;
	ll mn=INF,id,ss=0;
	rep(i,m){
		dg[U[i]]++;
		dg[V[i]]++;
		Es[U[i]][V[i]]=Es[V[i]][U[i]]=W[i];
	}
	rep(i,n){
		if(dg[i]<mn){
			mn=dg[i];
			id=i;
		}
	}
	while(!Q.empty())Q.pop(); 
	rep(i,n){
		if(i==id){
			vl[i]=0;
			Q.push((pir){i,0});
		}
		else vl[i]=INF;
	}
	S.clear();
	rep(i,n)if(i!=id)S.insert(i);
	while(!Q.empty()){
		pir t=Q.top();
		Q.pop();
		if(vis[t.x])continue;
		vis[t.x]=1;
		ss+=t.v;
		ll ls=0;
		for(map<ll,ll>::iterator o=Es[t.x].begin();o!=Es[t.x].end();o++){
			if(ls+1<(o->first))work(ls+1,(o->first)-1);
			ls=(o->first);
			if((o->second)<vl[o->first]){
				vl[o->first]=o->second;
				Q.push((pir){o->first,o->second});
			}
		}
		if(ls!=n)work(ls+1,n);
	}
	printf("%lld\n",ss);
	return;
}
int main(){
	scanf("%lld%lld",&n,&m);
	ll gg=n*(n-1)/2ll-m;
	rep(i,m)scanf("%lld%lld%lld",&U[i],&V[i],&W[i]);
	rep(i,m)Xr^=W[i];
	if(gg>=n){
		solve();
		return 0;
	}
	else{
		memset(to,1,sizeof(to));
		rep(i,m)to[U[i]][V[i]]=to[V[i]][U[i]]=0;
		rep(i,n)f[i]=i;
		bool fl=0;
		rep(i,n){
			rep(j,i-1){
				if(!to[i][j])continue;
				E[++sb]=(Edge){i,j};
				ll u=ff(i),v=ff(j);
				if(u==v){
					fl=1;
					break;
				}
				f[u]=v;
			}
			if(fl)break;
		}
		if(fl){
			solve();
			return 0;
		}
	}
	memset(MST::to,0,sizeof(MST::to));
	rep(i,m)MST::to[U[i]][V[i]]=MST::to[V[i]][U[i]]=W[i];
	MST::n=n;
	ll ans=INF;
	rep(i,sb){
		rep(j,sb)MST::to[E[j].x][E[j].y]=MST::to[E[j].y][E[j].x]=(i==j)?Xr:0;
		ans=min(ans,MST::prim());
	}
	printf("%lld\n",ans);
	return 0;
}