#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int>pii;
typedef pair<pii,int>pi3;
vector<int>pat[100000];
vector<int>ko[100000];
int par[100000];
bool flag[100000];
int siz[100000];
void dfs(int node)
{
	if(flag[node])return;
	flag[node]=true;
	for(int i=0;i<pat[node].size();i++)
	{
		if(!flag[pat[node][i]])
		{
			par[pat[node][i]]=node;
			ko[node].push_back(pat[node][i]);
			dfs(pat[node][i]);
		}
	}
}
void dfs2(int node)
{
	int ret=1;
	for(int i=0;i<ko[node].size();i++)
	{
		dfs2(ko[node][i]);
		ret+=siz[ko[node][i]];
	}
	siz[node]=ret;
}
int main()
{
	int num;
	scanf("%d",&num);
	vector<pi3>vec;
	for(int i=0;i<num-1;i++)
	{
		int za,zb,zc;
		scanf("%d%d%d",&za,&zb,&zc);
		za--;
		zb--;
		pat[za].push_back(zb);
		pat[zb].push_back(za);
		vec.push_back(make_pair(make_pair(za,zb),zc));
	}
	fill(flag,flag+num,false);
	par[0]=-1;
	dfs(0);
	dfs2(0);
	double zen=double(num)*double(num-1)*double(num-2)/6.0;
	double now=0;
	for(int i=0;i<vec.size();i++)
	{
		if(par[vec[i].first.first]==vec[i].first.second)
		{
			swap(vec[i].first.first,vec[i].first.second);
		}
	}
	vector<double>dat;
	for(int i=0;i<vec.size();i++)
	{
		int sa=siz[vec[i].first.second],sb=num-sa;
		dat.push_back(double(sa)*double(sa-1)*double(sb)/2.0+double(sa)*double(sb)*double(sb-1)/2.0);
		now+=dat[i]*double(vec[i].second)*2.0;
	}
	int query;
	scanf("%d",&query);
	for(int i=0;i<query;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		za--;
		now-=(vec[za].second-double(zb))*2.0*dat[za];
		printf("%lf\n",now/zen);
		vec[za].second=zb;
	}
}