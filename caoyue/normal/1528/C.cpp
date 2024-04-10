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
#include<bitset>
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
namespace Gra{
	struct edge{int v,next;}e[N*2];
	int n,num,ts;
	int pos[N],dfn[N],ed[N],fd[N];
	void add(int x,int y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
	void pre(int nn){
		n=nn;
		rep(i,n)pos[i]=-1;
		num=ts=0;
	}
	void dfs(int x,int f){
		dfn[x]=ed[x]=++ts;
		fd[ts]=x;
		repG(i,x){
			if(e[i].v==f)continue;
			dfs(e[i].v,x);
			ed[x]=ed[e[i].v];
		}
	}
	void work(){
		dfs(1,0);
	}
}
int T,n,num,size,ans;
struct edge{int v,next;}e[N*2];
int pos[N];
void add(int x,int y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
struct pir{int x,v;};
vector<pir>p[N];
set<int>S;
void dfs(int x,int f){
	p[x].clear();
	int q=Gra::dfn[x],l=Gra::dfn[x],r=Gra::ed[x];
	set<int>::iterator lo=S.lower_bound(l),ro=S.upper_bound(r);
	bool fl=(lo==S.end())|((*lo)==(*ro));
	if(fl){
		p[x].push_back((pir){q,1});
		S.insert(q);
		size++;
		set<int>::iterator o=S.lower_bound(q);
		if(o!=S.begin()){
			o--;
			if(Gra::ed[Gra::fd[(*o)]]>=q){
				int t=(*o);
				p[x].push_back((pir){t,0});
				S.erase(t);
				size--;
			}
		}
	}
	ans=max(ans,size);
	repG(i,x)if(e[i].v!=f)dfs(e[i].v,x);
	if(p[x].size()){
		for(int j=p[x].size()-1;~j;j--){
			if(p[x][j].v){
				S.erase(p[x][j].x);
				size--;
			}
			else{
				S.insert(p[x][j].x);
				size++;
			}
		}
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,n)pos[i]=-1;
		num=size=ans=0;
		Gra::pre(n);
		rep(i,n-1){
			int x; scanf("%d",&x);
			add(x,i+1);
		}
		rep(i,n-1){
			int x; scanf("%d",&x);
			Gra::add(x,i+1);
		}
		Gra::work();
		S.clear();
		dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}