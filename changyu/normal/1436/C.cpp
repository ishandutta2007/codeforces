#include<cstdio>
typedef long long ll;
const int M=1e9+7,N=1003;
int n,p,x,c0,c1,f[N],invf[N];
inline int Pow(int a,int m){int s=1;for(;m;m>>=1)m&1?s=(ll)s*a%M:0,a=(ll)a*a%M;return s;}
inline int A(int n,int m){return m<0||m>n?0:(ll)f[n]*invf[n-m]%M;}
int main(){
	scanf("%d%d%d",&n,&x,&p);
	f[0]=1;
	for(int i=1;i<=n;i++)f[i]=(ll)f[i-1]*i%M;
	invf[n]=Pow(f[n],M-2);
	for(int i=n;i;i--)invf[i-1]=(ll)invf[i]*i%M;
	int l=0,r=n,m;
	for(;l<r;){
	  m=l+r>>1;
	  if(m<=p)m!=p&&(++c0),l=m+1;
	  else ++c1,r=m;
	}
	printf("%lld\n",(ll)A(x-1,c0)*A(n-x,c1)%M*f[n-1-c0-c1]%M);
	return 0;
}