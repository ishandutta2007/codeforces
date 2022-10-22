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
const int N=3e5+7;
const int INF=1e9+7;
int T,n,m,num;
int c[N],Q[N*2],pos[N],f[N],w[N];
struct edge{int v,next;}e[N*2];
void add(int x,int y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
int ff(int x){return (f[x]==x)?x:f[x]=ff(f[x]);}
int main(){
	scanf("%d",&T);
	while(T--){
		num=0;
		scanf("%d%d",&n,&m);
		rep(i,n)c[i]=pos[i]=-1;
		rep(i,n)f[i]=i;
		rep(i,m){
			int u,v; scanf("%d%d",&u,&v);
			add(u,v); add(v,u);
			if(ff(u)!=ff(v))f[ff(u)]=ff(v);
		}
		bool fl=0;
		rep(i,n)if(ff(i)!=ff(1))fl=1;
		if(fl){
			puts("NO");
			continue;
		}
		c[1]=1;
		int hd=0,ti=0;
		repG(i,1){
			c[e[i].v]=0;
			Q[++ti]=e[i].v;
		}
		while(hd!=ti){
			int p=Q[++hd];
			repG(i,p){
				if(~c[e[i].v])continue;
				c[e[i].v]=1;
				repG(j,e[i].v){
					if(~c[e[j].v])continue;
					c[e[j].v]=0;
					Q[++ti]=e[j].v;
				}
			}
		}
		int cnt=0;
		rep(i,n)if(c[i]==1)w[++cnt]=i;
		puts("YES");
		printf("%d\n",cnt);
		rep(i,cnt)printf("%d ",w[i]);
		puts(""); 
	}
	return 0;
}