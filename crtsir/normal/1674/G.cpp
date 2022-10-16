#include<bits/stdc++.h>
using namespace std;
int n,a[200003],b[200003],id[200003],od[200003],m;
vector<int>v[200003];
bool ok[200003];
bool vis[200003];
int dp[200003];
void dfs(int x){
	vis[x]=1;
	dp[x]=1;
	for(int i=0;i<v[x].size();i++){
		if(!vis[v[x][i]])
			dfs(v[x][i]);
		dp[x]=max(dp[x],1+dp[v[x][i]]);
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a[i]>>b[i];a[i]--;b[i]--;
		od[a[i]]++;id[b[i]]++;
	}memset(ok,1,sizeof(ok));
	for(int i=0;i<m;i++)
		if(od[a[i]]!=1&&id[b[i]]!=1){
			v[a[i]].push_back(b[i]);
			ok[b[i]]=0;
		}int ans=0;
	for(int i=0;i<n;i++)
		if(ok[i]){
			dfs(i);
			ans=max(ans,dp[i]);
		}cout<<ans;
}