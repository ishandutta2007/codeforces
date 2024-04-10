#include<bits/stdc++.h>
using namespace std;
vector<int>v[2003];
int n,x,y;
bool vis[2003];
void dfs(int x){
	vis[x]=1;
	for(int i=0;i<v[x].size();i++)
		if(!vis[v[x][i]])
			dfs(v[x][i]);
	return;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>x>>y,x--,y--,v[x].push_back(y+1000),v[y+1000].push_back(x);
	int ans=-1;
	for(int i=0;i<2003;i++)if(!vis[i]&&v[i].size())dfs(i),ans++;
	cout<<ans;
}