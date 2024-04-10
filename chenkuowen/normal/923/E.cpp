#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353,N=1<<20|5;
inline void mo(int& x){x-=MOD; x+=(x>>31)&MOD; }
inline int mo1(int x){ x-=MOD; return x+((x>>31)&MOD); }
inline int mo2(int x){ return x+((x>>31)&MOD); }
inline int fpow(int x,int n,int ret=1){
	for(;n;n>>=1,x=1ll*x*x%MOD)
		if(n&1) ret=1ll*ret*x%MOD;
	return ret;
}
int inv[N],fac[N],ifac[N];
namespace POLY{
	vector<int> w[23];
	struct II{
		II(){
			inv[1]=fac[0]=ifac[0]=1;
			for(int i=1;i<N;++i){
				fac[i]=1ll*fac[i-1]*i%MOD;
				if(i>1) inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
				ifac[i]=1ll*ifac[i-1]*inv[i]%MOD;
			}
			for(int l=1;l<=20;++l){
				w[l].resize(1<<l-1); w[l][0]=1;
				int wn=fpow(3,MOD-1>>l);
				for(int i=1;i<w[l].size();++i)
					w[l][i]=1ll*w[l][i-1]*wn%MOD;
			}
		}
	}__ii;
	inline void NTT(int a[],int n,int t){
		for(int i=0,pos=0;i<n;++i){
			if(i<pos) swap(a[i],a[pos]);
			for(int p=n>>1;(pos^=p)<p;p>>=1);
		}
		for(int s=1,sx=2,p=1;s<n;sx=(s=sx)<<1,++p)
			for(int i=0;i<n;i+=sx)
				for(int j=i,*wn=&w[p][0];j<i+s;++j){
					int x=a[j],y=1ll*a[j+s]*(*wn++)%MOD;
					a[j]=(x+y-MOD)+(((x+y-MOD)>>31)&MOD);
					a[j+s]=(x-y)+(((x-y)>>31)&MOD);
				}
		if(t==-1){
			reverse(a+1,a+n);
			for(int i=0;i<n;++i) a[i]=1ll*a[i]*inv[n]%MOD;
		}
	}
	inline void mul(int a[],int b[],int n){
		NTT(a,n,1); NTT(b,n,1);
		for(int i=0;i<n;++i) a[i]=1ll*a[i]*b[i]%MOD;
		NTT(a,n,-1);
	}
	inline void mul2(int a[],int b[],int c[],int n){
		static int x[N],y[N];
		memset(x+n,0,sizeof(int)*n);
		memset(y+n,0,sizeof(int)*n);
		memcpy(x,a,sizeof(int)*n);
		memcpy(y,b,sizeof(int)*n);
		mul(x,y,n+n);
		memset(c+n,0,sizeof(int)*n);
		memcpy(c,x,sizeof(int)*n);
	}
	inline void get_inv(int a[],int b[],int n){
		static int g[N];
		b[0]=fpow(a[0],MOD-2);
		for(int s=2;s<=n;s<<=1){
			for(int i=s>>1;i<s+s;++i) g[i]=b[i]=0;
			for(int i=0;i<s;++i) g[i]=a[i];
			NTT(b,s+s,1); NTT(g,s+s,1);
			for(int i=0;i<s+s;++i)
				b[i]=(2ll+MOD-1ll*g[i]*b[i]%MOD)*b[i]%MOD;
			NTT(b,s+s,-1);
		}
		for(int i=n;i<n+n;++i) b[i]=0;
	}
		inline void deri(int a[],int b[],int n){
		for(int i=0;i+1<n;++i) b[i]=1ll*a[i+1]*(i+1)%MOD; b[n-1]=0;
	}
	inline void inte(int a[],int b[],int n){
		for(int i=n-1;i>=1;--i) b[i]=1ll*inv[i]*a[i-1]%MOD; b[0]=0;
	}
	inline void shr(int a[],int b[],int n){
		for(int i=0;i+1<n;++i) b[i]=a[i+1]; b[n-1]=0;
	}
	inline void shl(int a[],int b[],int n){
		for(int i=n-1;i>=1;--i) b[i]=a[i-1]; b[0]=0;
	}
	inline void ln(int a[],int b[],int n){
		static int g[N];
		get_inv(a,g,n);
		deri(a,b,n);
		mul2(g,b,b,n);
		inte(b,b,n);
	}
	inline void exp(int a[],int b[],int n){
		static int g[N];
		b[0]=1;
		for(int s=2;s<=n;s<<=1){
			for(int i=s>>1;i<s+s;++i) g[i]=b[i]=0;
			ln(b,g,s);
			for(int i=0;i<s;++i) g[i]=mo2(a[i]-g[i]);
			mo(g[0]+=1);
			mul2(g,b,b,s);
		}
		for(int i=n;i<n+n;++i) b[i]=0;
	}
	void rev_mul(int a[],int b[],int c[],int n){
		static int x[N],y[N];
		memset(x+n,0,sizeof(int)*n);
		memcpy(x,a,sizeof(int)*n);
		memset(y+n,0,sizeof(int)*n);
		memcpy(y,b,sizeof(int)*n);
		reverse(y,y+n);
		mul(x,y,n+n);
		for(int i=0;i<n;++i) c[i]=x[i+n-1];
	}
}
int a[N],b[N],f[N],g[N];
int main(){
	int n; long long m; scanf("%d%lld",&n,&m);
	m%=MOD-1;
	for(int i=0;i<=n;++i){
		scanf("%d",&f[i]),f[i]=1ll*f[i]*fac[i]%MOD;
		g[i]=1ll*ifac[i]%MOD;
	}
	int top=1; for(;top<=n;top<<=1);
//	for(int i=0;i<top;++i) printf("[%d]",f[i]); puts("");
//	for(int i=0;i<top;++i) printf("{%d}",g[i]); puts("");
	POLY::rev_mul(f,g,g,top);
	for(int i=0;i<=n;++i){
//		printf("(%d)",g[i]);
		g[i]=fpow(inv[i+1],m,g[i]);
//		printf("[%d]",g[i]);
	}
	for(int i=0;i<=n;++i) f[i]=1ll*(i&1?MOD-1:1)*ifac[i]%MOD;
//	for(int i=0;i<top;++i) printf("<%d>",f[i]); puts("");
//	for(int i=0;i<top;++i) printf("<%d>",g[i]); puts("");
	POLY::rev_mul(g,f,f,top);
	for(int i=0;i<=n;++i) printf("%d ",int(1ll*f[i]*ifac[i]%MOD));
	return 0;
}