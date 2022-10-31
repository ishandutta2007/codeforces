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
vector<int> G[N]; int d[N];
void dfs(int u,int f,int dep){
	d[u]=dep;
	rep0(i,G[u].size()){
		int v=G[u][i];
		if (v!=f) dfs(v,u,dep+1);
	}
}
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n,a,b,da,db; 
		scanf("%d%d%d%d%d",&n,&a,&b,&da,&db);
		rep(i,1,n) G[i].clear();
		rep(i,1,n-1){
			int u,v; scanf("%d%d",&u,&v);
			G[u].push_back(v),G[v].push_back(u); 
		}
		if (2*da>=db){ puts("Alice"); continue; }
		dfs(1,0,0); int u=0;
		rep(i,1,n) if (d[i]>d[u]) u=i;
		dfs(u,0,0); int mx=0;
		rep(i,1,n) mx=max(mx,d[i]);
		if (da>=(mx+1)/2){ puts("Alice"); continue; }
		dfs(a,0,0);
		puts(da>=d[b]?"Alice":"Bob");
	}
	return 0;
}