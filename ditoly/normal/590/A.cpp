#include<cstdio>
#include<algorithm>
using namespace std;
#define MN 500000
int a[MN+5];
int main()
{
	int n,i,j,k,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(i=2;i<n;++i)if(a[i]!=a[i-1])
	{
		for(j=i;j<n;++j)if(a[j]==a[j+1])break;
		if((j-i)&1)for(k=i;k<j;++k)a[k]=a[j];
		else for(k=0;i+k<j-1-k;++k)a[i+k]=a[i-1],a[j-1-k]=a[j];
		ans=max(ans,j-i+1>>1);i=j;
	}
	printf("%d\n",ans);
	for(i=1;i<=n;++i)printf("%d ",a[i]);
}