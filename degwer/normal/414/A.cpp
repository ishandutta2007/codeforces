#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(a==1)
	{
		if(b==0)
		{
			printf("1\n");
		}
		else
		{
			printf("-1\n");
		}
	}
	else
	{
		if(b<a/2)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d %d",b-a/2+1,2*(b-a/2+1));
			for(int i=2;i<a;i++)
			{
				printf(" %d",3*b+i);
			}
			printf("\n");
		}
	}
}