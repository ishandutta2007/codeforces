#include<cstdio>
#include<algorithm>
using namespace std;
int T,a[105],n,k,sum[105];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int res=0;
		for(int i=1;i<n;i++)
		{
			int tmp=min(k,a[i]);
			a[i]-=tmp;
			k-=tmp;
			res+=tmp;
		}
		a[n]+=res;
		for(int i=1;i<n;i++)printf("%d ",a[i]);
		printf("%d\n",a[n]);
	}
	return 0;
}