#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define LIMIT 252
typedef pair<int,int>pii;
pii par[LIMIT][LIMIT];
int ran[LIMIT][LIMIT];
int ren[LIMIT][LIMIT];
pii upm[LIMIT][LIMIT];
void init()
{
	for(int i=0;i<LIMIT;i++)
	{
		for(int j=0;j<LIMIT;j++)
		{
			par[i][j]=make_pair(i,j);
			ran[i][j]=0;
			ren[i][j]=1;
			upm[i][j]=make_pair(i,j);
		}
	}
}
pii find(pii a)
{
	if(par[a.first][a.second]==a)
	{
		return a;
	}
	else
	{
		return par[a.first][a.second]=find(par[a.first][a.second]);
	}
}
void unite(pii a,pii b)
{
	a=find(a);
	b=find(b);
	if(a==b)
	{
		return;
	}
	if(ran[a.first][a.second]>ran[b.first][b.second])
	{
		par[b.first][b.second]=a;
		ren[a.first][a.second]+=ren[b.first][b.second];
		upm[a.first][a.second]=min(upm[a.first][a.second],upm[b.first][b.second]);
	}
	else
	{
		par[a.first][a.second]=b;
		ren[b.first][b.second]+=ren[a.first][a.second];
		upm[b.first][b.second]=min(upm[a.first][a.second],upm[b.first][b.second]);
	}
	if(ran[a.first][a.second]==ran[b.first][b.second])
	{
		ran[b.first][b.second]++;
	}
}
int map[252][252];
bool ismin[252][252];
int main()
{
	int data;
	scanf("%d",&data);
	for(int p=0;p<data;p++)
	{
		init();
		int mx,my;
		scanf("%d%d",&mx,&my);
		for(int i=0;i<252;i++)
		{
			for(int j=0;j<252;j++)
			{
				map[i][j]=0;
				ismin[i][j]=false;
			}
		}
		for(int i=0;i<mx;i++)
		{
			for(int j=0;j<my;j++)
			{
				char zan;
				scanf(" %c",&zan);
				if(zan=='1')
				{
					if(map[i][j]==1)
					{
						unite(make_pair(i,j),make_pair(i+1,j+1));
					}
					if(map[i][j+1]==1)
					{
						unite(make_pair(i,j+1),make_pair(i+1,j+1));
					}
					if(map[i][j+2]==1)
					{
						unite(make_pair(i,j+2),make_pair(i+1,j+1));
					}
					if(map[i+1][j]==1)
					{
						unite(make_pair(i+1,j),make_pair(i+1,j+1));
					}
					map[i+1][j+1]=1;
				}
			}
		}
		int ret=0;
		for(int i=1;i<=mx;i++)
		{
			for(int j=1;j<=my;j++)
			{
				if(find(make_pair(i,j))==make_pair(i,j))
				{
					ismin[upm[i][j].first][upm[i][j].second]=true;
				}
			}
		}
		for(int i=1;i<=mx;i++)
		{
			for(int j=1;j<=my;j++)
			{
				if(ismin[i][j]&&ren[find(make_pair(i,j)).first][find(make_pair(i,j)).second]%4==0)
				{
					int hen=ren[find(make_pair(i,j)).first][find(make_pair(i,j)).second]/4+1;
					if(i+hen-1+hen-1<=mx&&j+hen-1<=my&&j-hen+1>=1)
					{
						bool han=true;
						for(int k=0;k<hen;k++)
						{
							if(map[i+k][j-k]==0||map[i+k][j+k]==0||map[i+hen-1+k][j-hen+1+k]==0||map[i+hen-1+k][j+hen-1-k]==0)
							{
								han=false;
								break;
							}
						}
						if(han)
						{
							ret++;
						}
					}
					if(i+hen-1<=mx&&j+hen-1<=my)
					{
						bool han=true;
						for(int k=0;k<hen;k++)
						{
							if(map[i+k][j]==0||map[i][j+k]==0||map[i+hen-1][j+k]==0||map[i+k][j+hen-1]==0)
							{
								han=false;
								break;
							}
						}
						if(han)
						{
							ret++;
						}
					}
				}
			}
		}
		printf("%d\n",ret);
	}
}