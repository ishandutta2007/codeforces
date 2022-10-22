#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
#include<cstdio>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(ll i=(x);i<=(y);i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,(int)n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
#define pb push_back
const ll N=1e5+7;
const ll M=1e6+7;
const ll mod=1e9+7;
ll Pow(ll x,ll y){
	ll ans=1,now=x;
	while(y){
		if(y&1)ans=ans*now%mod;
		now=now*now%mod;
		y>>=1;
	}
	return ans;
}
ll n,m,num=0,tt=0,cnt=0,tms=0;
ll pos[N],dep[N],dfn[N],a[N],pr[M],dr[M*10],qf[M*10],vw[N*22],ar[N],kk[N],ed[N],fs[N],er[N],mn[N*3];
bool is[M*10];
struct edge{ll v,next;}e[N*2];
struct pir{ll x,d;}st[N*3][22];
void add(ll x,ll y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
void dfs(ll x,ll f,ll d){
	dfn[x]=ed[x]=++tt;
	dep[x]=d;
	st[++tms][0]=(pir){x,d};
	fs[x]=er[x]=tms;
	repG(i,x){
		if(e[i].v==f)continue;
		dfs(e[i].v,x,d+1);
		ed[x]=ed[e[i].v];
		er[x]=++tms;
		st[tms][0]=(pir){x,d};
	}
}
pir mer(pir x,pir y){return x.d<y.d? x:y;}
void gd(){
	for(ll i=1;(1<<i)<=tms;i++){
		rep(j,tms-(1<<i)+1)st[j][i]=mer(st[j][i-1],st[j+(1<<(i-1))][i-1]);
		REP(j,(1<<i)+1,(1<<(i+1)))mn[j]=i;
	}
}
ll qrs(ll L,ll R){
	ll le=mn[R-L+1];
	return mer(st[L][le],st[R-(1<<le)+1][le]).x;
}
ll lca(ll x,ll y){
	if(fs[x]<fs[y])return qrs(fs[x],er[y]);
	return qrs(fs[y],er[x]);
}
bool cmp(ll x,ll y){return dfn[x]<dfn[y];}
struct wt{ll x,y,id;};
vector<ll>v[N*22];
vector <wt>w[N*22];
stack<ll>su;
struct cal{
	ll n,num;
	ll pos[N],fr[N],vt[N*5],df[N],qt[N*3],pt[N*3];
	int dep[N], fa[N], sz[N], hv[N], top[N], Q[N], xl[N], ti;
	edge e[N*2];
	void add(ll x,ll y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
	void bfs (int s) {
		int he = 1, ta = 0; Q[++ ta] = s, top[1] = 1;
		while (he<=ta) {
			int x = Q[he ++]; xl[++ ti] = x, sz[x] = 1;
			fr[x] += fr[fa[x]], dep[x] = dep[fa[x]]+1;
			repG(i,x) {
				int v = e[i].v; if (!dep[v]) fa[v] = x, Q[++ ta] = v;
			}
		}
		for (int i = n; i > 1; -- i) {
			int x = xl[i], pa = fa[x]; sz[pa] += sz[x];
			if (!hv[pa] || sz[hv[pa]]<sz[x]) hv[pa] = x;
		}
		REP(i,2,n) {
			int x = xl[i], pa = fa[x]; top[x] = (x==hv[pa]? top[pa]: x);
		}
	}
	int lca2 (int u, int v) {
		while (top[u]!=top[v])
			dep[top[u]]>dep[top[v]]? (u = fa[top[u]]): (v = fa[top[v]]);
		return dep[u]<dep[v]? u: v;
	}
	ll dis(ll x,ll y){
		ll L=lca2(kk[x],kk[y]);
		return fr[kk[x]]+fr[kk[y]]-fr[L]-fr[fa[L]];
	}
	void build(ll x){
		n=0;
		rep0(i,v[x].size())vt[++n]=v[x][i];
		rep0(i,w[x].size())vt[++n]=w[x][i].x,vt[++n]=w[x][i].y;
		sort(vt+1,vt+n+1,cmp);
		ll qw=n;
		rep(i,qw-1)qt[i]=lca(vt[i],vt[i+1]);
		sort(qt+1,qt+n,cmp);
		ll s1=0,s2=0,aa=0;
		rep(i,n*2-1){
			if(s2==n-1||(s1!=n&&dfn[vt[s1+1]]<dfn[qt[s2+1]]))pt[++aa]=vt[++s1];
			else pt[++aa]=qt[++s2];
		}
		rep(i,n*2-1)vt[i]=pt[i];
		n=n*2-1;
		qw=num=0;
		rep(i,n)if(vt[i]!=vt[i-1])vt[++qw]=vt[i];
		n=qw;
		rep(i,n)df[i]=dfn[vt[i]];
		df[n+1]=mod;
		rep(i,n)pos[i]=-1;
		while(!su.empty())su.pop();
		rep(i,n){
			kk[vt[i]]=i;
			fr[i]=0;
			while(!su.empty()&&df[i]>ed[vt[su.top()]])su.pop();
			if(!su.empty())add(su.top(),i);
			su.push(i);
		}
		rep0(i,v[x].size())fr[kk[v[x][i]]]++;
		rep(i,n) dep[i] = fa[i] = sz[i] = hv[i] = top[i] = xl[i] = 0;
		ti = 0, bfs (1);
	}
}T;
void work(ll x){
	T.build(x);
	rep0(i,w[x].size()){
		ll d=Pow(qf[vw[x]],T.dis(w[x][i].x,w[x][i].y));
		ar[w[x][i].id]=(ar[w[x][i].id]*d)%mod;
	}
}
int main(){
	memset(pos,-1,sizeof(pos));
	scanf("%I64d",&n);
	rep(i,n-1){
		ll x,y; scanf("%I64d%I64d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(1,0,1);
	gd();
	rep(i,n)scanf("%I64d",&a[i]);
	REP(i,2,1e7){
		if(!is[i])pr[++cnt]=i,qf[i]=i;
		rep(j,cnt){
			if(i*pr[j]>(1e7))break;
			is[i*pr[j]]=1;
			qf[i*pr[j]]=pr[j];
			if(i%pr[j]==0)break;
		}
	}
	ll hh=0;
	rep(i,n){
		ll x=a[i];
		while(x>1){
			ll k=qf[x],nw=1;
			while(x%k==0){
				nw*=k;
				x/=k;
				if(!dr[nw])dr[nw]=++hh,vw[hh]=nw;
				v[dr[nw]].pb(i);
			}
		}
	}
	scanf("%I64d",&m);
	rep(i,m){
		ar[i]=1;
		ll u,v,x; scanf("%I64d%I64d%I64d",&u,&v,&x);
		while(x>1){
			ll k=qf[x],nw=1;
			while(x%k==0){
				nw*=k;
				x/=k;
				if(dr[nw])w[dr[nw]].pb((wt){u,v,i});
			}
		}
	}
	rep(i,hh)work(i);
	rep(i,m)printf("%I64d\n",ar[i]);
	return 0;
}