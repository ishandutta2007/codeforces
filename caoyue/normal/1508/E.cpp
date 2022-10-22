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
const ll N=7e5+7;
const ll INF=1e15+7;
ll n,num=0,Mn,Md,ts=0,ans=0;
struct edge{ll v,next;}e[N*2];
struct pir{ll x,v;}ee[N],p1[N],p2[N];
vector<ll>esb[N];
ll a[N],pos[N],dfn[N],ed[N],fa[N],b[N],dep[N];
bool vis[N];
void add(ll x,ll y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
bool cmp(pir u,pir v){return  u.v<v.v;}

void dfs(ll x,ll f,ll d){
	dep[x]=d;
	fa[x]=f;
	dfn[x]=ed[x]=++ts;
	if(f){
		if(a[x]<a[f]){
			if(a[x]>Mn){
				Mn=a[x];
				Md=x;
			}
		}
	}
	ll cc=0;
	repG(i,x){
		if(e[i].v==f)continue;
		ee[++cc]=(pir){e[i].v,a[e[i].v]};
	}
	sort(ee+1,ee+cc+1,cmp);
	esb[x].clear();
	rep(j,cc)esb[x].push_back(ee[j].x);
	for(ll i=0;i<esb[x].size();i++){
		dfs(esb[x][i],x,d+1);
		ed[x]=++ts;
	}
}
int main(){
	scanf("%lld",&n);
	rep(i,n)scanf("%lld",&a[i]);
	memset(pos,-1,sizeof(pos));
	rep(i,n-1){
		ll x,y; scanf("%lld%lld",&x,&y);
		add(x,y); add(y,x);
	}
	Mn=-INF;
	dfs(1,0,1);
	rep(i,n){
		p1[i]=(pir){i,dfn[i]};
		p2[i]=(pir){i,ed[i]};
	}
	sort(p1+1,p1+n+1,cmp);
	sort(p2+1,p2+n+1,cmp);
	if(Mn==-INF){
		bool fl=0;
		rep(i,n){
			if(a[p1[i].x]!=i){
				fl=1;
				break;
			}
		}
		if(fl)puts("NO");
		else{
			puts("YES");
			puts("0");
			rep(i,n)printf("%lld ",a[i]);
			puts("");
		}
		return 0;
	}
	while(Md!=1){
		swap(a[Md],a[fa[Md]]);
		Md=fa[Md];
		ans++;
	}
	if(Mn==1){
		bool fl=0;
		rep(i,n){
			if(a[p1[i].x]!=i){
				fl=1;
				break;
			}
		}
		if(fl)puts("NO");
		else{
			puts("YES");
			printf("%lld\n",ans);
			rep(i,n)printf("%lld ",a[i]);
			puts("");
		}
		return 0;
	}
	Mn--;
	memset(vis,1,sizeof(vis));
	rep(j,Mn){
		b[p2[j].x]=j;
		vis[p2[j].x]=0;
	}
	ll cc=Mn;
	rep(j,n){
		if(!vis[p1[j].x])continue;
		b[p1[j].x]=++cc;
	}
	bool fl=1;
	rep(i,n)if(a[i]!=b[i]){fl=0; break;}
	if(fl){
		puts("YES");
		rep(i,Mn)ans+=(dep[p2[i].x]-1);
		printf("%lld\n",ans);
		rep(i,n)b[p1[i].x]=i;
		rep(i,n)printf("%lld ",b[i]);
		puts("");
	}
	else puts("NO");
	return 0;
}