#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>pat[5000];
vector<int>ko[5000];
int par[5000];
bool flag[5000];
bool ans[5001];
int num;
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
			par[pat[node][i]]=node;
			ko[node].push_back(pat[node][i]);
			dfs(pat[node][i]);
		}
	}
}
int calc(int node)
{
	vector<int>vec;
	int res=num-1;
	for(int i=0;i<ko[node].size();i++)
	{
		int zan=calc(ko[node][i]);
		vec.push_back(zan);
		res-=zan;
	}
	if(res!=0)
	{
		vec.push_back(res);
	}
	bool dp[5001];
	bool newdp[5001];
	fill(dp,dp+num+1,false);
	fill(newdp,newdp+num+1,false);
	dp[0]=true;
	newdp[0]=true;
	for(int i=0;i<vec.size();i++)
	{
		for(int j=1;j<num+1;j++)
		{
			if(j>=vec[i])
			{
				newdp[j]|=dp[j-vec[i]];
			}
		}
		for(int j=0;j<num+1;j++)
		{
			dp[j]=newdp[j];
		}
	}
	for(int i=0;i<num+1;i++)
	{
		ans[i]|=dp[i];
	}
	return num-res;
}
int main()
{
	scanf("%d",&num);
	for(int i=0;i<num-1;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		za--;
		zb--;
		pat[za].push_back(zb);
		pat[zb].push_back(za);
	}
	fill(flag,flag+num,false);
	fill(ans,ans+num+1,false);
	dfs(0);
	calc(0);
	int ret=0;
	for(int i=1;i<num-1;i++)
	{
		if(ans[i])
		{
			ret++;
		}
	}
	printf("%d\n",ret);
	for(int i=1;i<num-1;i++)
	{
		if(ans[i])
		{
			printf("%d %d\n",i,num-i-1);
		}
	}
}