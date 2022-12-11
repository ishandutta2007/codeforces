#include<cstdio>
#define MN 200000
#define MOD 1000000007
char s[MN+5];
int f[MN+5],v[MN+5];
inline int inv(int x)
{
	int r=1,y=MOD-2;
	for(;y;y>>=1,x=1LL*x*x%MOD)if(y&1)r=1LL*r*x%MOD;
	return r; 
}
int main()
{
	int i,l,r,ans=0;
	scanf("%s",s);
	for(i=f[0]=1;i<=MN;++i)f[i]=1LL*f[i-1]*i%MOD;
	for(v[i=MN]=inv(f[MN]);i--;)v[i]=1LL*v[i+1]*(i+1)%MOD;
	for(i=l=r=0;s[i];++i)if(s[i]==')')++r;
	for(i=0;r;++i)s[i]=='('?(ans=(ans+1LL*f[l+r]*v[l+1]%MOD*v[r-1])%MOD,++l):--r;
	printf("%d",ans);
}