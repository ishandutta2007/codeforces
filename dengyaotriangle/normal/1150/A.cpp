#include<bits/stdc++.h>

using namespace std;

const int maxn=35;

int a[maxn],b[maxn];
int dp[1005];
int main(){
	int n,m,c;
	cin>>n>>m>>c;
	for(int i=1;i<=n;i++)cin>>a[i];
	int mcs=0;
	int ans=c;
	for(int i=1;i<=m;i++)cin>>b[i];/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int e1=c/a[i];
			int e2=c-e1*a[i];
			ans=max(ans,e2+e1*b[j]);
		}
	}*/
	for(int i=1;i<=m;i++) mcs=max(mcs,b[i]);
	for(int i=0;i<=c;i++) dp[i]=c;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=c;j++){
			if(j>=a[i])dp[j]=max(dp[j],dp[j-a[i]]+mcs-a[i]);
			ans=max(ans,dp[j]);
		}
	}
	cout<<ans;
	return 0;
}