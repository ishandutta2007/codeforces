#include<bits/stdc++.h>
using namespace std;
int T,n,dp[5003][5003],a[5003],cnt;
map<int,int>mp;
vector<int>v;
int main(){
	T=1;
	while(T--){
		v.clear();
		mp.clear();
		cin>>n;
		mp[0]=1;
		for(int i=1;i<=n;i++)cin>>a[i],mp[a[i]]=1;
		cnt=mp.size();
		for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)v.push_back(it->first);
		for(int i=0;i<=n;i++)for(int j=0;j<cnt;j++)dp[i][j]=1e9;
		dp[0][0]=0;
		for(int i=1;i<=n;i++){
			int cur=1e9;
			for(int j=0;j<cnt;j++)if(v[j]<=a[i]){
				if(j!=0)cur+=v[j]-v[j-1];
				cur=min(cur,dp[i-1][j]);
				if(v[j]==a[i]) dp[i][j]=min(dp[i][j],cur);
				else dp[i][j]=min(dp[i][j],cur+1);
			}
			cur=1e9;
			for(int j=cnt-1;j>=0;j--){
				cur=min(cur,dp[i-1][j]);
				if(v[j]<=a[i]){
				if(v[j]==a[i]) dp[i][j]=min(dp[i][j],cur);
				else dp[i][j]=min(dp[i][j],cur+1);
				}
			}
		}
		int ans=1e9;
		for(int i=0;i<cnt;i++)ans=min(ans,dp[n][i]);
		cout<<ans<<"\n";
	}
}