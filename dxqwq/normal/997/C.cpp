#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
int read(){
	int w=0,f=1;
	char c=' ';
	while(c<'0'||c>'9')c=getchar(),f=c=='-'?-1:f;
	while(c>='0'&&c<='9')w=w*10+c-48,c=getchar();
	return w*f;
}
inline long long qpow(long long a,long long b)//a^b
{
    if(b==0) return 1;
    if(b==1) return a;
    long long t=qpow(a,b/2);
    t=t*t%MOD;
    if(b&1) t=t*a%MOD;
    return t;
}
long long fac[1000003],inv[1000003];
void init(int n)
{
    fac[0]=inv[0]=1;
    for(int i=1; i<=n; i++) fac[i]=fac[i-1]*i%MOD;
    inv[n]=qpow(fac[n],MOD-2);
    for(int i=n-1; i>=1; i--) inv[i]=inv[i+1]*(i+1)%MOD;
}
inline long long C(long long n,long long m)//C(n,m)
{
    if(n<m) return 0;
    if(m>n-m) m=n-m;
    return fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}
int main()
{
	int n=read();
	init(n);
	long long ans=(2ll*(qpow(qpow(3,n)-3,n)-qpow(qpow(3,n),n))-3ll*(qpow(qpow(3,n)-1,n)-qpow(qpow(3,n),n)))%MOD;
    ans=(ans+MOD)%MOD;
	for(int i=1; i<=n; i++) if(i&1) ans+=MOD-3ll*C(n,i)%MOD*qpow(qpow(3,n-i)-1,n)%MOD,ans%=MOD; else ans+=3ll*C(n,i)%MOD*qpow(qpow(3,n-i)-1,n)%MOD,ans%=MOD;
	printf("%lld\n",(MOD-ans)%MOD);
    return 0;
}