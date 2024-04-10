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
#include<bitset>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=2e6+7;
const int INF=1e9+7;
void read(int &x){
	char c=getchar(); x=0;
	while(c<'0'||c>'9')c=getchar();
	while(c<='9'&&c>='0')x=x*10+c-'0',c=getchar();
}
int n,m,num,ts,ks,tp;
struct edge{int v,next;}e[N*2];
int pos[N],dfn[N],low[N],K[N],S[N];
void add(int x,int y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
void tar(int x){
	S[++tp]=x;
	dfn[x]=low[x]=++ts;
	repG(i,x){
		if(!dfn[e[i].v]){
			tar(e[i].v);
			low[x]=min(low[x],low[e[i].v]);
		}
		else if(!K[e[i].v])low[x]=min(low[x],dfn[e[i].v]);
	}
	if(dfn[x]==low[x]){
		K[x]=++ks;
		while(S[tp]!=x)K[S[tp--]]=ks;
		tp--;
	}
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n,m; read(n); read(m);
		rep(i,n*2)pos[i]=-1,K[i]=dfn[i]=0;
		num=ts=ks=tp=0;
		rep(i,m){
			int x,y; read(x); read(y);
			if(x==y)continue;
			add(x,y);
			add(y+n,x+n);
		}
		rep(i,2*n)if(!dfn[i])tar(i);
		bool fl1=0,fl2=0;
		rep(i,n)if(K[i]!=K[1])fl1=1;
		rep(i,n)if(K[i+n]!=K[1+n])fl2=1;
		if(fl1&fl2){
			puts("Yes");
			int mn=K[1],s=0;
			rep(i,n)mn=min(mn,K[i]);
			rep(i,n)s+=(K[i]==mn);
			printf("%d %d\n",s,n-s);
			rep(i,n)if(K[i]==mn)printf("%d ",i);
			puts("");
			rep(i,n)if(K[i]!=mn)printf("%d ",i);
			puts("");
		}
		else puts("No");
	}
	return 0;
}