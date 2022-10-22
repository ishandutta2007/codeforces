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
const ll N=20007;
const ll INF=1e9+7;
ll p[N],ln[N],lca[N],mx[N],gg[N],pos[N],w[N],sz[N],ys[N];
bool is[N];
ll cnt=0,tot=0,num=0,ans=0;
struct edge{ll v,next,c;}e[N*2];
void add(ll x,ll y,ll c){
	e[num]=(edge){y,pos[x],c}; pos[x]=num++;
	e[num]=(edge){x,pos[y],c}; pos[y]=num++;
}
struct pir{ll x,l;};
pir solve(ll l,ll r){
	ll o=++tot;
	if(l==r){
		w[l]=o;
		return (pir){o,ln[l]};
	}
	ll mi=INF,md;
	REP(i,l+1,r){
		if(lca[i]<mi){
			mi=lca[i];
			md=i;
		}
	}
	REP(i,l,r)ln[i]-=mi;
	REP(i,l,r)lca[i]-=mi;
	pir a=solve(l,md-1);
	pir b=solve(md,r);
	add(o,a.x,a.l);
	add(o,b.x,b.l);
	return (pir){o,mi};
}
void dfs1(ll x,ll f){
	repG(i,x){
		if(e[i].v==f)continue;
		dfs1(e[i].v,x);
		sz[x]+=sz[e[i].v];
	}
}
ll dfs2(ll x,ll f,ll s){
	repG(i,x){
		if(e[i].v==f)continue;
		if(sz[e[i].v]>s-sz[e[i].v])return dfs2(e[i].v,x,s);
	}
	return x;
}
void dfs3(ll x,ll f,ll d){
	ans+=ys[x]*d;
	repG(i,x){
		if(e[i].v==f)continue;
		dfs3(e[i].v,x,d+e[i].c);
	}
}
int main(){
	memset(pos,-1,sizeof(pos));
	REP(i,2,5000){
		if(!is[i])p[++cnt]=i,gg[i]=i;
		rep(j,cnt){
			if(i*p[j]>5000)break;
			is[i*p[j]]=1;
			gg[i*p[j]]=p[j];
			if(i%p[j]==0)break;
		}
	}
	rep(i,5000){
		ll nw=i,e;
		while(nw>1){
			ln[i]++;
			e=gg[nw];
			nw/=gg[nw];
		}
		ln[i]+=ln[i-1];
		if(i>1){
			lca[i]=0;
			REP(j,e,i-1){
				if(is[j])continue;
				ll o=i-1;
				while(o>=j){
					lca[i]+=o/j;
					o/=j;
				}
			}
		}
	}
	tot=1;
	pir ggg=solve(1,5000);
	add(1,ggg.x,ggg.l);
	w[0]=1;
	ll n; scanf("%I64d",&n);
	rep(i,n){
		ll x; scanf("%I64d",&x);
		sz[w[x]]++;
		ys[w[x]]++;
	}
	dfs1(1,0);
	dfs3(dfs2(1,0,sz[1]),0,0);
	printf("%I64d\n",ans);
	return 0;
}