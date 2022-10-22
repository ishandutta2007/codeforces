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
const ll N=2e5+7;
const ll INF=1e9+7;
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
ll n,m,num=0,tp=0,ts=0,ks=0;
ll pos[N],dfn[N],low[N],K[N],kx[N],kz[N],S[N],ck[N],vl[N];
bool vis[N];
struct edge{ll v,next,c;}e[N*2];
vector<ll>ID[N];
void add(ll x,ll y,ll c){e[num]=(edge){y,pos[x],c}; pos[x]=num++;}
void dfs(ll x){
	S[++tp]=x;
	dfn[x]=low[x]=++ts;
	repG(i,x){
		if(!dfn[e[i].v]){
			dfs(e[i].v);
			low[x]=min(low[x],low[e[i].v]);
		}
		else if(!K[e[i].v])low[x]=min(low[x],dfn[e[i].v]);
	}
	if(dfn[x]==low[x]){
		K[x]=++ks;
		ID[ks].clear();
		kz[ks]=1;
		while(S[tp]!=x){
			ID[ks].push_back(S[tp]);
			K[S[tp--]]=ks;
			kz[ks]++;
		}
		tp--;
		kx[ks]=x;
		ID[ks].push_back(x);
	}
}
ll dfs0(ll x,ll v,ll To){
	vis[x]=1;
	vl[x]=v;
	repG(i,x){
		if(K[e[i].v]!=K[To])continue;
		if(e[i].v==To){
			return vl[x]+e[i].c;
		}
		if(!vis[e[i].v]){
			ll t=dfs0(e[i].v,v+e[i].c,To);
			if(t>=0)return t;
		}
	}
	return -1;
}
ll dfs(ll x,ll v,ll md){
	vl[x]=v;
	vis[x]=1;
	repG(i,x){
		if(K[e[i].v]!=K[x])continue;
		if(vis[e[i].v]){
			if((v+e[i].c)%md!=vl[e[i].v]){
				ll p=((vl[e[i].v]-(v+e[i].c))%md+md)%md;
				return p;
			}
		}
		else{
			ll o=dfs(e[i].v,(v+e[i].c)%md,md);
			if(~o)return o;
		}
	}
	return -1;
} 
bool check(ll x,ll &GG){
	rep0(j,ID[K[x]].size())vis[ID[K[x]][j]]=0;
	ll q=dfs(x,0,GG);
	if(~q){
		GG=gcd(GG,q);
		return 0;
	}
	return 1;
}
int main(){
	memset(pos,-1,sizeof(pos));
	scanf("%lld%lld",&n,&m);
	rep(i,m){
		ll x,y,c; scanf("%lld%lld%lld",&x,&y,&c);
		add(x,y,c);
	}
	rep(i,n)if(!dfn[i])dfs(i);
	rep(i,n)vis[i]=vl[i]=0;
	rep(i,ks){
		if(kz[i]==1){
			ck[i]=0;
			continue;
		}
		ll GG=dfs0(kx[i],0,kx[i]);
		while(!check(kx[i],GG));
		ck[i]=GG;
	}
	ll q; scanf("%lld",&q);
	while(q--){
		ll v,s,t; scanf("%lld%lld%lld",&v,&s,&t);
		ll h=gcd(t,ck[K[v]]);
		if(!h)puts("NO");
		else if(s%h==0)puts("YES");
		else puts("NO");
	}
	return 0;
}