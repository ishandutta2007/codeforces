#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s[200003];
bool vis[200003],used[26];
vector<int>g[200003],v[26];
void dfs(int x){
	vis[x]=1;
	for(int i=0;i<g[x].size();i++)
		if(!used[g[x][i]]){
			used[g[x][i]]=1;
			for(int j=0;j<v[g[x][i]].size();j++)
				if(!vis[v[g[x][i]][j]])
					dfs(v[g[x][i]][j]);
		}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
		for(int j=0;j<s[i].size();j++)
			if(v[s[i][j]-'a'].empty()||v[s[i][j]-'a'].back()!=i)
				v[s[i][j]-'a'].push_back(i),
				g[i].push_back(s[i][j]-'a');
	}
	for(int i=0;i<n;i++)
		if(!vis[i])
			dfs(i),
			ans++;
	cout<<ans;
}