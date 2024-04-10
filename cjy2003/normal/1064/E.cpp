#include<stdio.h>
#include<string.h>
int n,l,r,mid;
char col[10];
bool bj;
int main()
{
	r=536870912;
	scanf("%d",&n);
	printf("0 1\n");
	fflush(stdout);
	scanf("%s",col);
	if(col[0]=='b')bj=1;
	for(int i=1;i<n;++i)
	{
		if(i==29)
		{
			printf("%d 100000000\n",r);
			fflush(stdout);
			scanf("%s",col);
			if(col[0]=='b')
			{
				if(bj)printf("%d %d %d %d",l+r>>1,0,r+1,100000000);	
				else printf("%d %d %d %d",l+r>>1,0,r-1,100000000);	
			}
			else
			{
				if(bj)printf("%d %d %d %d",l+r>>1,0,r-1,100000000);	
				else printf("%d %d %d %d",l+r>>1,0,r+1,100000000);	
			}
			return 0;
		}
		mid=l+r>>1;
		printf("%d 1\n",mid);
		fflush(stdout);
		scanf("%s",col);
		if(col[0]=='b')
		{
			if(bj)l=mid;
			else r=mid;
		}
		else
		{
			if(bj)r=mid;
			else l=mid;
		}
	}
	printf("%d 0 %d 1",l+r>>1,l+r>>1);
	fflush(stdout);
	return 0;
}