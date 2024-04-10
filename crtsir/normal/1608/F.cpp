#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long dp[2][2003][2003],ans,fac[2003],inv[2003];
int lstl,lstr,nwl,nwr,b[2003],n,K;
long long mypow(long long x,int y){
	long long ret=1;
	while(y){
		if(y&1)ret=ret*x%mod;
		y>>=1;x=x*x%mod;
	}return ret;
}
int main(){
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++)
		scanf("%d",b+i);
	fac[0]=1;inv[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=1ll*fac[i-1]*i%mod;
		inv[i]=mypow(fac[i],mod-2);
	}
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++){
		nwl=max(0,b[i]-K);
		nwr=min(i,b[i]+K);
		int L=max(nwl,lstl),R=min(nwr,lstr),LL=max(min(lstl+1,L),nwl),RR=nwr;
		for(int j=lstl;j<=nwr;j++)
			for(int k=j;k<=i;k++)
				dp[i&1][j][k]=0;
		for(int j=lstl+1;j<=nwr;j++)
			for(int k=j;k<=i;k++){
				if(j-1<=lstr)dp[i&1][j][k]+=dp[(i^1)&1][j-1][k-1];
				dp[i&1][j][k]+=dp[i&1][j-1][k]*(k-j+1)%mod;
			}
		for(int j=L;j<=R;j++)
			for(int k=j+1;k<=i;k++)
				dp[i&1][j][k]+=dp[(i^1)&1][j][k-1];
		for(int j=L;j<=R;j++)
			for(int k=j;k<=i;k++)
				dp[i&1][j][k]+=dp[(i^1)&1][j][k]*k%mod;
		lstl=LL;lstr=RR;
		for(int j=lstl;j<=lstr;j++)
			for(int k=j;k<=i;k++)
				dp[i&1][j][k]%=mod;
	}
	for(int i=lstl;i<=lstr;i++)
		for(int j=i;j<=n;j++)
			ans+=dp[n&1][i][j]*fac[n-i]%mod*inv[n-j]%mod;
	cout<<ans%mod;
}