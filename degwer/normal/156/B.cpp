#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int dat[100000][2];
bool flag[100000];
typedef pair<int,int>pii;
int main()
{
	int num,gen;
	scanf("%d%d",&num,&gen);
	vector<pii>vec;
	int sum=0;
	for(int i=0;i<num;i++)
	{
		char za;
		int zb;
		scanf(" %c%d",&za,&zb);
		if(za=='+')
		{
			vec.push_back(make_pair(0,zb-1));
			dat[zb-1][0]++;
		}
		else
		{
			vec.push_back(make_pair(1,zb-1));
			dat[zb-1][1]++;
			sum++;
		}
	}
	fill(flag,flag+100000,false);
	int numtrue=0;
	for(int i=0;i<num;i++)
	{
		if(gen==sum+dat[i][0]-dat[i][1])
		{
			flag[i]=true;
			numtrue++;
		}
	}
	for(int i=0;i<num;i++)
	{
		if(vec[i].first==0)
		{
			if(flag[vec[i].second])
			{
				if(numtrue>1)
				{
					printf("Not defined\n");
				}
				else
				{
					printf("Truth\n");
				}
			}
			else
			{
				printf("Lie\n");
			}
		}
		else
		{
			if(flag[vec[i].second])
			{
				if(numtrue>1)
				{
					printf("Not defined\n");
				}
				else
				{
					printf("Lie\n");
				}
			}
			else
			{
				printf("Truth\n");
			}
		}
	}
}