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
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=5e5+7;
const int INF=1e9+7;
int T,n,m,num=0,cnt=0;
int dg[N],p[N],q[N],f[N],pos[N],tt[N],tp[N],vis[N],t[N],sz[N];
set<int>S[N];
int ff(int x){return (f[x]==x)?x:f[x]=ff(f[x]);}
struct edge{int v,next;}e[N*2];
void add(int x,int y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
vector<int>E[N],h[N];
void dfs(int x){
	vis[x]=1;
	tt[x]=-1;
	h[x].clear();
	int s0=-1;
	repG(i,x){
		if(vis[e[i].v])continue;
		dfs(e[i].v);
		if(tt[e[i].v]<0)h[x].push_back(e[i].v);
		if(s0<0)s0=e[i].v;
	}
	if(s0<0)return;
	if(!h[x].size()){
		if(tp[tt[s0]]==s0){
			tt[x]=tt[s0];
			sz[tt[s0]]++;
		}
		else{
			if(sz[tt[s0]]>2){
				sz[++cnt]=2;
				tt[s0]=tt[x]=cnt;
				tp[cnt]=x;
			}
			else{
				tt[x]=tt[s0];
				tp[tt[s0]]=s0;
				sz[tt[s0]]++;
			}
		}
	}
	else{
		sz[++cnt]=1;
		tp[cnt]=x;
		tt[x]=cnt;
		rep0(j,h[x].size()){
			tt[h[x][j]]=cnt;
			sz[cnt]++;
		}
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		rep(i,n)dg[i]=0;
		rep(i,n)S[i].clear();
		rep(i,m){
			int u,v; scanf("%d%d",&u,&v);
			dg[u]++; dg[v]++;
			S[u].insert(v);
			S[v].insert(u);
		}
		int nw=n;
		rep(i,n)if(dg[i]==n-1)p[i]=q[i]=nw--;
		rep(i,n)f[i]=i,pos[i]=-1,vis[i]=0;
		num=cnt=0;
		rep(i,n){
			if(dg[i]==n-1)continue;
			int to;
			rep(j,n){
				if(j==i)continue;
				if(S[i].count(j))continue;
				to=j;
				break;
			}
			if(ff(to)!=ff(i)){
				f[ff(to)]=ff(i);
				add(to,i);
				add(i,to);
			}
			t[i]=to;
		}
		rep(i,n){
			if(dg[i]==n-1)continue;
			if(vis[i])continue;
			dfs(i);
		}
		rep(i,cnt)E[i].clear();
		rep(i,n)if(dg[i]!=n-1)E[tt[i]].push_back(i);
		int bg=1;
		rep(i,cnt){
			p[tp[i]]=bg;
			q[tp[i]]=bg+E[i].size()-1;
			int ww=0;
			for(int j=0;j<E[i].size();j++){
				if(E[i][j]==tp[i])continue;
				q[E[i][j]]=bg+ww;
				ww++;
				p[E[i][j]]=bg+ww;
			}
			bg+=E[i].size();
		}
		rep(i,n)printf("%d ",p[i]);
		puts("");
		rep(i,n)printf("%d ",q[i]);
		puts("");
	}
	return 0;
}