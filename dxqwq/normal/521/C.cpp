// Problem: C. Pluses everywhere
// Contest: Codeforces - Codeforces Round #295 (Div. 1)
// URL: https://codeforces.com/contest/521/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+(ch&15),ch=getchar();
    return x;
}
int fac[200005],inv[200005];
const int mod=1e9+7;
inline int qpow(int s,int y,int ret=1)
{
	for(;y;y>>=1,s=1ll*s*s%mod) if(y&1) ret=1ll*ret*s%mod; 
	return ret;
}
inline void init_fac(int n)
{
	fac[0]=1;
	for(int i=1;i<=n;++i) fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=qpow(fac[n],mod-2);
	for(int i=n-1;~i;--i) inv[i]=(i+1ll)*inv[i+1]%mod;
}
inline int C(int n,int m){
	if(n<m) return 0;
	if(m==0) return 1;
	return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
char s[1000003];
int a[100003];
signed main()
{
	init_fac(100001);
    int n=read(),k=read();
    scanf("%s",s+1);
    for(int i=1; i<=n; i++) a[i]=s[i]-48;
    for(int i=1; i<=n; i++) (a[i]+=a[i-1])%=mod;
    int ans=0;
    // for(int i=1; i<n; i++) 
    // {
    	// for(int j=i,t=1;j<n;t=t*10%mod,++j)
    	// {
    		// (ans+=C(n-(j-i+1)-1,k-1)*t%mod*a[i]%mod)%=mod;
    	// }
    	// printf("%lld\n",ans);
    // }
    for(int i=0,t=1; i<n; i++,t=t*10%mod)//j-i
    (ans+=C(n-(i+1)-1,k-1)*t%mod*a[n-1-i]%mod)%=mod;
    for(int i=n,t=1; i>=1; i--,t=t*10%mod) (ans+=C(i-1,k)*((a[i]+mod-a[i-1])%mod)%mod*t%mod)%=mod;
    printf("%lld\n",ans);
    return 0;
}