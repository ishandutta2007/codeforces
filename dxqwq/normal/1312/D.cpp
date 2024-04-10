#include<bits/stdc++.h>
#define MOD (long long)998244353
using namespace std;
long long fac[200003],lst[200003];
inline long long qpow(long long a,long long b)
{
    if(b==1) return a;
    long long t=qpow(a,b/2);
    t=t*t%MOD;
    if(b&1) t=t*a%MOD;
    return t;
}
inline long long c(long long m,long long n)
{
    if(n<m) return 0;
    if(m>n-m) m=n-m;
    long long a=lst[m],b=fac[m];
    return a*qpow(b,MOD-2)%MOD;
}
inline long long C(long long m,long long n)
{
    if(n<m) return 0;
    if(m>n-m) m=n-m;
    long long a=1,b=1;
    for(long long i=0;i<m;i++)
	{
        a=(a*(n-i))%MOD;
        b=(b*(i+1))%MOD;
    }
    return a*qpow(b,MOD-2)%MOD;
}
int main()
{
	long long n,m,ans=0;
	cin>>n>>m;
	lst[0]=fac[0]=1;
	for(long long i=1; i<n-1; i++) fac[i]=fac[i-1]*i%MOD,lst[i]=lst[i-1]*(n-i-2)%MOD;
	for(long long i=2; i<n; i++) ans+=c(i-2,n-3)*(n-2),ans%=MOD;
	ans*=C(n-1,m),ans%=MOD;
	cout<<ans;
	return 0;
}