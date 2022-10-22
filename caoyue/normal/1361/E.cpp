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
int prand(){return (rand()<<15)|rand();}
const int N=2e5+7;
const int INF=1e9+7;
int T,n,m,num=0,fl,ts,cnt;
int pos[N],dfn[N],is[N],p[N],dep[N],st[N],ok[N],fr[N],vd[N];
struct edge{int v,next;}e[N*2];
void add(int x,int y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
void dfs0(int x){
	dfn[x]=++ts;
	is[x]=1;
	repG(i,x){
		if(!dfn[e[i].v])dfs0(e[i].v);
		else if(!is[e[i].v])fl=0;
	}
	is[x]=0;
}
bool check(int r){
	fl=1;
	ts=0;
	rep(i,n)dfn[i]=is[i]=0;
	dfs0(r);
	return fl;
}
map<int,int>S[N];
void dfs1(int x,int d){
	dep[x]=d;
	repG(i,x){
		if(dep[e[i].v]<dep[x]&&dep[e[i].v]){
			if(S[x].count(dep[e[i].v]))S[x][dep[e[i].v]]++;
			else S[x][dep[e[i].v]]=1;
		}
		else dfs1(e[i].v,d+1);
	}
}
int mer(int x,int y){
	if(S[x].size()<S[y].size())swap(x,y);
	for(map<int,int>::iterator u=S[y].begin();u!=S[y].end();u++){
		int t1=(u->first),t2=(u->second);
		if(S[x].count(t1))S[x][t1]+=t2;
		else S[x][t1]=t2;
	}
	return x;
}
void dfs2(int x){
	vd[x]=x;
	st[dep[x]]=x;
	repG(i,x){
		if(dfn[e[i].v]>dfn[x]){
			dfs2(e[i].v);
			vd[x]=mer(vd[x],vd[e[i].v]);
		}
	}
	while(S[vd[x]].size()){
		map<int,int>::iterator o=S[vd[x]].end();
		o--;
		if((o->first)<dep[x])break;
		S[vd[x]].erase((o->first));
	}
	if(S[vd[x]].size()==1){
		map<int,int>::iterator o=S[vd[x]].begin();
		if((o->second)==1)fr[x]=st[(o->first)];
	}
}
void dfs3(int x){
	if(!ok[x]){
		if(fr[x]&&ok[fr[x]]){
			ok[x]=1;
			p[++cnt]=x;
		}
	}
	repG(i,x)if(dfn[e[i].v]>dfn[x])dfs3(e[i].v);
}
int main(){
	srand(233);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		num=cnt=0;
		rep(i,n)pos[i]=-1;
		rep(i,m){
			int x,y; scanf("%d%d",&x,&y);
			add(x,y);
		}
		int rt=-1;
		rep(i,100){
			int t=prand()%n+1;
			if(check(t)){
				rt=t;
				break;
			}
		}
		if(rt<0){
			puts("-1");
			continue;
		}
		p[++cnt]=rt;
		rep(i,n)dep[i]=0;
		rep(i,n)S[i].clear();
		check(rt);
		dfs1(rt,1);
		rep(i,n)fr[i]=0;
		dfs2(rt);
		rep(i,n)ok[i]=0;
		ok[rt]=1;
		dfs3(rt);
		if(cnt*5<n)puts("-1");
		else{
			sort(p+1,p+cnt+1);
			rep(i,cnt)printf("%d ",p[i]);
			puts("");
		}
	}
	return 0;
}