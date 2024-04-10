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
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=1e5+7;
const int INF=1e9+7;
int T,num=0,n,a,b,d1,d2;
int pos[N],fa[N][22],dep[N];
struct edge{int v,next;}e[N*2];
void add(int x,int y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
void dfs(int x,int f,int d){
	dep[x]=d;
	fa[x][0]=f;
	for(int i=0;fa[fa[x][i]][i];i++)fa[x][i+1]=fa[fa[x][i]][i];
	repG(i,x)if(e[i].v!=f)dfs(e[i].v,x,d+1);
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=20;~i;i--)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;
	for(int i=20;~i;i--)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int dis(int x,int y){return dep[x]+dep[y]-2*dep[lca(x,y)];}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%d",&n,&a,&b,&d1,&d2);
		num=0;
		rep(i,n)pos[i]=-1;
		rep(i,n-1){
			int x,y; scanf("%d%d",&x,&y);
			add(x,y); add(y,x);
		}
		rep(i,n)rep0(j,21)fa[i][j]=0;
		dfs(1,0,1);
		int v1=1,v2=2;
		REP(i,3,n){
			int w1=dis(i,v1),w2=dis(i,v2),g1=v1,g2=v2;
			if(w1>=w2&&w1>=dis(v1,v2))v1=g1,v2=i;
			if(w2>=w1&&w2>=dis(v1,v2))v2=g2,v1=i;
		}
		d1=min(d1,dis(v1,v2));
		d2=min(d2,dis(v1,v2));
		if(dis(a,b)<=d1)puts("Alice");
		else if(d1+d1>=d2)puts("Alice");
		else puts("Bob");
	}
	return 0;
}