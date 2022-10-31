#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll com[101][101];
void calccom()
{
	com[0][0]=1;
	for(int i=1;i<=100;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(j==0)
			{
				com[i][j]=1;
			}
			else
			{
				if(j==i)
				{
					com[i][j]=1;
				}
				else
				{
					com[i][j]=com[i-1][j]+com[i-1][j-1];
				}
			}
		}
	}
}
int main()
{
	calccom();
	ll gen,ko;
	scanf("%I64d%I64d",&gen,&ko);
	ll now=1;
	int nn=-1;
	for(int i=0;;i++)
	{
		if(ko==now)
		{
			nn=i;
			break;
		}
		if(ko<now)
		{
			break;
		}
		now*=2;
	}
	if(nn==-1)
	{
		printf("0\n");
		return 0;
	}
	ll ans=0;
	now=0;
	ll pl=1;
	int pt;
	for(pt=0;;pt++)
	{
		if(now+pl<=gen+1)
		{
			ans+=com[pt][nn];
			now+=pl;
		}
		else
		{
			break;
		}
		pl*=2;
	}
	for(;pt>=0;pt--)
	{
		if(nn<0)
		{
			break;
		}
		if(now+pl<=gen+1)
		{
			ans+=com[pt][nn];
			now+=pl;
			nn--;
		}
		pl/=2;
	}
	if(ko==1)
	{
		ans--;
	}
	printf("%I64d\n",ans);
}