#include<cstdio>
typedef unsigned long long ll;
typedef long double llf;
const int K=19,M0=998244353,M1=1004535809,MM0=332747959,MM1=669690699,G=3;
const int N=1<<K;
const ll M=(ll)M0*M1;
int n,d,a[N],b[N],c[N],s[N],t[N],rev[N];ll ans[N];
inline int Mod(int a,int M){return a<M?a:a-M;}
inline ll Mult(ll a,ll b){
	ll res=a*b-(ll)((llf)a/M*b)*M;
	for(;res>=M;)res-=M;
	return res;
}
inline int Pow(int a,int m,int M){int s=1;for(;m;m>>=1)m&1?s=(ll)s*a%M:0,a=(ll)a*a%M;return s;}
inline void Init(){for(int i=0;i<N;i++)rev[i]=rev[i>>1]>>1|(i&1)*(1<<K-1);}
inline void Ntt(int*a,int f,int M){
	int tmp,tmp1,s,w;
	for(int i=0;i<N;i++)if(i<rev[i])
	  tmp=a[i],a[i]=a[rev[i]],a[rev[i]]=tmp;
	for(int k=1;k<N;k<<=1){
	  w=Pow(G,f>0?M/2/k:M-1-M/2/k,M);
	  for(int i=0;i<N;i+=k+k){
		s=1;
		for(int j=0;j<k;j++,s=(ll)s*w%M){
		  tmp=a[i+j],tmp1=(ll)a[i+k+j]*s%M;
		  a[i+j]=Mod(tmp+tmp1,M),a[i+k+j]=Mod(tmp-tmp1+M,M);
		}
	  }
	}
	if(f<0){
	  tmp=Pow(N,M-2,M);
	  for(int i=0;i<N;i++)a[i]=(ll)a[i]*tmp%M;
	}
}
inline void Mult(int*c,int*a,int*b,int M){
	Ntt(a,1,M),Ntt(b,1,M);
	for(int i=0;i<N;i++)c[i]=(ll)a[i]*b[i]%M;
	Ntt(a,-1,M),Ntt(b,-1,M),Ntt(c,-1,M);
}
int main(){
	int x; 
	scanf("%d%d",&n,&d);
	++b[0];
	for(int i=1;i<=n;i++)scanf("%d",a+i),++b[a[i]=(a[i]<d)+a[i-1]];
	for(int i=0;i<=n;i++)c[i]=b[n-i];
	Init();
	Mult(s,b,c,M0),Mult(t,b,c,M1);
	ans[0]=(ll)n*(n+1)/2;
	for(int i=1;i<=n;i++){
	  ans[i]=(Mult(s[n+i],(ll)M1*MM0)+Mult(t[n+i],(ll)M0*MM1))%M;
	  ans[0]-=ans[i];
	}
	for(int i=0;i<=n;i++)printf("%llu ",ans[i]);puts("");
	return 0;
}