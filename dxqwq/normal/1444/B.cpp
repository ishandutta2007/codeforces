#include<bits/stdc++.h>
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
int a[500003],n;
const int p=998244353;
int fac[1000003],inv[1000003],b[500003];
inline int qpow(int s,int y,int ret=1)
{
	for(;y;y>>=1,s=1ll*s*s%p) if(y&1) ret=1ll*ret*s%p; 
	return ret;
}
inline void init_fac(int n)
{
	fac[0]=1;
	for(int i=1;i<=n;++i) fac[i]=1ll*fac[i-1]*i%p;
	inv[n]=qpow(fac[n],p-2);
	for(int i=n-1;~i;--i) inv[i]=(i+1ll)*inv[i+1]%p;
}
inline int C(int n,int m){
	if(n<m) return 0;
	return 1ll*fac[n]*inv[m]%p*inv[n-m]%p;
}
int sum=0;
signed main()
{
    init_fac(1000000);
    n=read();
    for(int i=1; i<=2*n; i++) a[i]=read();
    sort(a+1,a+2*n+1);
    int ans=0,sum=0;
    for(int i=1; i<=n; i++) ans+=p-a[i],ans%=p;
    for(int i=n+1; i<=2*n; i++) ans+=a[i],ans%=p; 
    printf("%lld\n",ans*C(2*n,n)%p);
    return 0;
}