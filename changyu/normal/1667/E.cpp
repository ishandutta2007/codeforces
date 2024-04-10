#include<cstdio>
#include<cstring>
typedef long long ll;
const int M=998244353,G=3;
inline int Mod(int a){return a<M?a:a-M;}
inline int Pow(int a,int m){int s=1;for(;m;m>>=1)m&1?s=(ll)s*a%M:0,a=(ll)a*a%M;return s;}
const int K=19;
const int N=1<<K;
int inv[N],invf[N],func[N];
namespace poly{
	int rev[N],s[N],invn,t0[N],t1[N],t2[N];
	inline void Init(int K){
		for(int i=0;i<(1<<K);i++)rev[i]=rev[i>>1]>>1|(i&1)<<K-1;
		s[0]=1,s[1]=Pow(G,M>>K);
		for(int i=2;i<(1<<K);i++)s[i]=(ll)s[i-1]*s[1]%M;
		invn=Pow(1<<K,M-2);
	}
	inline void Ntt(int*a,int f,int K){
		int tmp,d,p;
		for(int i=0;i<(1<<K);i++)if(i<rev[i])
		  tmp=a[i],a[i]=a[rev[i]],a[rev[i]]=tmp;
		for(int k=1,g=0;k<(1<<K);k<<=1,g++){
		  d=f>0?(1<<K-1-g):-(1<<K-1-g);
		  for(int i=0;i<(1<<K);i+=k+k){
			p=0;
			for(int j=0;j<k;j++,p=p+d&(1<<K)-1){
			  tmp=(ll)a[i|k|j]*s[p]%M;
			  (a[i|k|j]=a[i|j]-tmp)<0&&(a[i|k|j]+=M);
			  (a[i|j]+=tmp)>=M&&(a[i|j]-=M);
			}
		  }
		}
		if(f<0)for(int i=0;i<(1<<K);i++)a[i]=(ll)a[i]*invn%M;
	}
	inline void Inv(int*c,int*a,int K){
		memset(c,0,sizeof(int)*(1<<K));
		memset(t0,0,sizeof(int)*(1<<K));
		c[0]=1;//
		for(int j=1;j<K;j++){
		  Init(j+1);
		  memcpy(t0,a,sizeof(int)*(1<<j));
		  Ntt(t0,1,j+1),Ntt(c,1,j+1);
		  for(int i=0;i<(1<<j+1);i++)c[i]=c[i]*(2-(ll)t0[i]*c[i]%M+M)%M;
		  Ntt(c,-1,j+1);
		  memset(c+(1<<j),0,sizeof(int)*(1<<j));
		}
	}
	inline void Integ(int*a,int K){
		for(int i=(1<<K)-1;i;i--)
		  a[i]=(ll)a[i-1]*inv[i]%M;
		a[0]=0;
	}
	inline void Deriv(int*a,int K){
		for(int i=1;i<(1<<K);i++)
		  a[i-1]=(ll)a[i]*i%M;
		a[(1<<K)-1]=0;
	}
	inline void Ln(int*c,int*a,int K){
		memcpy(c,a,sizeof(int)*(1<<K));
		Inv(t1,a,K),Deriv(c,K);
		Ntt(t1,1,K),Ntt(c,1,K);
		for(int i=0;i<(1<<K);i++)c[i]=(ll)c[i]*t1[i]%M;
		Ntt(c,-1,K);
		Integ(c,K);
		memset(c+(1<<K-1),0,sizeof(int)*(1<<K-1));
	}
	inline void Exp(int*c,int*a,int K){
		memset(c,0,sizeof(int)*(1<<K));
		memset(t2,0,sizeof(int)*(1<<K));
		c[0]=1;
		for(int j=1;j<K;j++){
		  Ln(t2,c,j+1);
		  for(int i=0;i<(1<<j);i++)t2[i]=(t2[i]-a[i]+M)%M;
		  Ntt(t2,1,j+1),Ntt(c,1,j+1);
		  for(int i=0;i<(1<<j+1);i++)c[i]=(c[i]-(ll)t2[i]*c[i]%M+M)%M;
		  Ntt(c,-1,j+1);
		  memset(c+(1<<j),0,sizeof(int)*(1<<j));
		}
	}
	inline void Mult(int*c,int*a,int K){
		Init(K);
		Ntt(a,1,K),Ntt(c,1,K);
		for(int i=0;i<(1<<K);i++)c[i]=(ll)a[i]*c[i]%M;
		Ntt(c,-1,K);
	}
}
int n,a[N],b[N],res[N];
int main(){
	func[0]=1;
	for(int i=1;i<N;i++)func[i]=(ll)func[i-1]*i%M;
	invf[N-1]=Pow(func[N-1],M-2);
	for(int i=N-1;i;i--){
	  invf[i-1]=(ll)invf[i]*i%M;
	  inv[i]=(ll)invf[i]*func[i-1]%M;
	}
	scanf("%d",&n);
	for(int i=1;i<=n/2;i++)a[i]=inv[i];
	poly::Exp(b,a,K);
	printf("%lld ",(ll)b[n-1]*func[n-1]%M);
	for(int i=0;i+1<n;i++)b[i]=i<n/2?0:(ll)b[i]*func[n-i-2]%M;//,printf("%d %lld\n",i,(ll)b[i]*func[i]%M);
	for(int i=0;i<n;i++)res[i]=invf[i];
	poly::Mult(res,b,K);
	for(int i=2;i<=n;i++)printf("%lld ",(ll)res[n-i]*func[n-i]%M*(i-1)%M);puts("");
	return 0;
}