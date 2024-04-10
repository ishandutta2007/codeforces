#include<bits/stdc++.h>
using namespace std;
long long n,k,dp[503][503],a[503],b[503],sum[503];
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i]+b[i];
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<k;j++){
			long long aa=j,bb=(sum[i]-j)%k;
			for(int l=0;l<k;l++){if(!dp[i-1][l])continue; 
				long long aaa=l,bbb=(sum[i-1]-l)%k;
				if(a[i]<(aa-aaa+k)%k||b[i]<(bb-bbb+k)%k)continue;
				dp[i][j]=1;break;
			}
		}long long ans=0;
	for(int i=0;i<k;i++)if(dp[n][i]){
		long long aa=i,bb=(sum[n]-i)%k;
		ans=max(ans,(sum[n]-aa-bb)/k);
	}
	cout<<ans;
}