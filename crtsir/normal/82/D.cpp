#include<bits/stdc++.h>
using namespace std;
int n,a[1003];
pair<pair<int,int>,pair<int,int> >dp[1003][1003];//i+1i+1j 
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	if(n==1){
		cout<<a[0]<<endl<<1;
		return 0;
	}
	memset(dp,63,sizeof(dp));
	dp[1][0].first.first=0;
	for(int i=3;i<=n;i+=2)
		for(int j=0;j<i-2;j++){
			dp[i][j].first.first=dp[i-2][j].first.first+max(a[i-1],a[i-2]);
			dp[i][j].second=make_pair(i-1,i),
			dp[i][j].first.second=j;
			//cout<<max(a[j],a[i-1])<<' '<<max(a[j],a[i-2])<<endl;
			if(dp[i][i-2].first.first>dp[i-2][j].first.first+max(a[j],a[i-1]))
				dp[i][i-2].first.first=dp[i-2][j].first.first+max(a[j],a[i-1]),
				dp[i][i-2].second=make_pair(j+1,i),
				dp[i][i-2].first.second=j;
			if(dp[i][i-1].first.first>dp[i-2][j].first.first+max(a[j],a[i-2]))
				dp[i][i-1].first.first=dp[i-2][j].first.first+max(a[j],a[i-2]),
				dp[i][i-1].second=make_pair(j+1,i-1),
				dp[i][i-1].first.second=j;
		}
	if(n%2==0){
		int ans=1232332222,xx;
		for(int i=0;i<n;i++)
			if(ans>=dp[n-1][i].first.first+max(a[i],a[n-1]))
				ans=dp[n-1][i].first.first+max(a[i],a[n-1]),
				xx=i;
		cout<<ans<<endl;
		vector<pair<int,int> >v;
		v.push_back(make_pair(xx+1,n));
		for(int i=n-1;i>1;i-=2)v.push_back(make_pair(dp[i][xx].second.first,dp[i][xx].second.second)),xx=dp[i][xx].first.second;
		for(int i=v.size()-1;i>=0;i--)cout<<v[i].first<<' '<<v[i].second<<endl;
		return 0;
	}
	if(n%2==1){
		int ans=1232332222,xx,tmp;
		for(int i=0;i<n;i++)
			if(ans>=dp[n][i].first.first+a[i])
				ans=dp[n][i].first.first+a[i],
				xx=i;
		tmp=xx;
		cout<<ans<<endl;
		vector<pair<int,int> >v;
		for(int i=n;i>1;i-=2)
			v.push_back(make_pair(dp[i][xx].second.first,dp[i][xx].second.second)),xx=dp[i][xx].first.second;
		for(int i=v.size()-1;i>=0;i--)cout<<v[i].first<<' '<<v[i].second<<endl;
		cout<<tmp+1;
	}
}