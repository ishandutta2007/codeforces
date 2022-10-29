#include<stdio.h>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pii;
typedef pair<ll,pii>pi3;
ll map[1000][1000];
ll rui[1001][1001];
ll gmin[1000][1000];
bool flag[1000][1000];
int main()
{
	int mx,my,bx,by;
	scanf("%d%d%d%d",&mx,&my,&bx,&by);
	for(int i=0;i<mx;i++)
	{
		for(int j=0;j<my;j++)
		{
			scanf("%I64d",&map[i][j]);
			rui[i+1][j+1]=rui[i+1][j]+rui[i][j+1]-rui[i][j]+map[i][j];
			flag[i][j]=true;
		}
	}
	for(int i=0;i<mx;i++)
	{
		deque<pii>deq;
		for(int j=0;j<my;j++)
		{
			for(;;)
			{
				if(deq.empty())
				{
					break;
				}
				if(map[i][j]<=deq[deq.size()-1].first)
				{
					deq.pop_back();
				}
				else
				{
					break;
				}
			}
			deq.push_back(make_pair(map[i][j],j));
			if(deq[0].second<=j-by)
			{
				deq.pop_front();
			}
			if(by-1<=j)
			{
				gmin[i][j]=deq[0].first;
			}
		}
	}
	vector<pi3>vec;
	for(int j=by-1;j<my;j++)
	{
		deque<pii>deq;
		for(int i=0;i<mx;i++)
		{
			for(;;)
			{
				if(deq.empty())
				{
					break;
				}
				if(gmin[i][j]<=deq[deq.size()-1].first)
				{
					deq.pop_back();
				}
				else
				{
					break;
				}
			}
			deq.push_back(make_pair(gmin[i][j],i));
			if(deq[0].second<=i-bx)
			{
				deq.pop_front();
			}
			if(bx-1<=i)
			{
				vec.push_back(make_pair(rui[i+1][j+1]-rui[i+1][j+1-by]-rui[i+1-bx][j+1]+rui[i+1-bx][j+1-by]-deq[0].first*bx*by,make_pair(i-bx+1,j-by+1)));
			}
		}
	}
	sort(vec.begin(),vec.end());
	vector<pi3>ans;
	for(int i=0;i<vec.size();i++)
	{
		if(flag[vec[i].second.first][vec[i].second.second]&&flag[vec[i].second.first+bx-1][vec[i].second.second]&&flag[vec[i].second.first][vec[i].second.second+by-1]&&flag[vec[i].second.first+bx-1][vec[i].second.second+by-1])
		{
			ans.push_back(vec[i]);
			for(ll j=vec[i].second.first;j<=vec[i].second.first+bx-1;j++)
			{
				for(ll k=vec[i].second.second;k<=vec[i].second.second+by-1;k++)
				{
					flag[j][k]=false;
				}
			}
		}
	}
	printf("%d\n",int(ans.size()));
	for(int i=0;i<ans.size();i++)
	{
		printf("%I64d %I64d %I64d\n",ans[i].second.first+1,ans[i].second.second+1,ans[i].first);
	}
}