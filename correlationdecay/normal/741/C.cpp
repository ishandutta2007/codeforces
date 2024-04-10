#include <bits/stdc++.h>
#define maxn 300009
using namespace std;
int n,a[maxn],b[maxn];
int p[maxn];
vector<int>G[maxn];
int ans[maxn];
bool vis[maxn];
void dfs(int u,int c){
	vis[u]=1;
	ans[u]=c;
	for(auto v:G[u]){
		if(vis[v])
			continue;
		dfs(v,3-c);
	}
}
int main(){
	cin>>n;
	for(int i=0;i<2*n;i++)
		p[i]=i;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
		a[i]--;
		b[i]--;
		G[a[i]].push_back(b[i]);
		G[b[i]].push_back(a[i]);
	}
	
	for(int i=0;i<n;i++){
		int u=2*i;
		int v=2*i+1;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=0;i<2*n;i++)
		if(!vis[i])
			dfs(i,1);
	for(int i=1;i<=n;i++){
		printf("%d %d\n",ans[a[i]],ans[b[i]]);
	}
	//system("pause");
	return 0;
}