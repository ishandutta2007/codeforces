#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1000000007;
inline int read()
{
    int s=0, w=1; char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int pre[1003][1003],res;
inline int F(int lx,int ly,int rx,int ry)
{
	if(lx>rx || ly>ry) return 0;
	return pre[rx][ry]-pre[rx][ly-1]-pre[lx-1][ry]+pre[lx-1][ly-1];
}
int x[5003],y[5003],b[5003];
int fac[10005],inv[10005];
inline int qpow(int x,int y,int ret=1)
{
	for(;y;y>>=1,x=1ll*x*x%mod) if(y&1) ret=1ll*ret*x%mod; 
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
signed main()
{
	init_fac(10000);
    int n=read(),m=read(),r=read();
	for(int i=1; i<=n; i++) x[i]=read(), y[i]=read(), b[i]=read();
	for(int i=1; i<=n; i++) ++pre[x[i]][y[i]];
	for(int i=1; i<=1000; i++) for(int j=1; j<=1000; j++) pre[i][j]+=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
	for(int i=1; i<=n; i++)
	{
		int w=F(max(1ll,x[i]-r),max(1ll,y[i]-r),min(1000ll,x[i]+r),min(1000ll,y[i]+r));
		res+=b[i]*b[i]%mod*(C(n,m)-C(n-w,m)+mod)%mod,res%=mod;		
	}
	for(int i=1; i<=n; i++) for(int j=1; j<i; j++)
	{
		int tot=C(n,m);
		res+=2ll*tot*b[i]%mod*b[j]%mod,res%=mod;
		int A=F(max(1ll,x[i]-r),max(1ll,y[i]-r),min(1000ll,x[i]+r),min(1000ll,y[i]+r));
		res+=mod-2ll*C(n-A,m)*b[i]%mod*b[j]%mod,res%=mod;
		int B=F(max(1ll,x[j]-r),max(1ll,y[j]-r),min(1000ll,x[j]+r),min(1000ll,y[j]+r));
		res+=mod-2ll*C(n-B,m)*b[i]%mod*b[j]%mod,res%=mod;
		int CC=F(max(max(1ll,x[i]-r),max(1ll,x[j]-r)),max(max(1ll,y[i]-r),max(1ll,y[j]-r)),min(min(1000ll,x[i]+r),min(1000ll,x[j]+r)),min(min(1000ll,y[i]+r),min(1000ll,y[j]+r)));
		res+=2ll*C(n-A-B+CC,m)*b[i]%mod*b[j]%mod,res%=mod;
	}
	printf("%lld\n",(res+mod)%mod);
    return 0;
}