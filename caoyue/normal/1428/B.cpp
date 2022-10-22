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
const int N=3e5+7;
const int INF=1e9+7;
int pos[N],dfn[N],low[N],K[N],S[N],sz[N];
int num=0,n,tp=0,ts=0,ks=0;
char s[N];
struct edge{int v,next;}e[N*2];
void add(int x,int y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
void dfs(int x){
	dfn[x]=low[x]=++ts;
	S[++tp]=x;
	repG(i,x){
		if(!dfn[e[i].v]){
			dfs(e[i].v);
			low[x]=min(low[x],low[e[i].v]);
		}
		else if(!K[e[i].v])low[x]=min(low[x],dfn[e[i].v]);
	}
	if(dfn[x]==low[x]){
		sz[++ks]=1;
		K[x]=ks;
		while(S[tp]!=x){
			sz[ks]++;
			K[S[tp]]=ks;
			tp--;
		}
		tp--;
	}
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		num=tp=ts=ks=0;
		rep(i,n)dfn[i]=low[i]=K[i]=0;
		rep(i,n)pos[i]=-1;
		scanf("%s",s+1);
		rep(i,n){
			int v=i%n+1;
			if(s[i]!='>')add(v,i);
			if(s[i]!='<')add(i,v);
		}
		rep(i,n)if(!dfn[i])dfs(i);
		int ans=0;
		rep(i,n)if(sz[K[i]]!=1)ans++;
		printf("%d\n",ans);
	}
	return 0;
}