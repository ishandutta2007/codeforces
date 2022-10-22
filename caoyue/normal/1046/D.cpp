#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=1e5+7;
const int INF=1e9+7;
db f[N],zf[N];
int pos[N],fa[N];
struct edge{int v,next;}e[N*2];
int n,num=0,q;
void add(int x,int y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
void dfs(int x,int ff){
	fa[x]=ff;
	zf[x]=0;
	repG(i,x)if(e[i].v!=ff)dfs(e[i].v,x),zf[x]+=1-f[e[i].v];
}
int main(){
	memset(pos,-1,sizeof(pos));
	scanf("%d",&n);
	rep0(i,n)scanf("%lf",&f[i]);
	f[n]=1;
	rep(i,n-1){
		int x,y; scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(0,n);
	db ans=0;
	rep0(i,n)ans+=(1-f[i])*f[fa[i]];
	int q; scanf("%d",&q);
	while(q--){
		int a; db b; scanf("%d%lf",&a,&b);
		ans-=(1-f[a])*f[fa[a]];
		ans-=zf[a]*f[a];
		zf[fa[a]]-=1-f[a];
		f[a]=b;
		zf[fa[a]]+=1-f[a];
		ans+=(1-f[a])*f[fa[a]];
		ans+=zf[a]*f[a];
		printf("%.5lf\n",ans);
	}
	return 0;
}
/*
1
1
3
0 0.3
0 1
0 0
*/