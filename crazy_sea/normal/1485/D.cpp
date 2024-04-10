#include<cstdio>
using namespace std;
const int p=720720;
int n,m,a;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a);
			if((i+j)&1) a=p;
			else a=a*a*a*a+p;
			printf("%d ",a);
		}
		printf("\n");
	}
	return 0;
}