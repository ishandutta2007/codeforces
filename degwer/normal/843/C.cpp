#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>pat[200000];
bool flag[200000];
int siz[200000];
int cent[200000];
typedef pair<int,int>pii;
typedef pair<int,pii>pi3;
int num;
void dfs(int node)
{
	if(flag[node])return;
	flag[node]=true;
	siz[node]=1;
	int maxi=0;
	for(int i=0;i<pat[node].size();i++)
	{
		if(!flag[pat[node][i]])
		{
			dfs(pat[node][i]);
			siz[node]+=siz[pat[node][i]];
			maxi=max(maxi,siz[pat[node][i]]);
		}
	}
	maxi=max(maxi,num-siz[node]);
	if(maxi+maxi<=num)cent[node]=1;
}
int par[200000];
int deg[200000];
vector<int>idx;
vector<pi3>ans;
void dfs2(int node,int p)
{
	if(flag[node])return;
	flag[node]=true;
	par[node]=p;
	for(int i=0;i<pat[node].size();i++)
	{
		if(!flag[pat[node][i]])
		{
			dfs2(pat[node][i],node);
		}
	}
	idx.push_back(node);
}
int main()
{
	scanf("%d",&num);
	for(int i=0;i<num-1;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		za--,zb--;
		pat[za].push_back(zb);
		pat[zb].push_back(za);
	}
	dfs(0);
	fill(flag,flag+num,false);
	for(int c=0;c<num;c++)
	{
		if(cent[c]==0)continue;
		flag[c]=true;
		for(int j=0;j<pat[c].size();j++)
		{
			if(cent[pat[c][j]])continue;
			idx.clear();
			idx.push_back(c);
			dfs2(pat[c][j],c);
			ans.push_back(make_pair(c,make_pair(pat[c][j],idx[1])));
			for(int i=1;i<idx.size()-1;i++)if(idx[i+1]!=par[idx[i]])ans.push_back(make_pair(idx[i],make_pair(par[idx[i]],idx[i+1])));
			for(int i=int(idx.size())-4;i>=0;i--)ans.push_back(make_pair(idx[i],make_pair(idx[i+1],idx[idx.size()-2])));
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)printf("%d %d %d\n",ans[i].first+1,ans[i].second.first+1,ans[i].second.second+1);
}