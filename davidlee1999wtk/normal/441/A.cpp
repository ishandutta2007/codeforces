#include<cstdio>
using namespace std;
int ans[100];
int num;
int cnt,n,sum,i,p,j;
int main()
{
	cnt=0;
	scanf("%d%d",&n,&sum);
	for(i=1;i<=n;i++)
	{
		int ok=0;
		scanf("%d",&p);
		for(j=1;j<=p;j++)
		{
			scanf("%d",&num);
			if(num<sum)
				ok=1;
		}
		if(ok)
		{
			ans[cnt]=i;
			cnt++;
		}
	}
	printf("%d\n",cnt);
	for(i=0;i<cnt;i++)
		printf("%d ",ans[i]);
	return 0;
}