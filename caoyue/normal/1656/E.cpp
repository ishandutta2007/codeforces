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
const int N=1e5+7;
const int INF=1e9+7;
int T,n,num=0;
int pos[N];
ll dg[N];
struct edge{int v,next;}e[N*2];
void add(int x,int y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
set<int>Sx,Sy;
bool is[N];
void dfs(int x,int f,bool v){
	if(v)Sx.insert(dg[x]-1);
	else Sy.insert(dg[x]-1);
	is[x]=v;
	repG(i,x){
		if(e[i].v==f)continue;
		dfs(e[i].v,x,v^1);
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,n){
			pos[i]=-1;
			dg[i]=0;
		}
		Sx.clear();
		Sy.clear();
		num=0;
		rep(i,n-1){
			int x,y; scanf("%d%d",&x,&y);
			dg[x]++;
			dg[y]++;
			add(x,y); add(y,x);
		}
		dfs(1,0,0);
		rep(i,n){
			if(is[i])printf("%d ",dg[i]);
			else printf("%d ",-dg[i]);
		}
		puts("");
	}
	return 0;
}