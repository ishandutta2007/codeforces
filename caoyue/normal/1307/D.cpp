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
int n,m,k,num=0;
int a[N],pos[N],dis1[N],dis2[N],Qu[N];
struct edge{int v,next;}e[N*2];
void add(int x,int y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
void dfs(int S,int *d){
	int hd=0,ti=1;
	Qu[1]=S;
	rep(i,n)d[i]=INF;
	d[S]=0;
	while(hd!=ti){
		int t=Qu[++hd];
		repG(i,t){
			if(d[e[i].v]>d[t]+1){
				d[e[i].v]=d[t]+1;
				Qu[++ti]=e[i].v;
			}
		}
	}
}
struct pir{int u,v;}p[N];
bool cmp(pir x,pir y){return x.u>y.u;}

int main(){
	memset(pos,-1,sizeof(pos));
	scanf("%d%d%d",&n,&m,&k);
	rep(i,k)scanf("%d",&a[i]);
	rep(i,m){
		int x,y; scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(1,dis1);
	dfs(n,dis2);
	rep(i,k)p[i]=(pir){dis1[a[i]],dis2[a[i]]};
	sort(p+1,p+k+1,cmp);
	int nw=0,ans=0;
	rep(i,k){
		if(i>1)ans=max(ans,min(dis2[1],p[i].u+min(nw,p[i].v)+1));
		nw=max(nw,p[i].v);
	}
	printf("%d\n",ans);
	return 0;
}