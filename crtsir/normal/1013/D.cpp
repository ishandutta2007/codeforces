#include<bits/stdc++.h>
using namespace std;
int n,m,p,a,b;
bool vis[400003];
vector<int>v[400003];
void dfs(int x){
	vis[x]=1;
	for(int i=0;i<v[x].size();i++)
		if(!vis[v[x][i]])
			dfs(v[x][i]);
}
int main(){
	cin>>n>>m>>p;
	for(int i=0;i<p;i++){
		cin>>a>>b;
		v[a-1].push_back(b-1+n);
		v[b-1+n].push_back(a-1);
	}
	int ans=-1;
	for(int i=0;i<n+m;i++)
		if(!vis[i])
		{
			dfs(i);
			ans++;
		}
	cout<<ans;
}