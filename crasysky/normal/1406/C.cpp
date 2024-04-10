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
vector<int> G[N]; int s[N],fa[N],leaf[N];
void dfs(int u,int f){
	fa[u]=f,s[u]=1;
	if (G[u].size()==1) leaf[u]=u;
	rep0(i,G[u].size()){
		int v=G[u][i];
		if (v!=f) dfs(v,u),s[u]+=s[v],leaf[u]=v;
	}
}
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n; scanf("%d",&n);
		rep(i,1,n) G[i].clear();
		rep(i,1,n-1){
			int u,v; scanf("%d%d",&u,&v);
			G[u].push_back(v),G[v].push_back(u);
		}
		if (n&1){ 
			printf("%d %d\n%d %d\n",1,G[1][0],1,G[1][0]); 
			continue;
		}
		dfs(1,0);
		bool f=false;
		rep(i,1,n)
			if (s[i]==n/2){
				f=true;
				printf("%d %d\n%d %d\n",leaf[i],fa[leaf[i]],leaf[i],fa[i]);
				break;
			}
		if (!f) printf("%d %d\n%d %d\n",1,G[1][0],1,G[1][0]);
	}
	return 0;
}