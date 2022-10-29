#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>pat[100000];
bool flag[100000];
double ans=0.0;
void dfs(int node,int d)
{
	if(flag[node])
	{
		return;
	}
	flag[node]=true;
	ans+=1.0/double(d);
	for(int i=0;i<pat[node].size();i++)
	{
		if(!flag[pat[node][i]])
		{
			dfs(pat[node][i],d+1);
		}
	}
}
int main()
{
	int node;
	scanf("%d",&node);
	for(int i=0;i<node-1;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		za--;
		zb--;
		pat[za].push_back(zb);
		pat[zb].push_back(za);
	}
	dfs(0,1);
	printf("%lf\n",ans);
}