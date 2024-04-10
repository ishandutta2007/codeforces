#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7,N=1<<20|5;
inline int mo1(int x){ return x>=MOD?x-MOD:x; }
inline void mo(int& x){ x>=MOD?x-=MOD:0; }
inline int fpow(int x,int n,int ret=1){
	for(;n;n>>=1,x=1ll*x*x%MOD)
		if(n&1) ret=1ll*ret*x%MOD;
	return ret;
}
int inv[N],fac[N],ifac[N];
inline int comb(int n,int m){
	if(n<m||n<0||m<0) return 0;
	return 1ll*fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;
}
struct II{
	II(){
		inv[1]=fac[0]=ifac[0]=1;
		for(int i=1;i<N;++i){
			fac[i]=1ll*fac[i-1]*i%MOD;
			if(i>1) inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
			ifac[i]=1ll*ifac[i-1]*inv[i]%MOD;
		}
	}
}__ii;
namespace POLY{
	vector<int> w[23];
	struct II{
		II(){
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
					a[j]=x+y>=MOD?x+y-MOD:x+y;
					a[j+s]=x-y<0?x-y+MOD:x-y;
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
		memcpy(x,a,sizeof(int)*n);
		memset(x+n,0,sizeof(int)*n);
		memcpy(y,b,sizeof(int)*n);
		memset(y+n,0,sizeof(int)*n);
		mul(x,y,n+n);
		memcpy(c,x,sizeof(int)*n);
		memset(c+n,0,sizeof(int)*n);
	}
	inline void get_inv(int a[],int b[],int n){
		static int g[N]; b[0]=fpow(a[0],MOD-2);
		for(int s=2;s<=n;s<<=1){
			for(int i=s>>1;i<s+s;++i) b[i]=g[i]=0;
			for(int i=0;i<s;++i) g[i]=a[i];
			NTT(b,s+s,1); NTT(g,s+s,1);
			for(int i=0;i<s+s;++i)
				b[i]=(2ll+MOD-1ll*b[i]*g[i]%MOD)*b[i]%MOD;
			NTT(b,s+s,-1);
		}
		for(int i=n;i<n+n;++i) b[i]=0;
	}
	inline void deri(int a[],int b[],int n){
		for(int i=0;i+1<n;++i) b[i]=1ll*(i+1)*a[i+1]%MOD; b[n-1]=0;
	}
	inline void inte(int a[],int b[],int n){
		for(int i=n-1;i>=1;--i) b[i]=1ll*inv[i]*a[i-1]%MOD; b[0]=0; 
	}
	inline void ln(int a[],int b[],int n){
		static int g[N];
		get_inv(a,g,n);
		deri(a,b,n);
		mul2(b,g,b,n);
		inte(b,b,n);
	}
	inline void exp(int a[],int b[],int n){
		static int g[N]; b[0]=1;
		for(int s=2;s<=n;s<<=1){
			for(int i=s>>1;i<s+s;++i) b[i]=g[i]=0;
			ln(b,g,s);
			for(int i=0;i<s;++i) g[i]=mo1(a[i]+MOD-g[i]);
			mo(g[0]+=1);
			mul2(b,g,b,s);
		}
		for(int i=n;i<n+n;++i) b[i]=0;
	}
}
int stir2[N],a[N],b[N];
int main(){
	int n,k,sum=0; scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		int x; scanf("%d",&x);
		mo(sum+=x);
	}
	--k;
	int ans=0;
	for(int t=0;t<=k;++t){
		int key=1ll*ifac[t]*ifac[k-t]%MOD*(k-t&1?MOD-1:1)%MOD*(1ll*fpow(1+t,n-1)%MOD+(n>1?1ll*(n-1)%MOD*fpow(1+t,n-2)%MOD:0))%MOD;
		mo(ans+=key);
	}
	ans=1ll*ans*sum%MOD;
	printf("%d\n",ans);
	return 0;
}