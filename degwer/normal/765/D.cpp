#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int dat[100000];
int g[100000];
int h[100000];
int main()
{
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)scanf("%d",&dat[i]),dat[i]--;
	int pt=0;
	for(int i=0;i<num;i++)
	{
		if(dat[i]==i)
		{
			h[pt]=i;
			g[i]=pt;
			pt++;
		}
	}
	if(pt==0)
	{
		printf("-1\n");
		return 0;
	}
	for(int i=0;i<num;i++)
	{
		if(dat[i]!=i)
		{
			if(dat[dat[i]]==dat[i])
			{
				g[i]=g[dat[i]];
			}
			else
			{
				printf("-1\n");
				return 0;
			}
		}
	}
	printf("%d\n",pt);
	for(int i=0;i<num;i++)printf("%d ",g[i]+1);printf("\n");
	for(int i=0;i<pt;i++)printf("%d ",h[i]+1);printf("\n");
}