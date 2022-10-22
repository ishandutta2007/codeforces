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
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=6e5+7;
const int INF=1e9+7;
char sv[N];
int pos[N],dfn[N],low[N],K[N],vr[N],w[N],dp[N][27];
bool cg[N];
int n,m,num=0,cnt=0,kk=0;
struct edge{int v,next;}e[N];
struct Edge{int u,v;}E[N];
void add(int x,int y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
stack<int>s;
void tar(int x){
	dfn[x]=low[x]=++cnt;
	s.push(x);
	repG(i,x){
		if(dfn[e[i].v]){
			if(!K[e[i].v])low[x]=min(low[x],dfn[e[i].v]);
		}
		else{
			tar(e[i].v);
			low[x]=min(low[e[i].v],low[x]);
		}
	}
	if(low[x]==dfn[x]){
		K[x]=++kk;
		vr[kk]=x;
		if(s.top()==x)s.pop();
		else{
			while(s.top()!=x)K[s.top()]=kk,cg[s.top()]=1,s.pop();
			s.pop();
		}
	}
}
void dfs(int x){
	if(w[x]<INF)return;
	w[x]=N;
	repG(i,x){
		dfs(e[i].v);
		w[x]=min(w[x],w[e[i].v]-1);
	}
}
struct pir{int x,d;}p[N];
bool cmp(pir u,pir v){return u.d<v.d;}

int main(){
	memset(pos,-1,sizeof(pos));
	scanf("%d%d",&n,&m);
	scanf("%s",sv+1);
	rep(i,m){
		int x,y; scanf("%d%d",&x,&y);
		add(x,y);
		if(x==y){
			printf("-1\n");
			return 0;
		}
		E[i].u=x;
		E[i].v=y;
	}
	rep(i,n)if(!dfn[i])tar(i);
	memset(pos,-1,sizeof(pos));
	rep(i,m)if(K[E[i].u]!=K[E[i].v])add(K[E[i].u],K[E[i].v]);
	memset(w,120,sizeof(w));
	rep(i,kk)if(w[i]>INF)dfs(i);
	rep(i,n)if(cg[i]){printf("-1\n"); return 0;}
	rep(i,kk)p[i]=(pir){i,w[i]};
	sort(p+1,p+kk+1,cmp);
	int ans=-INF;
	for(int q=kk;q;q--){
		int i=p[q].x;
		rep0(k,26)dp[i][k]=0;
		repG(j,i)rep0(k,26)dp[i][k]=max(dp[e[j].v][k],dp[i][k]);
		dp[i][sv[vr[i]]-'a']++;
		rep0(k,26)ans=max(ans,dp[i][k]);
	}
	printf("%d\n",ans);
	return 0;
}