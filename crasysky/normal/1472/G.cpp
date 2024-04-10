#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,ll>
#define mp make_pair
#define fi first
#define se second
#define ll long long 
using namespace std;
const int N=1e6+6; 
vector<int> G[N]; int n,d[N],ans[N]; queue<int> q;
void dfs(int u){
	if (ans[u]!=n+1) return;
	ans[u]=d[u];
	rep0(i,G[u].size()){
		int v=G[u][i];
		if (d[v]<=d[u]) ans[u]=min(ans[u],d[v]);
		else dfs(v),ans[u]=min(ans[u],ans[v]);
	}
}
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int m; scanf("%d%d",&n,&m);
		rep(i,1,n) G[i].clear();
		rep(i,1,m){
			int u,v; scanf("%d%d",&u,&v);
			G[u].push_back(v);
		}
		rep(i,1,n) d[i]=n+1,ans[i]=n+1; 
		d[1]=0,q.push(1);
		while (!q.empty()){
			int u=q.front(); q.pop();
			rep0(i,G[u].size()){
				int v=G[u][i];
				if (d[u]+1<d[v]) d[v]=d[u]+1,q.push(v);
			}
		}
		rep(i,1,n) dfs(i);
		rep(i,1,n) printf("%d ",ans[i]); putchar('\n');
	}
	return 0;
}