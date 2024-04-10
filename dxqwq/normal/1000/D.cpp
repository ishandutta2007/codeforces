#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int fac[20005],inv[20005];
const int mod=998244353;
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
	return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int a[1003];
int ans[1003];
signed main()
{
	init_fac(20000);
	int n=read();
	for(int i=1; i<=n; i++) a[i]=read();
	for(int i=0; i<=n; i++) ans[i]=1;
	for(int i=1; i<=n; i++) if(a[i]>0 && a[i]+i<=n)
	{
		for(int j=a[i]; j+i<=n; j++) ans[i+j]+=ans[i-1]*C(j,a[i])%mod,ans[i+j]%=mod;
	}
	printf("%lld\n",(ans[n]+mod-1)%mod);
	return 0;
}

//QAQ