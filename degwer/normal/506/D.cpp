#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
#define SIZE 200
typedef pair<int,int>pii;
set<pii>se;
vector<vector<int> >dat;
vector<vector<bool> >vb;
map<pii,vector<int> >ma;
void dfs(int node,int col,int b)
{
	if(se.find(make_pair(node,col))!=se.end())return;
	se.insert(make_pair(node,col));
	dat[b].push_back(node);
	for(int i=0;i<ma[make_pair(node,col)].size();i++)
	{
		dfs(ma[make_pair(node,col)][i],col,b);
	}
}
int main()
{
	int num,way;
	scanf("%d%d",&num,&way);
	for(int i=0;i<way;i++)
	{
		int za,zb,zc;
		scanf("%d%d%d",&za,&zb,&zc);
		za--;
		zb--;
		zc--;
		ma[make_pair(za,zc)].push_back(zb);
		ma[make_pair(zb,zc)].push_back(za);
	}
	map<pii,vector<int> >::iterator it=ma.begin();
	for(;;)
	{
		if(it==ma.end())break;
		pair<pii,vector<int> >zan=(*it);
		it++;
		if(se.find(zan.first)==se.end())
		{
			vector<int>v;
			dat.push_back(v);
			dfs(zan.first.first,zan.first.second,dat.size()-1);
		}
	}
	vector<pii>vec;
	vector<vector<int> >dv;
	for(int i=0;i<dat.size();i++)
	{
		sort(dat[i].begin(),dat[i].end());
		if(dat[i].size()<=SIZE)
		{
			for(int j=0;j<dat[i].size();j++)
			{
				for(int k=j+1;k<dat[i].size();k++)
				{
					vec.push_back(make_pair(dat[i][j],dat[i][k]));
				}
			}
		}
		else
		{
			vector<bool>b;
			for(int j=0;j<num;j++)b.push_back(false);
			for(int j=0;j<dat[i].size();j++)
			{
				b[dat[i][j]]=true;
			}
			vb.push_back(b);
		}
	}
	sort(vec.begin(),vec.end());
	int query;
	scanf("%d",&query);
	for(int p=0;p<query;p++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		if(za>zb)swap(za,zb);
		za--;
		zb--;
		int low=lower_bound(vec.begin(),vec.end(),make_pair(za,zb))-vec.begin();
		int upp=upper_bound(vec.begin(),vec.end(),make_pair(za,zb))-vec.begin();
		int ret=upp-low;
		for(int i=0;i<vb.size();i++)
		{
			if(vb[i][za]&&vb[i][zb])ret++;
		}
		printf("%d\n",ret);
	}
}