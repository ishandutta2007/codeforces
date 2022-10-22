#include<cstdio>
typedef long long ll;
const int N=20,M=1e9+7;
inline int Mod(int a){return a<M?a:a-M;}
int n,invf[N],f[N],s,c;ll m,a[N],l;
inline int Pow(int a,int m){int s=1;for(;m;m>>=1)m&1?s=1ll*s*a%M:0,a=1ll*a*a%M;return s;}
inline void InC(){
	f[0]=1;
	for(int i=1;i<n;i++)f[i]=1ll*f[i-1]*i%M;
	invf[n-1]=Pow(f[n-1],M-2);
	for(int i=n-1;i;i--)invf[i-1]=1ll*invf[i]*i;
}
int C(ll n,int m){
	if(m>n||m<0)return 0;
	n%=M;
	if(m>n)return 0;
	int s=invf[m];
	for(int i=0;i<m;i++)s=1ll*s*(n-i)%M;
	return s;
}
int main()
{
	scanf("%d%I64d",&n,&m);
	InC();
	for(int i=0;i<n;i++)scanf("%I64d",a+i);
	for(int I=0;I<(1<<n);I++){
	  c=0;l=m;
	  for(int i=0;i<n;i++)
		if(I&1<<i)c++,l-=a[i]+1;
	  s=c&1?Mod(s-C(l+n-1,n-1)+M):Mod(s+C(l+n-1,n-1));
	}printf("%d",s);
	return 0;
}