#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int dat[35][150][150];
int now[150];
int nn[150];
bool flag[150];
typedef pair<int,int>pii;
typedef pair<int,pii>pi3;
int main()
{
	int num,way;
	scanf("%d%d",&num,&way);
	vector<pi3>vec;
	for(int i=0;i<way;i++)
	{
		int za,zb,zc;
		scanf("%d%d%d",&za,&zb,&zc);
		za--;
		zb--;
		vec.push_back(make_pair(zc,make_pair(za,zb)));
	}
	sort(vec.begin(),vec.end());
	now[0]=1;
	int cur=0;
	for(int i=0;i<way;i++)
	{
		if(cur!=vec[i].first)
		{
			int t=vec[i].first-cur;
			for(int j=0;j<=30;j++)
			{
				if((t&(1<<j))!=0)
				{
					fill(nn,nn+num,0);
					for(int k=0;k<num;k++)
					{
						for(int l=0;l<num;l++)
						{
							nn[l]|=now[k]&dat[j][k][l];
						}
					}
					for(int k=0;k<num;k++)now[k]=nn[k];
				}
			}
			cur=vec[i].first;
		}
		//printf("dgdg%d\n",i);
		//for(int j=0;j<num;j++)printf("%d ",now[j]);printf("\n");
		vector<pii>ne;
		if(dat[0][vec[i].second.first][vec[i].second.second]==0)
		{
			ne.push_back(vec[i].second);
			dat[0][vec[i].second.first][vec[i].second.second]=1;
		}
		for(int j=1;j<=30;j++)
		{
			vector<pii>nne;
			for(int k=0;k<ne.size();k++)
			{
				for(int l=0;l<num;l++)
				{
					if(dat[j][ne[k].first][l]==0)
					{
						if(dat[j-1][ne[k].second][l]==1)
						{
							nne.push_back(make_pair(ne[k].first,l));
							dat[j][ne[k].first][l]=1;
						}
					}
					if(dat[j][l][ne[k].second]==0)
					{
						if(dat[j-1][l][ne[k].first]==1)
						{
							nne.push_back(make_pair(l,ne[k].second));
							dat[j][l][ne[k].second]=1;
						}
					}
				}
			}
			ne=nne;
		}/*
		for(int j=0;j<=3;j++)
		{
			printf("%d %d\n",i,j);
			for(int k=0;k<num;k++)
			{
				for(int l=0;l<num;l++)
				{
					printf("%d ",dat[j][k][l]);
				}
				printf("\n");
			}
		}*/
		queue<pii>que;
		for(int j=0;j<num;j++)if(now[j]==1)que.push(make_pair(vec[i].first,j));
		fill(flag,flag+num,false);
		for(;;)
		{
			if(que.empty())break;
			pii zan=que.front();
			que.pop();
			if(flag[zan.second])continue;
			flag[zan.second]=true;
			if(zan.second==num-1)
			{
				printf("%d\n",zan.first);
				return 0;
			}
			for(int j=0;j<=i;j++)
			{
				if(vec[j].second.first==zan.second)que.push(make_pair(zan.first+1,vec[j].second.second));
			}
		}
	}
	printf("Impossible\n");
}