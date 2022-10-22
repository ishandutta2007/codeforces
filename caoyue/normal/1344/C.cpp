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
int n,m,tp=0,ts=0,ks=0,num=0,fl=0,ans=0;
int dfn[N],low[N],K[N],S[N],pos[N],p[N],mn1[N],mn2[N];
struct edge{int v,next;}e[N*2];
void add(int x,int y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
void tar(int x){
	dfn[x]=low[x]=++ts;
	S[++tp]=x;
	repG(i,x){
		if(!dfn[e[i].v]){
			tar(e[i].v);
			low[x]=min(low[x],low[e[i].v]);
		}
		else if(!K[e[i].v])low[x]=min(low[x],dfn[e[i].v]);
	}
	if(low[x]==dfn[x]){
		K[x]=++ks;
		if(S[tp]!=x)fl=1;
		while(S[tp]!=x)K[S[tp--]]=ks;
		tp--;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	memset(pos,-1,sizeof(pos));
	rep(i,m){
		int x,y; scanf("%d%d",&x,&y);
		add(x,y);
	}
	rep(i,n)if(!dfn[i])tar(i);
	if(fl){puts("-1"); return 0;}
	rep(i,n)p[K[i]]=i;
	rep(i,n){
		mn1[i]=p[i];
		repG(j,p[i])mn1[i]=min(mn1[i],mn1[K[e[j].v]]);
		mn2[i]=INF;
	}
	for(int i=n;i;i--){
		mn2[i]=min(mn2[i],p[i]);
		repG(j,p[i])mn2[K[e[j].v]]=min(mn2[i],mn2[K[e[j].v]]);
	}
	rep(i,n)if(min(mn1[K[i]],mn2[K[i]])==i)ans++;
	printf("%d\n",ans);
	rep(i,n)if(min(mn1[K[i]],mn2[K[i]])==i)putchar('A');else putchar('E');
	puts("");
	return 0;
}