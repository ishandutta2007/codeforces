#include<bits/stdc++.h>
using namespace std;
int n,dp[300004],p[300004],vis[300004];
vector<int>g[300004];
void dfs(int x,int fa){
	for(auto y:g[x])if(y!=fa)
		p[y]=x,dfs(y,x),dp[x]^=dp[y]+1;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(v),g[v].push_back(u);
	}
	dfs(1,0);
	int ans=dp[1];
	putchar(ans?'1':'2');
	for(int i=2;i<=n;i++){
		int j=i;
		vector<int>v;
		for(;!vis[j];j=p[j])v.push_back(j),vis[j]=1;
		reverse(v.begin(),v.end());
		for(auto x:v)ans^=(dp[x]+1)^dp[x]^1;
		putchar(ans?'1':'2');
	}
}