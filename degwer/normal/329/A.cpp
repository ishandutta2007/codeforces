#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int map[100][100];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			char zan;
			scanf(" %c",&zan);
			if(zan=='E')
			{
				map[i][j]=1;
			}
			else
			{
				map[i][j]=0;
			}
		}
	}
	vector<int>x;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(map[i][j]==0)
			{
				x.push_back(j);
				break;
			}
		}
	}
	vector<int>y;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(map[j][i]==0)
			{
				y.push_back(j);
				break;
			}
		}
	}
	if(x.size()==n)
	{
		for(int i=0;i<n;i++)
		{
			printf("%d %d\n",i+1,x[i]+1);
		}
		return 0;
	}
	if(y.size()==n)
	{
		for(int i=0;i<n;i++)
		{
			printf("%d %d\n",y[i]+1,i+1);
		}
		return 0;
	}
	printf("-1\n");
}