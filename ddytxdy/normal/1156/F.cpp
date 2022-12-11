#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=5050,mod=998244353;
int n,cnt[N],dp[N][N],c,inv[N],ans,x;
int main(){
	scanf("%d",&n);
	inv[1]=1;
	for(int i=2;i<=n;i++)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<=n;i++)scanf("%d",&x),cnt[x]++;
	for(int i=1;i<n;i++){
		c=(i==1);
		for(int j=1;j<=n;j++){
			dp[i][j]=1ll*c*cnt[j]%mod*inv[n-i+1]%mod;
			if(cnt[j]>1)ans=(ans+1ll*dp[i][j]*inv[n-i]%mod*(cnt[j]-1))%mod;
			c=(c+dp[i-1][j])%mod;
		}
	}
	printf("%d",ans);
	return 0;
}