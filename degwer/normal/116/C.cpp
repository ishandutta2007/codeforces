#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int par[2000];
vector<int>ko[2000];
int maxi=0;
void dfs(int node,int depth)
{
	for(int i=0;i<ko[node].size();i++)
	{
		dfs(ko[node][i],depth+1);
	}
	maxi=max(maxi,depth);
}
int main()
{
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		if(zan==-1)
		{
			par[i]=zan;
		}
		else
		{
			zan--;
			par[i]=zan;
			ko[zan].push_back(i);
		}
	}
	for(int i=0;i<num;i++)
	{
		if(par[i]==-1)
		{
			dfs(i,0);
		}
	}
	printf("%d\n",maxi+1);
}