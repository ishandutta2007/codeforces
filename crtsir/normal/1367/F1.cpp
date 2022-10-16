#include<bits/stdc++.h>
using namespace std;
int T,n,x[200003],dp[200003];pair<int,int>a[200003];
int main(){
	cin>>T;while(T--){
		cin>>n;
		for(int i=0;i<n;i++)scanf("%d",&a[i].first),a[i].second=i,dp[i]=0;
		sort(a,a+n);
		for(int i=0;i<n;i++)x[a[i].second]=i;
		for(int i=0;i<n;i++)
			if(x[i]==0)
				dp[x[i]]=1;
			else
				dp[x[i]]=dp[x[i]-1]+1;int ans=0;
		for(int i=0;i<n;i++)ans=max(ans,dp[i]);
		cout<<n-ans<<endl;
	}
}