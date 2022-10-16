#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int dp[100003][103],n,k,len,a[100003],cnt[100003][103],sum[100003];
int main(){
	cin>>n>>k>>len;
	if(len==1){cout<<0;return 0;}
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	if(a[1]==-1)
		for(int i=1;i<=k;i++)
			dp[1][i]=1;
	else
		dp[1][a[1]]=1;
	sum[0]=1;
	if(a[1]==-1)
		sum[1]=k;
	else
		sum[1]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k;j++)
			if(a[i]==j||a[i]==-1)
				cnt[i][j]=cnt[i-1][j]+1;
			else
				cnt[i][j]=cnt[i-1][j];
	for(int i=2;i<=n;i++){
		for(int j=1;j<=k;j++)
			if(a[i]==j||a[i]==-1){
				dp[i][j]=sum[i-1];
				if(i>=len)
					if(cnt[i][j]-cnt[i-len][j]==len)
						dp[i][j]=((dp[i][j]+dp[i-len][j]-sum[i-len])%mod+mod)%mod;
				sum[i]+=dp[i][j];
				sum[i]%=mod;
			}
	}
	cout<<sum[n];
}