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
int n,num=0;
int X1[N],Y1[N],X2[N],Y2[N],pos[N],fa[N][22],dep[N],fb[N],f[N];
int ff(int x){return (f[x]==x)?x:f[x]=ff(f[x]);}
struct edge{int v,next,c;}e[N*2];
void add(int x,int y,int c){e[num]=(edge){y,pos[x],c}; pos[x]=num++;}
void dfs(int x,int ft,int d){
	fa[x][0]=ft;
	dep[x]=d;
	for(int i=0;fa[fa[x][i]][i];i++)fa[x][i+1]=fa[fa[x][i]][i];
	repG(i,x){
		if(e[i].v!=ft){
			dfs(e[i].v,x,d+1);
			fb[e[i].v]=e[i].c;
		}
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=18;~i;i--)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;
	for(int i=18;~i;i--)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
void dfs2(int x,int ft){
	repG(i,x){
		if(e[i].v==ft)continue;
		dfs2(e[i].v,x);
		int p=ff(e[i].v),t=lca(e[i].v,x);
		if(dep[p]>dep[t]){
			printf("%d %d %d %d\n",p,fa[p][0],e[i].v,x);
			f[p]=fa[p][0];
		}
		else{
			int nw=x;
			for(int j=18;~j;j--)if(dep[ff(fa[nw][j])]>dep[ff(t)])nw=fa[nw][j];
			printf("%d %d %d %d\n",nw,fa[nw][0],e[i].v,x);
			f[nw]=fa[nw][0];
		}
	}
}
int main(){
	memset(pos,-1,sizeof(pos));
	scanf("%d",&n);
	rep(i,n-1)scanf("%d%d",&X1[i],&Y1[i]);
	rep(i,n-1)scanf("%d%d",&X2[i],&Y2[i]);
	rep(i,n-1){
		add(X1[i],Y1[i],i);
		add(Y1[i],X1[i],i);
	}
	rep(i,n)f[i]=i;
	dfs(1,0,1);
	memset(pos,-1,sizeof(pos));
	num=0;
	printf("%d\n",n-1); 
	rep(i,n-1){
		add(X2[i],Y2[i],i);
		add(Y2[i],X2[i],i);
	}
	dfs2(1,0);
	return 0;
}