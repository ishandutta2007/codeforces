#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
long long n,m;
long long ans=1,MOD=1000000007;
long long modpow(long long a,long long b)
{
	if (b==0) return 1;
	long long ans=modpow(a,b/2);
	ans*=ans;
	ans%=MOD;
	if (b%2) ans*=a,ans%=MOD;
	return ans;
}
inline long long calc(long long a,long long b)
{
    long long ans=0;
    for(long long i=a;i<=n;i*=a)
    {
        ans+=n/i;
        if(n/i<a)break;
    }
    return modpow(a,ans);
} 
int main( )
{
    scanf("%lld%lld",&m,&n);
    long long nn=sqrt(m)+1;
    for(long long i=2;i<=nn;i++)
    if(m%i==0)
    {
        long long a=0;
        while(m%i==0)m/=i,a++;
        ans=ans*calc(i,a)%MOD;
    }
    if(m>1)ans=ans*calc(m,1)%MOD;
    cout<<ans;
    return 0;
}