#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e6+6;
vector<int> G[N],un[N]; int d[N],vis[N],q[N],e[N][2];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n,m; scanf("%d%d",&n,&m);
		rep(i,1,n) G[i].clear(),un[i].clear(),d[i]=vis[i]=0;
		rep(i,1,m){
			int op,u,v; scanf("%d%d%d",&op,&u,&v);
			if (op) G[u].push_back(v),++d[v];
			else un[u].push_back(v),un[v].push_back(u);
		}
		int l=1,r=0,t=0,c=0; rep(i,1,n) if (!d[i]) q[++r]=i;
		while (l<=r){
			int u=q[l++]; vis[u]=true,++c;
			rep0(i,G[u].size()){
				int v=G[u][i]; e[++t][0]=u,e[t][1]=v;
				if (!--d[v]) q[++r]=v;
			}
			rep0(i,un[u].size()){
				int v=un[u][i];
				if (!vis[v]) e[++t][0]=u,e[t][1]=v;
			}
		}
		if (c!=n) puts("NO");
		else{
			puts("YES");
			rep(i,1,t) printf("%d %d\n",e[i][0],e[i][1]);
		}
	}
	return 0;
}