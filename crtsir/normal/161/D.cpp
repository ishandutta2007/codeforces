#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int>v[50003];
long long dp[50003][503],ans;
void dfs(int now,int fa){
	dp[now][0]=1;
	for(int i=0;i<v[now].size();i++)
		if(fa!=v[now][i]){
			dfs(v[now][i],now);
			for(int j=0;j<k;j++)ans+=dp[now][k-j-1]*dp[v[now][i]][j];
			for(int j=0;j<k;j++)dp[now][j+1]+=dp[v[now][i]][j];
		}
}
int main(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;a--;b--;
		v[a].push_back(b);v[b].push_back(a);
	}
	dfs(0,-1);
	cout<<ans;
}