#include<bits/stdc++.h>
using namespace std;
vector<int>adj[1000000];
int mark[1000000];
long long int sol=0;
int m;
void dfs(int u,int p)
{
	for(int i=0;i<adj[u].size();i++)
	if(p!=adj[u][i]){
		dfs(adj[u][i],u);
		mark[u]+=mark[adj[u][i]];
	}
	sol+=min(mark[u],2*m-mark[u]);
}
int main(){
	int n,x,y;
	scanf("%d%d",&n,&m);
	for(int i=0;i<2*m;i++)
	{
		int x;
		cin>>x;
		mark[x]++;
	}
	for(int i=0;i<n-1;i++)
	{
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1,0);
	cout<<sol<<endl;
}