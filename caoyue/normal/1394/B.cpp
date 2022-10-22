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
const int N=2e5+7;
const int INF=1e9+7;
const ll mod=10000000000000061;
ll prand(){return (((ll)(rand()<<15|rand()))<<30)|(rand()<<15|rand());}
int n,m,k,ans=0;
ll s1=0,s2=0;
struct Edge{int v,c;};
vector<Edge>E[N];
ll c1[10][10],c2[10][10],g1[N],g2[N];
bool cmp(Edge a,Edge b){return a.c<b.c;}
void solve(int x,ll v1,ll v2){
	if(x==k+1){
		if(v1==s1&&v2==s2)ans++;
		return;
	}
	rep(j,x)solve(x+1,(v1+c1[x][j])%mod,(v2+c2[x][j])%mod);
}
int main(){
	srand(114514);
	scanf("%d%d%d",&n,&m,&k);
	rep(i,m){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		E[u].push_back((Edge){v,w});
	}
	rep(i,n){
		g1[i]=prand()%mod;
		g2[i]=prand()%mod;
		s1=(s1+g1[i])%mod;
		s2=(s2+g2[i])%mod;
	}
	rep(i,n)sort(E[i].begin(),E[i].end(),cmp);
	bool fl=1;
	rep(i,n){
		int t=E[i].size();
		if(!t){fl=0; break;}
		rep0(j,t){
			c1[t][j+1]=(c1[t][j+1]+g1[E[i][j].v])%mod;
			c2[t][j+1]=(c2[t][j+1]+g2[E[i][j].v])%mod;
		}
	}
	solve(1,0,0);
	printf("%d\n",ans);
	return 0;
}