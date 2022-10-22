#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<time.h>
#include<vector>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=1e3+7;
const int INF=1e9+7;
int n,num=0,cnt=-1;
int pos[N],sz[N],fa[N],t[N];
struct edge{int v,next;}e[N*2];
void add(int x,int y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
void dfs(int x,int f){
	sz[x]=1;
	fa[x]=f;
	repG(i,x){
		if(e[i].v==f)continue;
		dfs(e[i].v,x);
		sz[x]+=sz[e[i].v];
	}
}
int fd(int x){
	repG(i,x){
		if(e[i].v==fa[x])continue;
		if(sz[e[i].v]>n-sz[e[i].v])return fd(e[i].v);
	}
	return x;
}
struct pir{int x,s;}p[N];
bool cmp(pir a,pir b){return a.s<b.s;}
void dfs2(int x,int f,int v){
	t[x]=++cnt;
	printf("%d %d %d\n",x,f,(t[x]-t[f])*v);
	repG(i,x){
		if(e[i].v==f)continue;
		dfs2(e[i].v,x,v);
	}
}
int main(){
	scanf("%d",&n);
	memset(pos,-1,sizeof(pos));
	rep(i,n-1){
		int x,y; scanf("%d%d",&x,&y);
		if(n<=3)printf("%d %d %d\n",x,y,i);
		add(x,y); add(y,x);
	}
	if(n<=3)return 0;
	dfs(1,0);
	int r=fd(1),gg=0,sm=0,id;
	dfs(r,0);
	repG(i,r)p[++gg]=(pir){e[i].v,sz[e[i].v]};
	sort(p+1,p+gg+1,cmp);
	t[r]=0;
	cnt=0;
	rep(i,gg){
		sm+=p[i].s;
		dfs2(p[i].x,r,1);
		if(sm*3>=n){
			id=i;
			break;
		}
	}
	cnt=0;
	REP(i,id+1,gg)dfs2(p[i].x,r,sm+1);
	return 0;
}