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
const int N=2007;
const int INF=1e9+7;
struct edge{int v,next;}e[N*2];
int num=0,n,rt;
int c[N],sz[N],pos[N],v[N];
void add(int x,int y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
void dfs1(int x){
	sz[x]=1;
	repG(i,x){
		dfs1(e[i].v);
		sz[x]+=sz[e[i].v];
	}
}
void dfs3(int x,int u,int t){
	v[x]+=u;
	if(v[x]>=t)v[x]++;
	repG(i,x)dfs3(e[i].v,u,t);
}
void dfs2(int x){
	v[x]=c[x]+1;
	int ns=0;
	repG(i,x)dfs2(e[i].v);
	repG(i,x){
		dfs3(e[i].v,ns,c[x]+1);
		ns+=sz[e[i].v];
	}
}
int main(){
	scanf("%d",&n);
	memset(pos,-1,sizeof(pos));
	rep(i,n){
		int p; scanf("%d%d",&p,&c[i]);
		if(p)add(p,i);
		else rt=i;
	}
	dfs1(rt);
	rep(i,n)if(c[i]+1>sz[i]){puts("NO"); return 0;}
	dfs2(rt);
	puts("YES");
	rep(i,n)printf("%d ",v[i]);
	puts("");
	return 0;
}