#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int mod=1e9+7;
ll fac[maxn],inv[maxn];
ll q_mod(ll a,ll n)
{
	ll res=1;
	while(n){
		if(n&1)res=res*a%mod;
		n>>=1;
		a=a*a%mod;	
	}
	return res;
}
ll C(ll n,ll m)//C(n,m)
{
	if(n<m)return 0;
	return fac[n]*inv[m] % mod * inv[n-m] %mod;
}
int main()
{
	fac[0]=1;
	for(int i=1;i<maxn;i++) fac[i]=fac[i-1]*i%mod;
	
	inv[maxn-1]=q_mod(fac[maxn-1],mod-2);
	
	for(int i=maxn-2;i>=0;--i){
		inv[i]=inv[i+1]*(i+1)%mod;
	}
	
	ll f,w,h;
	cin>>f>>w>>h;
	if(w==0)return 0*puts("1");//... 
	ll a=0,b=0;
	for(int i=1;i<=w;i++){
		a=(a + C(w-1,i-1) * C(f+1,i) )%mod;
		b=(b + C(w-1-i*h,i-1) * C(f+1,i) )%mod;
	}
	cout<<b * q_mod(a,mod-2)%mod<<endl;
	return 0;
}