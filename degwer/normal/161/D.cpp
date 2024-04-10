#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>pat[50000];
vector<int>ko[50000];
int par[50000];
bool flag[50000];
int sum=0;
int cit,mok;
void dfs(int node)
{
	if(flag[node])
	{
		return;
	}
	flag[node]=true;
	for(int i=0;i<pat[node].size();i++)
	{
		if(!flag[pat[node][i]])
		{
			ko[node].push_back(pat[node][i]);
			par[pat[node][i]]=node;
			dfs(pat[node][i]);
		}
	}
}
vector<int>calc(int node)
{
	vector<int>ret;
	ret.resize(mok+1);
	fill(ret.begin(),ret.end(),0);
	ret[0]=1;
	for(int i=0;i<ko[node].size();i++)
	{
		vector<int>zan=calc(ko[node][i]);
		for(int j=0;j<mok+1;j++)
		{
			sum+=ret[j]*zan[mok-j];
		}
		for(int j=0;j<mok+1;j++)
		{
			ret[j]+=zan[j];
		}
	}
	reverse(ret.begin(),ret.end());
	ret.push_back(0);
	reverse(ret.begin(),ret.end());
	return ret;
}
int main()
{
	scanf("%d%d",&cit,&mok);
	for(int i=0;i<cit-1;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		za--;
		zb--;
		pat[za].push_back(zb);
		pat[zb].push_back(za);
	}
	fill(flag,flag+50000,false);
	dfs(0);
	calc(0);
	printf("%d\n",sum);
}