#include<cstdio>
#include<algorithm>
using namespace std;
#define MN 22
#define MM 200000
char s[MN+1][MM+5];
int n;long long a[1<<MN],b[1<<MN];
void fwt(long long*f,int v)
{
	for(int i=0;i<n;++i)for(int j=0;j<1<<n;++j)if(j&(1<<i))
		f[j^(1<<i)]+=f[j],f[j]=f[j^(1<<i)]-(f[j]<<1),v?(f[j^(1<<i)]>>=1,f[j]>>=1):0;
}
int main()
{
	int m,i,j,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%s",s[i]+1);
	for(i=1;i<=m;++a[k],++i)for(k=0,j=1;j<=n;++j)k=(k<<1)+s[j][i]-'0';
	for(i=0;i<1<<n;++i)b[i]=b[i>>1]+(i&1);
	for(i=0;i<1<<n;++i)b[i]=min(b[i],n-b[i]);
	fwt(a,0);fwt(b,0);
	for(i=0;i<1<<n;++i)a[i]*=b[i];
	fwt(a,1);
	for(k=n*m,i=0;i<1<<n;++i)k=min(k,(int)a[i]);
	printf("%d",k);
}