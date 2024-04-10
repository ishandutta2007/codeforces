#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,ggg=3,invggg=(mod+1)/ggg;
const int maxn=524288;
int tmp[maxn],F[maxn],G[maxn];
int mypow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		y>>=1;x=1ll*x*x%mod;
	}return ret;
}
int revs[maxn];
void initrev(int Len){
	for(int i=1;i<Len;++i){
		revs[i]=revs[i>>1]>>1;
		if(i&1)revs[i]|=(Len>>1);
	}
}
void DFT(int *f,int n,int rev){
	int g0=rev==1?ggg:invggg;
	initrev(n);
	for(register int i=0;i<n;++i)
		if(i<revs[i])
			f[i]^=f[revs[i]]^=f[i]^=f[revs[i]];
	for(register int h=2;h<=n;h<<=1){
		int gn=mypow(g0,(mod-1)/h);
		for(register int j=0;j<n;j+=h){
			int gk=1;
			for(register int k=j;k<j+(h>>1);++k){
				int e=f[k],o=1ll*gk*f[k+(h>>1)]%mod;
				f[k]=(e+o)%mod,f[k+(h>>1)]=(e+mod-o)%mod;
				gk=1ll*gk*gn%mod;
			}
		}
	}
	if(rev==-1){
		int invv=mypow(n,mod-2);
		for(register int i=0;i<n;++i)
			f[i]=1ll*f[i]*invv%mod; 
	}
}int n,k,m;
int dp[19][524288];
int main(){
	cin>>n>>k>>m;
	for(int i=0;i<=k;i++)
		dp[0][i]=1;
	for(int i=1;i<=n;i++){
		DFT(dp[i-1],maxn,1);
		for(int j=0;j<maxn;j++)
			dp[i][j]=1ll*dp[i-1][j]*dp[i-1][j]%mod;
		DFT(dp[i],maxn,-1);
		if(i==n)break;
		int sum=0;
		for(int j=maxn-1;j>=0;j--){
			sum=(sum+dp[i][j])%mod;
			if(j<=k)
				dp[i][j]=(1ll*dp[i][j]*(k-j)+sum)%mod;
			else
				dp[i][j]=0;
		}
	}cout<<dp[n][m];
}