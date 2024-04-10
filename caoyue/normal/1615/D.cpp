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
const int N=2e5+7;
const int INF=1e9+7;
int T,n,m,num=0,fl=0;
int pos[N],X[N],Y[N],V[N],vis[N];
struct edge{int v,c,next;}e[N*10];
void add(int x,int y,int c){e[num]=(edge){y,c,pos[x]}; pos[x]=num++;}
void dfs(int x,int v){
	vis[x]=v;
	repG(i,x){
		if(vis[e[i].v]<0)dfs(e[i].v,v^e[i].c);
		else if(vis[e[i].v]!=(v^e[i].c))fl=1;
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		rep(i,n){
			pos[i]=-1;
			vis[i]=-1;
		}
		num=fl=0;
		rep(i,n-1){
			scanf("%d%d%d",&X[i],&Y[i],&V[i]);
			if(V[i]>=0){
				int w=0;
				rep0(j,30)if((V[i]>>j)&1)w^=1;
				add(X[i],Y[i],w);
				add(Y[i],X[i],w);
			}
		}
		rep(i,m){
			int x,y,z; scanf("%d%d%d",&x,&y,&z);
			add(x,y,z); add(y,x,z);
		}
		rep(i,n)if(vis[i]<0)dfs(i,0);
		if(fl)puts("NO");
		else{
			puts("YES");
			rep(i,n-1){
				if(V[i]<0)V[i]=vis[X[i]]^vis[Y[i]];
				printf("%d %d %d\n",X[i],Y[i],V[i]);
			}
		}
	}
	return 0;
}