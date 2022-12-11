#include<cstdio>
#define ll long long
#define MN 100000
int f[MN+5];
int gf(int k){return f[k]?f[k]=gf(f[k]):k;}
int main()
{
	int n,i,j,k,cnt=1;ll ans=0;
	scanf("%d",&n);
	for(i=0;cnt<n;++i)for(j=1;cnt<n&&j<=n;++j)
	{
		k=(i-j+n+1)%(n+1);
		if(k&&gf(j)!=gf(k))ans+=i,++cnt,f[gf(j)]=gf(k);
	}
	printf("%I64d",ans);
}