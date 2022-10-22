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
const int N=5e5+7;
const int INF=1e9+7;
int T,n,num,ts,tp,fl,ks;
int pos[N],dfn[N],low[N],K[N],S[N],p[N],Ans[N];
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
	if(dfn[x]==low[x]){
		if(S[tp]!=x)fl=1;
		while(S[tp]!=x)tp--;
		tp--;
		K[x]=++ks;
		p[ks]=x;
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,n){
			pos[i]=-1;
			K[i]=dfn[i]=low[i]=p[i]=0;
			Ans[i]=1;
		}
		num=ts=tp=fl=ks=0;
		rep(i,n){
			int kk; scanf("%d",&kk);
			rep(j,kk){
				int x; scanf("%d",&x);
				add(x,i);
			}
		}
		rep(i,n)if(!dfn[i])tar(i);
		if(fl){
			puts("-1");
			continue;
		}
		int ans=0;
		for(int i=n;i;i--){
			ans=max(ans,Ans[p[i]]);
			repG(j,p[i]){
				Ans[e[j].v]=max(Ans[e[j].v],Ans[p[i]]+(p[i]>e[j].v));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}