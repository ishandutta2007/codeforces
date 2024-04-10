#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int,int> Pii;
#define reg register
#define mp make_pair
#define pb push_back
#define Mod1(x) ((x>=P)&&(x-=P))
#define Mod2(x) ((x<0)&&(x+=P))
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
template <class T> inline void cmin(T &a,T b){ ((a>b)&&(a=b)); }
template <class T> inline void cmax(T &a,T b){ ((a<b)&&(a=b)); }

char IO;
template <class T=int> T rd(){
	T s=0; int f=0;
	while(!isdigit(IO=getchar())) f|=IO=='-';
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=2e5+10,INF=1e9+10;

int n,k;
vector <int> G[N];
int col[N];
int ma,id,fa[N];
void dfs(int u,int f,int d){
	fa[u]=f;
	if(d>ma) ma=d,id=u;
	for(int v:G[u]) if(v!=f) dfs(v,u,d+1);
}

int A[N],C,vis[N],dp[N][2];
void dfs2(int u,int c,int d,int delta){
	col[u]=c,vis[u]=1;
	for(int v:G[u]) if(!vis[v]) {
		dfs2(v,(c+delta+k)%k,d+1,delta);
		int t=dp[v][0]+1;
		rep(j,0,1) if(t>dp[u][j]) swap(dp[u][j],t);
	}
	if(dp[u][1]>0 && dp[u][0]+dp[u][1]>=k-1) puts("No"),exit(0);
}

namespace pt1{
	void dfs(int u,int f){
		for(int v:G[u]) if(v!=f) col[v]=col[u]^1,dfs(v,u);
	}
	void Solve() {
		dfs(1,0);
		puts("Yes");
		rep(i,1,n) printf("%d ",col[i]+1);
	}
}

int main(){
	n=rd(),k=rd();
	rep(i,2,n){
		int u=rd(),v=rd();
		G[u].pb(v),G[v].pb(u);
	}
	if(k==2) return pt1::Solve(),0;
	ma=-1,dfs(1,0,0),ma=-1,dfs(id,0,0);
	for(int u=id;u;u=fa[u]) A[++C]=u,vis[u]=1;
	rep(i,1,C) {
		dfs2(A[i],i%k,max(C-i,i-1),C-i>=i-1?-1:1);
		if(dp[A[i]][0]>0 && dp[A[i]][0]+min(i-1,C-i)>=k-1) puts("No"),exit(0);
	}
	puts("Yes");
	rep(i,1,n) printf("%d ",col[i]+1);
}