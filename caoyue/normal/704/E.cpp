#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<bitset>
#include<time.h>
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
const db eps=1e-8;
int pos[N],dep[N],fa[N],son[N],sz[N],top[N];
int n,m,num=0;
db Ans=INF,nX;
struct edge{int v,next;}e[N*2];
void add(int x,int y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
void dfs1(int x,int f,int d){
	dep[x]=d;
	fa[x]=f;
	sz[x]=1;
	int mx=0;
	repG(i,x){
		if(e[i].v==f)continue;
		dfs1(e[i].v,x,d+1);
		if(sz[e[i].v]>mx){
			mx=sz[e[i].v];
			son[x]=e[i].v;
		}
		sz[x]+=sz[e[i].v];
	}
}
void dfs2(int x,int tp){
	top[x]=tp;
	if(sz[x]==1)return;
	dfs2(son[x],tp);
	repG(i,x)if(e[i].v!=son[x]&&e[i].v!=fa[x])dfs2(e[i].v,e[i].v);
}
int dis(int x,int y){
	int ans=dep[x]+dep[y];
	while(top[x]!=top[y]){
		if(dep[top[x]]>dep[top[y]])x=fa[top[x]];
		else y=fa[top[y]];
	}
	return ans-2*min(dep[x],dep[y]);
}
set<db>ts[N];
void gg(int x,db t){
	set<db>::iterator g=ts[x].lower_bound(t-eps);
	if(g==ts[x].end())ts[x].insert(t);
	else {
		if(abs(t-(*g))>eps)ts[x].insert(t);
		else Ans=min(Ans,t);
	}
}
db calc(db x,db k,db b){return k*x+b;}
db cro(db k1,db b1,db k2,db b2){return (b2-b1)/(k1-k2);}
struct le{
	db s,e,k,b;
	friend bool operator < (le x,le y){return calc(nX,x.k,x.b)<calc(nX,y.k,y.b);}
};
vector<le>z[N];
void Add(int x,db a,db b,db c,db d){z[x].push_back((le){a,b,c,d});}
void ins(int x,int y,int t,int v){
	db bt=t,et=t+(db)(dis(x,y))/v;
	while(top[x]!=top[y]){
		if(dep[top[x]]>dep[top[y]]){
			db ds=dep[x]-dep[fa[top[x]]];
			db ts=ds/v;
			Add(top[x],bt,bt+ts,-v,ds+bt*v);
			bt+=ts;
			x=fa[top[x]];
		}
		else{
			db ds=dep[y]-dep[fa[top[y]]];
			db ts=ds/v;
			Add(top[y],et-ts,et,v,ds-v*et);
			et-=ts;
			y=fa[top[y]];
		}
	}
	if(x==y)gg(x,bt);
	else{
		if(dep[x]<dep[y]){
			db ds=dep[x]-dep[fa[top[x]]];
			Add(top[x],bt,et,v,ds-v*bt);
		}
		else{
			db ds=dep[x]-dep[fa[top[x]]];
			Add(top[x],bt,et,-v,ds+v*bt);
		}
	}
}
struct pir{db x;bool v;int d;}pp[N*2];
bool cmp(pir a,pir b){
	if(a.x!=b.x)return a.x<b.x;
	return a.v>b.v;
}
set<le>G;
le sb(le dd){dd.b-=eps; return dd;}
void solve(int x){
	if(!z[x].size())return;
	int tt=0;
	rep0(i,z[x].size()){
		pp[tt++]=(pir){z[x][i].s,1,i};
		pp[tt++]=(pir){z[x][i].e,0,i};
	}
	sort(pp,pp+tt,cmp);
	G.clear();
	rep0(i,tt){
		if(pp[i].x+eps>Ans)return;
		if(pp[i].v){
			nX=pp[i].x;
			if(!G.size()){
				G.insert(z[x][pp[i].d]);
				continue;
			}
			set<le>::iterator o=G.lower_bound(sb(z[x][pp[i].d]));
			if(o!=G.end()){
				if(abs(calc(nX,(*o).k,(*o).b)-calc(nX,z[x][pp[i].d].k,z[x][pp[i].d].b))<eps){
					Ans=nX;
					return;
				}
				db q=cro((*o).k,(*o).b,z[x][pp[i].d].k,z[x][pp[i].d].b);
				if(q>nX&&q<=min((*o).e,z[x][pp[i].d].e)+eps)Ans=min(Ans,q);
			}
			if(o!=G.begin()){
				o--;
				if(abs(calc(nX,(*o).k,(*o).b)-calc(nX,z[x][pp[i].d].k,z[x][pp[i].d].b))<eps){
					Ans=nX;
					return;
				}
				db q=cro((*o).k,(*o).b,z[x][pp[i].d].k,z[x][pp[i].d].b);
				if(q>nX&&q<=min((*o).e,z[x][pp[i].d].e)+eps)Ans=min(Ans,q);
			}
			G.insert(z[x][pp[i].d]);
		}
		else{
			nX=pp[i].x;
			set<le>::iterator o=G.lower_bound(sb(z[x][pp[i].d]));
			if(o!=G.end()&&o!=G.begin()){
				set<le>::iterator o1=o,o2=o;
				o1++;
				o2--;
				if(o1!=G.end()){
					db q=cro((*o2).k,(*o2).b,(*o1).k,(*o1).b);
					if(q>nX&&q<=min((*o1).e,(*o2).e)+eps)Ans=min(Ans,q);
				}
			}
			G.erase(o);
		}
	}
}
int main(){
	memset(pos,-1,sizeof(pos));
	scanf("%d%d",&n,&m);
	rep(i,n-1){
		int x,y; scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs1(1,0,1);
	dfs2(1,1);
	rep(i,m){
		int t,v,x,y; scanf("%d%d%d%d",&t,&v,&x,&y);
		ins(x,y,t,v);
	}
	rep(i,n)for(set<db>::iterator o=ts[i].begin();o!=ts[i].end();o++)Add(top[i],(*o),(*o),0,dep[i]-dep[fa[top[i]]]);
	rep(i,n)if(top[i]==i)solve(i);
	if(Ans==INF)puts("-1");
	else printf("%.6lf\n",Ans);
	return 0;
}