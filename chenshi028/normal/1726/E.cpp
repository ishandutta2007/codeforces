#include<cstdio>
#include<iostream>
using namespace std;
const int o=1.2e6,MOD=998244353;
inline int fix(int x){return x+(x>>31&MOD);}
inline int qp(int b,int f){int res=1;for(;f;f>>=1,b=b*1ll*b%MOD) if(f&1) res=res*1ll*b%MOD;return res;}
int T,n,f[o],fac[o],inv[o],pw[o],ans,a[o],b[o],w[o],rev[o],bt;
inline void init(){
	for(int i=1;i<(1<<bt);++i) rev[i]=(rev[i>>1]>>1)|((i&1)<<(bt-1));
	w[1<<(bt-1)]=1;
	for(int i=(1<<(bt-1)),j=qp(3,(MOD-1)/(1<<bt));i<(1<<bt);++i) w[i+1]=w[i]*1ll*j%MOD;
	for(int i=(1<<(bt-1));--i;) w[i]=w[i<<1];
}
inline void ntt(int*a,int n,bool inv){
	for(int i=1;i<n;++i) if(rev[i]<i) swap(a[i],a[rev[i]]);
	for(int md=1;md<n;md<<=1) for(int i=0;i<n;i+=md<<1) for(int j=0,x,y;j<md;++j)
		x=a[i+j],y=a[i+j+md]*1ll*w[j+md]%MOD,a[i+j]=fix(x+y-MOD),a[i+j+md]=fix(x-y);
	if(inv) for(int i=1,j=n-1;i<j;swap(a[i++],a[j--]));
}
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",ans),ans=0){
		scanf("%d",&n);inv[1]=1;
		for(int i=2;i<=n;++i) inv[i]=MOD-MOD/i*1ll*inv[MOD%i]%MOD;
		for(int i=fac[0]=inv[0]=1;i<=n;++i) fac[i]=fac[i-1]*1ll*i%MOD,inv[i]=inv[i-1]*1ll*inv[i]%MOD;
		for(int i=pw[0]=1;i<=n;++i) pw[i]=pw[i-1]*(MOD+1ll)/2%MOD;
		for(bt=1;(1<<bt)<=n*2;++bt);
		if((1<<bt)<33)
			for(int i=0;i<=n;++i) for(int j=f[i]=0;j*2<=i;++j) f[i]=(f[i]+fac[i]*1ll*pw[j]%MOD*inv[i-2*j]%MOD*inv[j])%MOD;
		else{
			for(int i=0;i<(1<<bt);++i) a[i]=b[i]=0;
			for(int i=0;i*2<=n;++i) a[i*2]=inv[i]*1ll*pw[i]%MOD;
			for(int i=0;i<=n;++i) b[i]=inv[i];
			init();ntt(a,1<<bt,0);ntt(b,1<<bt,0);
			for(int i=0;i<(1<<bt);++i) a[i]=a[i]*1ll*b[i]%MOD;
			ntt(a,1<<bt,1);
			for(int i=0,j=qp(1<<bt,MOD-2);i<=n;++i) f[i]=a[i]*1ll*j%MOD*fac[i]%MOD;
		}
		for(int i=0;i*2<=n;i+=2) ans=(ans+fac[n-i]*1ll*inv[i]%MOD*inv[n-2*i]%MOD*f[n-i*2]%MOD*fac[i]%MOD*inv[i/2])%MOD;
	}
	return 0;
}