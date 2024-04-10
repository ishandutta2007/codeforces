#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int map[100][100];
bool flag[100];
vector<int>topo;
int num;
int dat[100];
int ans[100];
bool used[100];
void dfs(int node)
{
	if(flag[node])return;
	flag[node]=true;
	for(int i=0;i<num;i++)
	{
		if(map[node][i]==1&&(!used[i]))dfs(i);
	}
	topo.push_back(node);
}
vector<int>clc;
void rdfs(int node)
{
	if(flag[node])return;
	flag[node]=true;
	for(int i=0;i<num;i++)
	{
		if(map[i][node]==1&&(!used[i]))rdfs(i);
	}
	clc.push_back(node);
}
int main()
{
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		for(int j=0;j<num;j++)
		{
			char zan;
			scanf(" %c",&zan);
			map[i][j]=zan-'0';
		}
	}
	for(int i=0;i<num;i++)scanf("%d",&dat[i]);
	fill(used,used+num,false);
	for(int i=0;i<num;i++)
	{
		fill(flag,flag+num,false);
		topo.clear();
		clc.clear();
		for(int j=0;j<num;j++)
		{
			if((!flag[j])&&(!used[j]))
			{
				dfs(j);
			}
		}
		int b=topo[topo.size()-1];
		fill(flag,flag+num,false);
		rdfs(b);
		int rr=-1;
		for(int j=0;j<clc.size();j++)
		{
			if(dat[clc[j]]==0)rr=clc[j];
		}
		if(rr==-1)
		{
			used[b]=true;
			ans[b]=0;
		}
		else
		{
			for(int j=0;j<num;j++)
			{
				dat[j]-=map[rr][j];
			}
			used[rr]=true;
			ans[rr]=1;
		}
	}
	vector<int>c;
	for(int i=0;i<num;i++)if(ans[i]==1)c.push_back(i);
	printf("%d\n",c.size());
	for(int i=0;i<c.size();i++)
	{
		if(i!=0)printf(" ");
		printf("%d",c[i]+1);
	}
	printf("\n");
}