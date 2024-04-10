#include<iostream>
using namespace std;
#define ll long long
#define MX 1000000
ll f[MX+5];
ll F(ll x)
{
	if(x<=MX)return f[x];
	ll i,r=x;
	for(i=2;i*i<=x;++i)if(x%i==0)
	{
		r=r/i*(i-1);
		while(x%i==0)x/=i;
	}
	return x>1?r/x*(x-1):r;
}
int main()
{
	ll n,k,i,j;
	cin>>n>>k;k=k+1>>1;
	for(i=1;i<=MX;++i)f[i]=i;
	for(i=2;i<=MX;i+=2)f[i]>>=1;
	for(i=3;i<=MX;i+=2)if(f[i]==i)
		for(j=i;j<=MX;j+=i)f[j]=f[j]/i*(i-1);
	while(n>1&&k--)n=F(n);
	cout<<n%1000000007;
}