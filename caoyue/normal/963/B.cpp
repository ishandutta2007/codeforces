#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=5e5+7;
const int INF=1e9+7;
set<int>s;
int pos[N],dg[N],v[N];
bool vis[N];
struct er{int x,d;}w[N];
int n,num=0,rt;
struct edge{int v,next;}e[N*2];
void add(int x,int y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
void dfs(int x,int f){
	w[x]=(er){x,w[f].d+1};
	repG(i,x)if(e[i].v!=f)dfs(e[i].v,x);
}
bool cmp(er x,er y){return x.d>y.d;}
int main(){
	memset(pos,-1,sizeof(pos));
	scanf("%d",&n);
	rep(i,n){
		int x; scanf("%d",&x);
		if(!x){rt=i; continue;}
		dg[i]++; dg[x]++;
		add(x,i); add(i,x);
	}
	dfs(1,0);
	sort(w+1,w+n+1,cmp);
	rep(i,n)v[w[i].x]=i;
	int q=0;
	rep(i,n)if(dg[i]%2==0)q++;
	if(q%2==0){puts("NO\n"); return 0;}
	puts("YES\n");
	rep(i,n)if(dg[i]%2==0)s.insert(v[i]);
	rep(o,n){
		set<int>::iterator u=s.begin();
		if(s.begin()==s.end())return 0;
		int k=w[*u].x;
		s.erase(u);
		printf("%d\n",k);
		vis[k]=1;
		repG(i,k){
			if(vis[e[i].v])continue;
			dg[e[i].v]--;
			if(dg[e[i].v]&1)s.erase(v[e[i].v]);
			else s.insert(v[e[i].v]);
		}
	}
	return 0;
}