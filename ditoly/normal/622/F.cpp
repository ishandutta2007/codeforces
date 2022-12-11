#include<cstdio>
#define MOD 1000000007
int pw(int x,int y)
{
	int r=1;
	for(;y;y>>=1,x=1LL*x*x%MOD)if(y&1)r=1LL*r*x%MOD;
	return r;
}
#define MK 1000000
int z[MK+5];
inline int mod(int a){return a>=MOD?a-MOD:a;}
int main()
{
	int n,k,i,ans=0,s0=1,s1=1;
	scanf("%d%d",&n,&k);
	for(i=0;i++<=k;)z[i]=mod(z[i-1]+pw(i,k));
	if(n<=++k)return printf("%d",z[n]),0;
	for(i=0;i<=k;++i)s0=1LL*s0*(n-i)%MOD;
	for(i=1;i<=k;++i)s1=1LL*s1*(MOD-i)%MOD;
	for(i=0;i<=k;++i)
		ans=(ans+1LL*z[i]*s0%MOD*pw(n-i,MOD-2)%MOD*pw(s1,MOD-2))%MOD,
		s1=1LL*s1*pw(MOD-k+i,MOD-2)%MOD*(i+1)%MOD;
	printf("%d",ans);
}