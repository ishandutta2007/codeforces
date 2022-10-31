#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e6+6; 
vector<int> G[N]; int c[N]; bool vis[N];
void dfs(int u){
	vis[u]=true;
	if (c[u]==1){
		rep0(i,G[u].size()) c[G[u][i]]=0;
		rep0(i,G[u].size()) if (!vis[G[u][i]]) dfs(G[u][i]);
	}
	else{
		rep0(i,G[u].size()){
			int v=G[u][i];
			if (c[v]==-1) c[v]=1,dfs(v);
		}
	}
}
int ans[N];
signed main(){
	int T; scanf("%d",&T);
	while (T--){
		int n,m; scanf("%d%d",&n,&m);
		rep(i,1,n) G[i].clear();
		rep(i,1,m){
			int u,v; scanf("%d%d",&u,&v);
			G[u].push_back(v),G[v].push_back(u);
		}
		rep(i,1,n) vis[i]=0,c[i]=-1; c[1]=1,dfs(1);
		bool f=false; rep(i,1,n) if (!vis[i]) f=true;
		if (f) puts("NO");
		else{
			puts("YES");
			int k=0; rep(i,1,n) if (c[i]==1) ans[++k]=i;
			printf("%d\n",k);
			rep(i,1,k) printf("%d ",ans[i]);
			putchar('\n');
		}
	}
	return 0;
}