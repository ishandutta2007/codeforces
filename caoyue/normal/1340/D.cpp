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
struct edge{int v,next,c;}e[N*2];
int n,num=0,cnt=0;
int pos[N];
void add(int x,int y){e[num]=(edge){y,pos[x],0}; pos[x]=num++;}
map<int,int>mp[N];
struct pir{int x,t;}p[N*10];
void dfs(int x,int f,int c){
	int nw1=c-1,nw2=c+1;
	repG(i,x){
		if(e[i].v==f)continue;
		if(nw1>=1){
			e[i].c=e[i^1].c=nw1;
			mp[x][nw1]=e[i].v;
			mp[e[i].v][nw1]=x;
			dfs(e[i].v,x,nw1);
			nw1--;
		}
		else{
			e[i].c=e[i^1].c=nw2;
			mp[x][nw2]=e[i].v;
			mp[e[i].v][nw2]=x;
			dfs(e[i].v,x,nw2);
			nw2++;
		}
	}
}
void solve(int x,int v){
	p[++cnt]=(pir){x,v};
	map<int,int>::iterator tt=mp[x].upper_bound(v);
	if(tt==mp[x].end()){
		if(x>1){
			map<int,int>::iterator u=mp[x].begin();
			solve(x,(u->first)-1);
		}
		return;
	}
	solve(tt->second,v+1);
}
int main(){
	scanf("%d",&n);
	memset(pos,-1,sizeof(pos));
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,0,0);
	solve(1,0);
	printf("%d\n",cnt);
	rep(i,cnt)printf("%d %d\n",p[i].x,p[i].t);
	return 0;
}