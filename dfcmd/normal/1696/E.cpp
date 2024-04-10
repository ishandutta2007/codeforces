#include<bits/stdc++.h>
using namespace std;
#define N 400020
const int mod=1e9+7;
typedef long long ll;
int n,a[N],fac[N],ifac[N];
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;++i){
		fac[i]=1LL*fac[i-1]*i%mod;
	}
	ifac[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i){
		ifac[i]=1LL*ifac[i+1]*(i+1)%mod;
	}
}
inline int C(int n,int m){
	if(m<0||m>n)return 0;
	return 1LL*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<=n;++i){
		cin>>a[i];
	}
	int m=a[0];
	init(n+m);
	int ans=0;
	for(int i=0;i<=n;++i){
		ans=(ans+C(i+a[i],a[i]-1))%mod;
	}
	cout<<ans<<'\n';
	return 0;
}