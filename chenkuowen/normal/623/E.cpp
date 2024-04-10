#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int MAX_N=1<<17|5,MOD=1e9+7;
namespace POLY{
	const ld pi=acos(-1);
	struct C{ 
		ld x,y;
		inline C operator+(C b){ return (C){x+b.x,y+b.y}; }
		inline C operator-(C b){ return (C){x-b.x,y-b.y}; }
		inline C operator*(C b){ return (C){x*b.x-y*b.y,x*b.y+y*b.x}; }
		inline C operator!(){ return (C){x,-y}; }
	};
	vector<C> w[23];
	struct Init{
		Init(){
			for(int l=1;l<=20;++l){
				int len=1<<l-1;
				w[l].resize(len); w[l][0]=(C){1,0};
				C wn=(C){cos(pi/len),sin(pi/len)};
				for(int i=1;i<len;++i)
					w[l][i]=w[l][i-1]*wn;
			}
		}
	}__init;
	inline void FFT(C a[],int n,int t){
		for(int i=0,pos=0;i<n;++i){
			if(i<pos) swap(a[i],a[pos]);
			for(int p=n>>1;(pos^=p)<p;p>>=1);
		}
		for(int s=1,sx=2,p=1;s<n;sx=(s=sx)<<1,++p)
			for(int i=0;i<n;i+=sx)
				for(int j=i;j<i+s;++j){
					C x=a[j],y=a[j+s]*w[p][j-i];
					a[j]=x+y; a[j+s]=x-y;
				}
		if(t==-1){
			reverse(a+1,a+n);
			for(int i=0;i<n;++i) a[i]=a[i]*(C){1.0/n,0};
		}
	}
	void mul(int x[],int y[],int z[],int n){
		static C a[MAX_N],b[MAX_N],c[MAX_N],d[MAX_N];
		int m=sqrt(MOD);
		for(int i=0;i<n;++i){
			a[i].x=x[i]/m; a[i].y=x[i]%m;
			c[i].x=y[i]/m; c[i].y=y[i]%m;
		}
		FFT(a,n,1); FFT(c,n,1);
		for(int i=0;i<n;++i){
			int j=i==0?0:n-i;
			b[i]=(a[i]-!a[j])*(C){0,-0.5};
			d[i]=(c[i]-!c[j])*(C){0,-0.5};
		}
		for(int i=0;i<n;++i){
			b[i]=b[i]*d[i];
			a[i]=a[i]*c[i]+b[i];
		}
		FFT(a,n,-1); FFT(b,n,-1);
		for(int i=0;i<n;++i){
			z[i]=((ll)(a[i].x+0.5)%MOD*m%MOD*m
				+(ll)(a[i].y+0.5)%MOD*m+(ll)(b[i].x+0.5)%MOD)%MOD;
			if(z[i]<0) z[i]+=MOD;
		}
	}
}
int g[MAX_N],f[MAX_N];
int inv[MAX_N],fac_inv[MAX_N],fac[MAX_N];
int c(int n,int m){
	if(n<0||m<0||m>n) return 0;
	return 1ll*fac[n]*fac_inv[n-m]%MOD*fac_inv[m]%MOD;
}
inline int fpow(int x,int n,int ret=1){
	for(;n;n>>=1,x=1ll*x*x%MOD)
		n&1?ret=1ll*ret*x%MOD:0;
	return ret;
}
void mul(int f[],int g[],int h[],int n,int sz){
	static int a[MAX_N],b[MAX_N];
	for(int j=0;j<n;++j){
		a[j]=1ll*g[j]*fac_inv[j]%MOD*fpow(2,1ll*sz*j%(MOD-1))%MOD;
		b[j]=1ll*h[j]*fac_inv[j]%MOD;
		a[j+n]=0; b[j+n]=0;
	}
	POLY::mul(a,b,f,n+n);
	for(int i=0;i<n;++i){
		f[i]=1ll*f[i]*fac[i]%MOD;
		f[i+n]=0;
	}
}
void init(int n){
	fac[0]=fac_inv[0]=inv[1]=1; 
	for(int i=1;i<=n;++i){
		fac[i]=1ll*fac[i-1]*i%MOD;
		if(i>1) inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
		fac_inv[i]=1ll*fac_inv[i-1]*inv[i]%MOD;
	}
}
int main(){
	ll n; int k; scanf("%lld%d",&n,&k);
	int top=1; for(;top<=k;top<<=1);
	init(top);
	if(n>k+1){
		puts("0");
		return 0;
	}
	for(int i=1;i<top;++i) g[i]=1;
	f[0]=1;
	for(int p=1;p<=n;p<<=1,mul(g,g,g,top,p>>1))
		if(n&p)
			mul(f,f,g,top,p);
	int ans=0;
	for(int i=0;i<=k;++i){
		ans=(ans+1ll*c(k,i)*f[i])%MOD;
	}
	printf("%d\n",ans);
	return 0;
}