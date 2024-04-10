#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7,N=205;
inline int mo1(int x){ return x>=MOD?x-MOD:x; }
inline void mo(int& x){x>=MOD?x-=MOD:0; }
inline int fpow(int x,int n,int ret=1){
	for(;n;n>>=1,x=1ll*x*x%MOD)
		if(n&1) ret=1ll*ret*x%MOD;
	return ret;
}
struct Graph{
	struct Edge{ int to,nxt; };
	vector<Edge> edge;
	vector<int> head;
	Graph(int n=0,int m=0){
		head=vector<int>(n+1,-1);
		edge.clear(); edge.reserve(m);
	}
	inline void add(int x,int y){
		edge.push_back((Edge){y,head[x]});
		head[x]=edge.size()-1;
	}
}G;
int sz[N],fa[N];
void dfs(int x,int pre){
	fa[x]=pre,sz[x]=1;
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		if(y!=pre){
			dfs(y,x),sz[x]+=sz[y];
		}
	}
}
int f[N][N];
int main(){
	int n; scanf("%d",&n);
	G=Graph(n,n+n);
	for(int i=1;i<n;++i){
		int x,y; scanf("%d%d",&x,&y);
		G.add(x,y); G.add(y,x);
	}
	dfs(1,0);
	for(int i=1;i<=n;++i) f[0][i]=0,f[i][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			f[i][j]=1ll*(MOD+1>>1)*(f[i-1][j]+f[i][j-1])%MOD;
	int ans=0,invn=fpow(n,MOD-2);
	for(int x=1;x<=n;++x){
		dfs(x,0);
		for(int y=x+1;y<=n;++y){
			vector<int> g;
			g.push_back(sz[y]);
			for(int z=y;z!=x;z=fa[z])
				g.push_back(sz[fa[z]]-sz[z]);
			for(int i=0;i<g.size();++i){
				ans=(ans+1ll*invn*g[i]%MOD*f[g.size()-1-i][i])%MOD;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}