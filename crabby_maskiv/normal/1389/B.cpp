#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n,m,k;
ll a[N];
ll dp[N][6];
int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n>>m>>k;
		for(i=1;i<=n;i++) cin>>a[i];
		for(i=1;i<=n;i++) memset(dp[i],0xf3,sizeof(dp[i]));
		dp[1][0]=a[1];
		for(i=2;i<=m+1;i++){
			for(j=0;j<=k;j++) dp[i][j]=dp[i-1][j]+a[i];
			for(j=1;j<=k;j++) dp[i][j]=max(dp[i][j],dp[i][j-1]+(a[i]+a[i-1]));
		}
		ll ans=0;
		for(i=1;i<=m+1;i++){
			for(j=0;j<=k;j++){
				if(i+j*2-2<=m)
					ans=max(ans,dp[i][j]-a[i]);
				if(i+j*2-1<=m)
					ans=max(ans,dp[i][j]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}