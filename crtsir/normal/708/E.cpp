#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int n,m,a,b,k,p,pw[100003],ipw[100003],ip;
int dpl[1503][1503],dpr[1503][1503];
int mypow(int x,int times){
	int ret=1;
	while(times){
		if(times&1)
			ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;
		times>>=1;
	}return ret;
}
int fac[100003],inv[100003];
int C(int x,int y){
	if(y<0||x<y)return 0;
	return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int calc(int x){if(x>k)return 0;return 1ll*pw[x]*ipw[k-x]%mod*C(k,x)%mod;}
int S[1503],val[1503],dp[1503];
int main(){
	cin>>n>>m>>a>>b>>k;
	p=1ll*a*mypow(b,mod-2)%mod;ip=mod+1-p;
	pw[0]=1;ipw[0]=1;
	for(int i=1;i<100003;i++)
		pw[i]=1ll*pw[i-1]*p%mod,
		ipw[i]=1ll*ipw[i-1]*ip%mod;
	fac[0]=1;
	for(int i=1;i<100003;i++)
		fac[i]=1ll*fac[i-1]*i%mod;
	inv[100002]=mypow(fac[100002],mod-2);
	for(int i=100001;i>=0;i--)
		inv[i]=1ll*inv[i+1]*(i+1)%mod;
	for(int i=1;i<=m;i++)
		for(int j=i;j<=m;j++){
			dpl[0][i]=(dpl[0][i]+1ll*calc(i-1)*calc(m-j))%mod;
			dpr[0][j]=(dpr[0][j]+1ll*calc(i-1)*calc(m-j))%mod;
		}
	for(int i=0;i<=m;i++)S[i]=(calc(i)+(i?S[i-1]:0))%mod;
	for(int i=1;i<n;i++){
		int sum=0,_sum=0;
		for(int j=1;j<=m;j++){
			dpl[i][j]=(dpl[i][j]+1ll*sum*S[m-j]%mod*calc(j-1))%mod;
			sum=(sum+dpr[i-1][j])%mod;
		}sum=0;
		for(int j=m;j>0;j--){
			dpl[i][j]=(dpl[i][j]+(1ll*_sum*S[m-j]-sum+mod)%mod*calc(j-1))%mod;
			_sum=(_sum+dpl[i-1][j])%mod;
			sum=(sum+1ll*dpl[i-1][j]*S[m-j])%mod;
		}
		for(int j=1;j<=m;j++)
			dpr[i][j]=dpl[i][m+1-j];
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<=m;j++)
			val[i]=(val[i]+dpl[i][j])%mod;
		if(i&1)val[i]=(mod-val[i])%mod;
	}
	dp[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<i;j++)
			dp[i]=(dp[i]+1ll*dp[j]*val[i-j-1])%mod;
	cout<<dp[n];
}