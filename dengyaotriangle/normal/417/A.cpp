#include<bits/stdc++.h>

using namespace std;

const int maxn=200;

int d,c;
int n,m,k;
int dp[maxn*maxn];
 
int main(){
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	cin>>c>>d;
	cin>>n>>m>>k;
	int tgt=n*m-k;
	for(int i=1;i<=tgt+n+m+10;i++){
		if(i-n>=0) dp[i]=min(dp[i],dp[i-n]+c);
		if(i-1>=0) dp[i]=min(dp[i],dp[i-1]+d);
	}
	int ans=0x3f3f3f3f;
	for(int i=tgt;i<=tgt+n+m+10;i++) ans=min(ans,dp[i]);
	cout<<ans;
	return 0;
}