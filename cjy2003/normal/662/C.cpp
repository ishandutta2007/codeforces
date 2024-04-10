#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[20][100010];
int n,m,a[100010];
long long f[1<<20],g[1<<20];
void fwt(long long f[])
{
	for(int i=0;i<n;++i)
		for(int j=0;j<1<<n;++j)
			if(j>>i&1)
			{
				long long x=f[j^(1<<i)],y=f[j];
				f[j^(1<<i)]=x+y;f[j]=x-y;
			}
}
void ifwt(long long f[])
{
	for(int i=0;i<n;++i)
		for(int j=0;j<1<<n;++j)
			if(j>>i&1)
			{
				long long x=f[j^(1<<i)],y=f[j];
				f[j^(1<<i)]=(x+y)/2;f[j]=(x-y)/2;
			}
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;++i)scanf("%s",s[i]+1);
	for(int i=1;i<=m;++i)
	{
		for(int j=0;j<n;++j)a[i]|=(s[j][i]-'0')<<j;
		++g[a[i]];
	}
	for(int i=0;i<1<<n;++i)f[i]=min(__builtin_popcount(i),n-__builtin_popcount(i));
	fwt(f);fwt(g);
	for(int i=0;i<1<<n;++i)f[i]*=g[i];
	ifwt(f);
	int ans=0x3f3f3f3f;
	for(int i=0;i<1<<n;++i)ans=min(ans,(int)f[i]);
	printf("%d",ans);
	return 0;
}