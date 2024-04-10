#include<bits/stdc++.h>

using namespace std;

const int maxn=500005;

int prv[maxn],loc[maxn];
int pfx[maxn];
int n,c;
int a[maxn];
int dp[maxn];
int main(){
	cin>>n>>c;
	for(int i=1;i<=n;i++)cin>>a[i];
	memset(loc,-1,sizeof(loc));
	for(int i=1;i<=n;i++){
		prv[i]=loc[a[i]];
		loc[a[i]]=i;
		pfx[i]=pfx[i-1]; 
		if(a[i]==c)pfx[i]++;
	}
	int ans=pfx[n];
	for(int i=1;i<=n;i++){
		dp[i]=pfx[i-1]+1;
		if(prv[i]!=-1)dp[i]=max(dp[i],dp[prv[i]]+1);
		ans=max(ans,dp[i]+pfx[n]-pfx[i]);
	} 
	cout<<ans;
	return 0;
}