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
const int N=1e5+7;
const int M=320;
const int INF=1e9+7;
int T,n,m,k,num,tot,gg;
struct edge{int v,next;}e[N*2];
int pos[N],dg[N],w[N],p[N],c[N];
void add(int x,int y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
struct pir{
	int x,v;
	friend bool operator < (pir a,pir b){return a.v>b.v;}
};
priority_queue<pir>Q;
bool vis[N],h[M*2][N];
bool judge(int x){
	if((ll)k*(k-1)/2>m)return 0;
	int oo=0,id=++gg;
	repG(i,x){
		if(!vis[e[i].v]){
			w[++oo]=e[i].v;
			c[e[i].v]=gg;
		}
	}
	rep(i,oo){
		if(p[w[i]]){
			rep(j,oo){
				if(!h[p[w[i]]][w[j]])return 0;
			}
		}
		else{
			int sm=0;
			repG(j,w[i])sm+=(c[e[j].v]==id);
			if(sm!=k-2)return 0;
		}
	}
	puts("2");
	rep(i,oo)printf("%d ",w[i]);
	printf("%d\n",x);
	return 1;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		rep(i,n)pos[i]=-1,vis[i]=0,p[i]=dg[i]=c[i]=0;
		num=tot=gg=0;
		int tt=sqrt(m);
		rep(i,m){
			int x,y; scanf("%d%d",&x,&y);
			add(x,y); add(y,x);
			dg[x]++; dg[y]++;
		}
		while(!Q.empty())Q.pop();
		rep(i,n)Q.push((pir){i,dg[i]});
		rep(i,n){
			if(dg[i]>tt){
				p[i]=++tot;
				memset(h[tot],0,sizeof(h[tot]));
				repG(j,i)h[p[i]][e[j].v]=1;
				h[p[i]][i]=1;
			}
		}
		int fl=0;
		while(!Q.empty()){
			pir t=Q.top();
			Q.pop();
			if(vis[t.x])continue;
			if(t.v>=k){
				fl=1;
				break;
			}
			if(t.v==k-1){
				if(judge(t.x)){
					fl=2;
					break;
				}
			}
			vis[t.x]=1;
			repG(i,t.x){
				if(vis[e[i].v])continue;
				dg[e[i].v]--;
				Q.push((pir){e[i].v,dg[e[i].v]});
			}
		}
		if(fl==1){
			int q=0;
			rep(i,n)if(!vis[i])q++;
			printf("1 %d\n",q);
			rep(i,n)if(!vis[i])printf("%d ",i);
			puts("");
		}
		if(!fl) puts("-1");
	}
	return 0;
}