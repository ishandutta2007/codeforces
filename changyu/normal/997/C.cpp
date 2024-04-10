#include<cstdio>
typedef long long ll;
const int M=998244353,A=1e6+3,INV3=332748118;
inline int Pow(int a,ll m){int s=1;for(;m;m>>=1)m&1?s=(ll)s*a%M:0,a=(ll)a*a%M;return s;}
int n,s,t,f[A],invf[A];
inline int C(int n,int m){return(ll)f[n]*invf[m]%M*invf[n-m]%M;}
signed main(){
	f[0]=1;
	for(int i=1;i<A;i++)f[i]=(ll)f[i-1]*i%M;
	invf[A-1]=Pow(f[A-1],M-2);
	for(int i=A-1;i;i--)invf[i-1]=(ll)invf[i]*i%M;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  s=(s+(ll)(i&1?1:M-1)*C(n,i)%M*Pow(3,((ll)n*(n-i)+i)))%M;
	s=s*2%M;
	for(int i=1;i<=n;i++)
	  t=(t+(ll)Pow(M-Pow(INV3,n),i)*C(n,i)%M*(Pow(-Pow(INV3,n-i)+1+M,n)-1+M))%M;
	t=(ll)t*Pow(3,(ll)n*n+1)%M;
	printf("%d",(s-t+M)%M);
	return 0;
}