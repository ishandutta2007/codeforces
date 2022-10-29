#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int map[1000][1000];
int main()
{
	int mx,my;
	scanf("%d%d",&mx,&my);
	vector<pair<int,int> >vecx;
	vector<pair<int,int> >vecy;
	for(int i=0;i<mx;i++)
	{
		for(int j=0;j<my;j++)
		{
			char zan;
			scanf(" %c",&zan);
			if(zan=='#')
			{
				map[i][j]=1;
				vecx.push_back(make_pair(i,j));
				vecy.push_back(make_pair(j,i));
			}
			else
			{
				map[i][j]=0;
			}
		}
	}
	sort(vecx.begin(),vecx.end());
	sort(vecy.begin(),vecy.end());
	int kx[1000];
	int ky[1000];
	fill(kx,kx+1000,10000000);
	fill(ky,ky+1000,10000000);
	kx[0]=0;
	queue<pair<int,int> >que;
	que.push(make_pair(0,0));
	for(;;)
	{
		if(que.empty()==true)
		{
			printf("-1\n");
			return 0;
		}
		pair<int,int>zan=que.front();
		que.pop();
		if(zan==make_pair(mx-1,0))
		{
			printf("%d\n",kx[mx-1]);
			return 0;
		}
		if(zan.second==0)
		{
			int low=lower_bound(vecx.begin(),vecx.end(),make_pair(zan.first,0))-vecx.begin();
			int upp=upper_bound(vecx.begin(),vecx.end(),make_pair(zan.first,10000000))-vecx.begin()-1;
			for(int k=low;k<=upp;k++)
			{
				if(ky[vecx[k].second]>kx[zan.first]+1)
				{
					ky[vecx[k].second]=kx[zan.first]+1;
					que.push(make_pair(vecx[k].second,1));
				}
			}
		}
		else
		{
			int low=lower_bound(vecy.begin(),vecy.end(),make_pair(zan.first,0))-vecy.begin();
			int upp=upper_bound(vecy.begin(),vecy.end(),make_pair(zan.first,10000000))-vecy.begin()-1;
			for(int k=low;k<=upp;k++)
			{
				if(kx[vecy[k].second]>ky[zan.first]+1)
				{
					kx[vecy[k].second]=ky[zan.first]+1;
					que.push(make_pair(vecy[k].second,0));
				}
			}
		}
	}
}