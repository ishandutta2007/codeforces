#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int mypow(int x,int times){
	int ret=1;
	while(times){
		if(times&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;times>>=1;
	}return ret;
}
int val[200003],ans=0,fac[200003],inv[200003],pw[200003],fact[200003],sum[200003];
int calc(int len,int k){
	int ret=0;k=min(k,len);
	for(int i=1;i<=k;i++){
		if(fact[i]==0)
			pw[i]=mypow(i,len);
		else
			pw[i]=1ll*pw[fact[i]]*pw[i/fact[i]]%mod;
		ret=(ret+1ll*pw[i]*inv[i]%mod*sum[k-i])%mod;
	}
	return ret;
}
int main(){
	inv[0]=1;
	fac[0]=1;for(int i=1;i<200003;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[200002]=mypow(fac[200002],mod-2);
	for(int i=200001;i>=0;i--)inv[i]=1ll*inv[i+1]*(i+1)%mod;
	for(int i=0;i<200003;i++){
		sum[i]=inv[i];
		if(i&1)sum[i]=mod-sum[i];
	}
	for(int i=1;i<200003;i++)
		sum[i]=(sum[i]+sum[i-1])%mod;
	for(int i=2;i<=200001;i++)
		if(fact[i]==0)
			for(int j=i+i;j<=200001;j+=i)
				fact[j]=i;
	int n,k;
	cin>>n>>k;val[1]=1;
	if(n==1||k==1){cout<<1;return 0;}
	for(int i=1;i<=n;i++){
		ans+=val[i]*(calc((n+i-1)/i,k)-1);
		if(ans<0)ans+=mod;
		if(ans>=mod)ans-=mod;
		for(int j=i+i;j<=n;j+=i)
			val[j]-=val[i];
	}cout<<ans;
}