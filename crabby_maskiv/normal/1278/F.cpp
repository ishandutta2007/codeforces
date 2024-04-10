#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005;
const int mod=998244353;
ll n,m;int k;
inline ll po(ll x,ll k){
	ll ret=1;
	while(k){
		if(k&1) ret=ret*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ret;
}
int s[N][N];
ll fac[N],invf[N];
inline ll C(int x,int k){
	return fac[x]*invf[k]%mod*invf[x-k]%mod;
}
ll fn[N];
int main(){
	int i,j;
	s[0][0]=1;
	for(i=1;i<N;i++){
		for(j=0;j<=i;j++){
			if(j==0) s[i][j]=0;
			else s[i][j]=(s[i-1][j]*ll(j)+s[i-1][j-1])%mod;
		}
	}
	fac[0]=1;
	for(i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;
	invf[N-1]=po(fac[N-1],mod-2);
	for(i=N-2;i>=0;i--) invf[i]=invf[i+1]*(i+1)%mod;
	cin>>n>>m>>k;
	fn[0]=1;
	for(i=1;i<=k;i++) fn[i]=fn[i-1]*(n-i+1)%mod;
	for(i=1;i<=k;i++) fn[i]=fn[i]*invf[i]%mod;
	ll ans=0;
	m=po(m,mod-2);
	for(i=1;i<=k;i++){
		if(i>n) break;
		ans=(ans+po(m,i)*fn[i]%mod*fac[i]%mod*s[k][i]%mod)%mod;
	}
	
	cout<<ans;
	return 0;
}