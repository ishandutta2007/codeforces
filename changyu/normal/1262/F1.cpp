#include<cstdio>
typedef long long ll;
const int N=2e5+3,M=998244353;
inline int Mod(int a){return a<M?a:a-M;}
int n,m,t,s,a[N],f[N],invf[N];
inline int Pow(int a,int m){int s=1;for(;m;m>>=1)m&1?s=(ll)s*a%M:0,a=(ll)a*a%M;return s;}
inline int C(int n,int m){return(ll)f[n]*invf[m]%M*invf[n-m]%M;}
inline int F(int n){return(ll)(Pow(2,n)-C(n,n/2)*(~n&1)+M)*Pow(2,M-2)%M;}
int main(){
	scanf("%d%d",&n,&m);
	f[0]=1;
	for(int i=1;i<=n;i++)f[i]=(ll)f[i-1]*i%M;
	invf[n]=Pow(f[n],M-2);
	for(int i=n;i;i--)invf[i-1]=(ll)invf[i]*i%M;
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++)t+=a[i]==a[i%n+1];
	for(int i=0;i<=n-t;i++)
	  s=(s+(ll)C(n-t,i)*Pow(m-2,i)%M*F(n-t-i))%M;
	s=(ll)s*Pow(m,t)%M;
	printf("%d",s);
	return 0;
}