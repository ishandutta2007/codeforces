#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=14;
const int M=2e6+5;
const int mod=1e9+7;
int n,m;
int w[N][1<<N];
int dp[1<<N];
int a[N];
int inv[M];
int main(){
	int i,j,k;
	cin>>n;
	for(i=0;i<n;i++) cin>>a[i];
	inv[1]=1;
	for(i=2;i<M;i++) inv[i]=ll(mod-mod/i)*inv[mod%i]%mod;
	for(i=0;i<n;i++){
		for(j=0;j<(1<<n);j++){
			if(j>>i&1) continue;
			w[i][j]=1;
			for(k=0;k<n;k++)
				if(j>>k&1) w[i][j]=1ll*w[i][j]*a[i]%mod*inv[a[i]+a[k]]%mod;
		}
	}
	for(i=1;i<(1<<n);i++){
		dp[i]=1;
		for(j=(i-1)&i;j;j=(j-1)&i){
			int s=dp[j];
			for(k=0;k<n;k++)
				if(j>>k&1) s=1ll*s*w[k][i-j]%mod;
			dp[i]=(dp[i]-s+mod)%mod;
		}
	}
	int ans=0;
	for(i=1;i<(1<<n);i++){
		int x=__builtin_popcount(i);
		int s=dp[i];
		for(j=0;j<n;j++)
			if(i>>j&1) s=1ll*s*w[j][(1<<n)-1-i]%mod;
		ans=(ans+1ll*x*s)%mod;
	}
	cout<<ans;
	return 0;
}