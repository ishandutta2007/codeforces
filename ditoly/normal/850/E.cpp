#include<cstdio>
#define ll long long
#define r register int
#define MN (1<<20)
#define MOD 1000000007
char s[MN+5];
int n,ans,f[MN+5];
ll a[MN+5];
inline int mod(int x){return x<MOD?x:x-MOD;}
void fwt(int v)
{
	for(r i=0;i<n;++i)for(r j=0,x;j<1<<n;++j)if(x=j^(1<<i),j&(1<<i))
		a[x]=a[x]+a[j],a[j]=(a[x]-a[j]-a[j])/(v?2:1),a[x]/=v?2:1;
}
int main()
{
	scanf("%d%s",&n,s);
	for(r i=0;i<1<<n;++i)a[i]=s[i]-'0';fwt(0);
	for(r i=0;i<1<<n;++i)a[i]*=a[i];fwt(1);
	for(r i=f[0]=1;i<1<<n;++i)f[i]=mod(f[i>>1]<<(i&1));
	for(r i=0;i<1<<n;++i)ans=(ans+1LL*a[i]*f[i^((1<<n)-1)])%MOD;
	printf("%d",3LL*ans%MOD);
}