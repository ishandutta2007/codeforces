#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=5e5+7;
const ll INF=1e17+7;
ll h[N],t[N],f[N][2],pos[N],w[N];
ll n,num=0;
struct edge{ll v,next;}e[N*2];
struct pir{ll a,b;}p[N];
bool cmp(pir x,pir y){return (x.b-x.a)<(y.b-y.a);}
void add(ll x,ll y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
void dfs(ll x,ll fa){
	ll cnt=0,s1=0,s0=0,hh=0,ss=0;
	repG(i,x){
		if(e[i].v==fa)continue;
		hh=1;
		dfs(e[i].v,x);
		if(h[e[i].v]>h[x])s1++,ss+=f[e[i].v][1];
		if(h[e[i].v]<h[x])s0++,ss+=f[e[i].v][0];
	}
	if(!hh){
		f[x][0]=f[x][1]=t[x];
		return;
	}
	w[0]=0;
	repG(i,x){
		if(e[i].v!=fa&&h[e[i].v]==h[x]){
			w[0]+=f[e[i].v][0];
			p[++cnt]=(pir){f[e[i].v][0],f[e[i].v][1]};
		}
	}
	sort(p+1,p+cnt+1,cmp);
	rep(i,cnt)w[i]=w[i-1]+p[i].b-p[i].a;
	f[x][0]=f[x][1]=INF;
	rep0(i,cnt+1){
		f[x][0]=min(f[x][0],w[i]+max(cnt-i+s0,i+s1+(x!=1))*t[x]+ss);
		f[x][1]=min(f[x][1],w[i]+max(cnt-i+s0+(x!=1),i+s1)*t[x]+ss);
	}
}
int main(){
	scanf("%I64d",&n);
	memset(pos,-1,sizeof(pos));
	rep(i,n)scanf("%I64d",&t[i]);
	rep(i,n)scanf("%I64d",&h[i]);
	rep(i,n-1){
		ll x,y; scanf("%I64d%I64d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(1,0);
	printf("%I64d\n",f[1][0]);
	return 0;
}