#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register ll
ll dsg[200005]={1},f[200005][3],res;
const ll mod=1000000007;
inline ll qpow(re x,re k) 
{
	re smw=1;
	while(k) 
	{
		if(k&1) smw=(smw*x)%mod;
		k>>=1;x=(x*x)%mod;
	}
	return smw;
}
inline ll clac(re n,re m) 
{
	return dsg[n]*qpow(dsg[m]*dsg[n-m]%mod,mod-2)%mod;
}
int main()
{
	ll n,l,r;
	for(re i=1;i<=200005;i++) dsg[i]=dsg[i-1]*i%mod;
	cin>>n>>l>>r;
	re a[3];
	a[0]=r/3-(l-1)/3;
	a[1]=(r+2)/3-(l+1)/3;
	a[2]=(r+1)/3-l/3;
	f[0][0]=1;
	for(re i=1;i<=200005;i++)
	for(re j=0;j<3;j++)
	{
		f[i][j]=f[i-1][j]*a[0]%mod+f[i-1][(j+2)%3]*a[1]%mod+f[i-1][(j+1)%3]*a[2];
		f[i][j]%=mod;
	}
	cout<<f[n][0];
	return 0;
}