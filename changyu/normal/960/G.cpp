#include<bits/stdc++.h>
typedef long long ll;
const int M=998244353,K=18,G=3;
inline int Mod(int a){return a<M?a:a-M;}
inline int Pow(int a,int m){int s=1;for(;m;m>>=1)m&1?s=(ll)s*a%M:0,a=(ll)a*a%M;return s;}
namespace poly{
	int rev[1<<K],inv,s[1<<K];
	inline void Init(){
		for(int i=0;i<(1<<K);i++)rev[i]=rev[i>>1]>>1|(i&1)*(1<<K-1);
		inv=Pow(1<<K,M-2);
		s[0]=1,s[1]=Pow(G,M-1>>K);
		for(int i=2;i<(1<<K);i++)
		  s[i]=(ll)s[i-1]*s[1]%M;
	}
	inline void Ntt(int*a,int f){
		int tmp,tmp1,p,d;
		for(int i=0;i<(1<<K);i++)if(i<rev[i])std::swap(a[i],a[rev[i]]);
		for(int k=1;k<(1<<K);k<<=1){
		  d=f>0?(1<<K-1)/k:-(1<<K-1)/k;
		  for(int i=0;i<(1<<K);i+=k+k){
			p=0;
			for(int j=0;j<k;j++,p=p+d&(1<<K)-1){
			  tmp=a[i+j],tmp1=(ll)a[i+k+j]*s[p]%M;
			  a[i+j]=Mod(tmp+tmp1),a[i+k+j]=Mod(tmp-tmp1+M); 
			} 
		  }
		}
		if(f<0)for(int i=0;i<(1<<K);i++)a[i]=(ll)a[i]*inv%M;
	}
	inline void Pow(int*c,int*a,int m){
		for(int i=0;i<(1<<K);i++)c[i]=0;
		c[0]=1;
		for(;m;m>>=1){
		  Ntt(a,1);
		  if(m&1){
			Ntt(c,1);
			for(int i=0;i<(1<<K);i++)c[i]=(ll)c[i]*a[i]%M;
			Ntt(c,-1);
			memset(c+(1<<K-1),0,sizeof(int)*(1<<K-1));
		  }
		  for(int i=0;i<(1<<K);i++)a[i]=(ll)a[i]*a[i]%M;
		  Ntt(a,-1);
		  memset(a+(1<<K-1),0,sizeof(int)*(1<<K-1));
		}
	}
}
int n,l,r,a[1<<K],b[1<<K],c[1<<K],f[1<<K],invf[1<<K],ans;
inline int C(int n,int m){return(ll)f[n]*invf[m]%M*invf[n-m]%M;}
int main(){
	scanf("%d%d%d",&n,&l,&r);
	if(!l||!r)return 0*puts("0");
	f[0]=1;
	for(int i=1;i<(1<<K);i++)f[i]=(ll)f[i-1]*i%M;
	invf[(1<<K)-1]=Pow(f[(1<<K)-1],M-2);
	for(int i=(1<<K)-1;i;i--)invf[i-1]=(ll)invf[i]*i%M;
	poly::Init();
	for(int i=1;i<=n;i++)a[i]=(ll)f[i-1]*invf[i]%M;
	poly::Pow(b,a,l-1);
	for(int i=1;i<=n;i++)a[i]=(ll)f[i-1]*invf[i]%M;
	poly::Pow(c,a,r-1);
	for(int i=0;i<n;i++)b[i]=(ll)b[i]*f[i]%M*invf[l-1]%M;
	for(int i=0;i<n;i++)c[i]=(ll)c[i]*f[i]%M*invf[r-1]%M;
	for(int i=0;i<n;i++)ans=(ans+(ll)C(n-1,i)*b[i]%M*c[n-1-i])%M;
	printf("%d\n",ans);
	return 0;
}