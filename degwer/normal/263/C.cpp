#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int sam(vector<int>a,vector<int>b)
{
	int ret=0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(a[i]==b[j])
			{
				ret++;
			}
		}
	}
	return ret;
}
vector<int>pat[100000];
vector<int>rin[100000];
int main()
{
	int num;
	scanf("%d",&num);
	for(int i=0;i<num*2;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		za--;
		zb--;
		pat[za].push_back(zb);
		pat[zb].push_back(za);
	}
	for(int i=0;i<num;i++)
	{
		if(pat[i].size()!=4)
		{
			printf("-1\n");
			return 0;
		}
		if(sam(pat[i],pat[i])!=4)
		{
			printf("-1\n");
			return 0;
		}
	}
	if(num>=7)
	{
		for(int i=0;i<num;i++)
		{
			for(int j=0;j<4;j++)
			{
				if(sam(pat[i],pat[pat[i][j]])==2)
				{
					rin[i].push_back(pat[i][j]);
				}
			}
			if(rin[i].size()!=2)
			{
				printf("-1\n");
				return 0;
			}
		}
		vector<int>vec;
		int now=0;
		int pre=-1;
		for(;;)
		{
			vec.push_back(now);
			if(pre==rin[now][0])
			{
				pre=now;
				now=rin[now][1];
			}
			else
			{
				pre=now;
				now=rin[now][0];
			}
			if(now==0)
			{
				break;
			}
		}
		if(vec.size()!=num)
		{
			printf("-1\n");
			return 0;
		}
		for(int i=0;i<num;i++)
		{
			vector<int>d;
			d.push_back(vec[(i+num-2)%num]);
			d.push_back(vec[(i+num-1)%num]);
			d.push_back(vec[(i+num+1)%num]);
			d.push_back(vec[(i+num+2)%num]);
			if(sam(d,pat[vec[i]])!=4)
			{
				printf("-1\n");
				return 0;
			}
		}
		for(int i=0;i<num;i++)
		{
			if(i!=0)
			{
				printf(" ");
			}
			printf("%d",vec[i]+1);
		}
		printf("\n");
	}
	else
	{
		vector<int>vec;
		for(int i=0;i<num;i++)
		{
			vec.push_back(i);
		}
		for(;;)
		{
			bool han=true;
			for(int i=0;i<num;i++)
			{
				vector<int>d;
				d.push_back(vec[(i+num-2)%num]);
				d.push_back(vec[(i+num-1)%num]);
				d.push_back(vec[(i+num+1)%num]);
				d.push_back(vec[(i+num+2)%num]);
				//printf("%d %d %d %d  %d %d %d %d\n",pat[vec[i]][0],pat[vec[i]][1],pat[vec[i]][2],pat[vec[i]][3],d[0],d[1],d[2],d[3]);
				if(sam(d,pat[vec[i]])!=4)
				{
					han=false;
				}
			}
			if(han)
			{
				for(int i=0;i<num;i++)
				{
					if(i!=0)
					{
						printf(" ");
					}
					printf("%d",vec[i]+1);
				}
				printf("\n");
				return 0;
			}
			if(!next_permutation(vec.begin(),vec.end()))
			{
				break;
			}
		}
		printf("-1\n");
	}
}