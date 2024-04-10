#include<bits/stdc++.h>
using namespace std;
int path[5003],dp[5003],n,h[5003],w[5003],a,b;
int dfs(int x,int y,int i){
	if(dp[i]>-1)return dp[i]+1;
	int ans=0;
	for(int j=0;j<n;j++)
		if(h[j]>x&&w[j]>y)
			if(dp[i]<=dfs(h[j],w[j],j)+1)
				dp[i]=dfs(h[j],w[j],j)+1,
				path[i]=j;
	return dp[i]+1;
}
int main(){
	cin>>n>>a>>b;
	for(int i=0;i<n;i++)
		cin>>h[i]>>w[i],
		path[i]=-1,
		dp[i]=-1;
	path[n]=-1;dp[n]=-1;
	dfs(a,b,n);
	vector<int>ans;
	while(path[n]>=0)
		ans.push_back(path[n]),
		n=path[n];
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)cout<<ans[i]+1<<' ';
}