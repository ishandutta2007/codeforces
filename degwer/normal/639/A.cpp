#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int d[10];
int dat[150000];
int main()
{
	int num,gen,query;
	scanf("%d%d%d",&num,&gen,&query);
	for(int i=0;i<num;i++)scanf("%d",&dat[i]);
	for(int i=0;i<query;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		zb--;
		if(za==1)
		{
			int now=dat[zb];
			for(int i=0;i<gen;i++)
			{
				if(now>d[i])swap(now,d[i]);
			}
		}
		else
		{
			bool f=false;
			for(int i=0;i<gen;i++)
			{
				if(d[i]==dat[zb])f=true;
			}
			if(f)printf("YES\n");
			else printf("NO\n");
		}
	}
}