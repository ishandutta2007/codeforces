#include<cstdio>
#include<algorithm>
using namespace std;
int T,n,k;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		if(k==1)
		{
			printf("Yes\n");
			for(int i=1;i<=n;i++)
				printf("%d\n",i);
			continue;
		}
		if(n&1) printf("No\n");
		else
		{
			printf("Yes\n");
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=k;j++)
					printf("%d ",i+(j-1)*n);
				printf("\n");
			}
		}
	}
}