#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
vector<int>pat[200000];
vector<int>ko[200000];
bool flag[200000];
int dat[200000];
void dfs(int node)
{
	if(flag[node])return;
	flag[node]=true;
	for(int i=0;i<pat[node].size();i++)
	{
		if(!flag[pat[node][i]])
		{
			ko[node].push_back(pat[node][i]);
			dfs(pat[node][i]);
		}
	}
}
int root=-1;
void calc1(int node)
{
	if(ko[node].empty())dat[node]=0;
	int isr=0;
	for(int i=0;i<ko[node].size();i++)
	{
		calc1(ko[node][i]);
		if(dat[node]==-5)dat[node]=dat[ko[node][i]]+1;
		else if(dat[node]!=dat[ko[node][i]]+1)isr=1,dat[node]=-10;
	}
	if(root==-1&&isr==1)root=node;
}
void calc2(int node)
{
	if(ko[node].empty())dat[node]=0;
	for(int i=0;i<ko[node].size();i++)
	{
		calc2(ko[node][i]);
		if(dat[node]==-5)dat[node]=dat[ko[node][i]]+1;
		else if(dat[node]!=dat[ko[node][i]]+1)root=node,dat[node]=-1000000000;
	}
}
int main()
{
	int num;
	scanf("%d",&num);
	for(int i=0;i<num-1;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		za--,zb--;
		pat[za].push_back(zb);
		pat[zb].push_back(za);
	}
	fill(flag,flag+num,false);
	for(int i=0;i<num;i++)ko[i].clear(),dat[i]=-5;
	dfs(0);
	calc1(0);
	if(root==-1)root=0;
	//printf("%d\n",root+1);
	fill(flag,flag+num,false);
	for(int i=0;i<num;i++)ko[i].clear(),dat[i]=-5;
	dfs(root);
	calc2(root);
	//printf("%d\n",root+1);
	//for(int i=0;i<num;i++)printf("%d ",dat[i]);printf("\n");
	set<int>se;
	for(int i=0;i<ko[root].size();i++)
	{
		if(dat[ko[root][i]]<0)
		{
			printf("-1\n");
			return 0;
		}
		se.insert(dat[ko[root][i]]+1);
		//printf("%d ",dat[ko[root][i]]+1);
	}
	if(se.size()>=3)
	{
		printf("-1\n");
		return 0;
	}
	set<int>::iterator it=se.begin();
	int sum=0;
	for(;;)
	{
		if(it==se.end())break;
		sum+=*it;
		it++;
	}
	for(;;)
	{
		if(sum%2==1)break;
		sum/=2;
	}
	printf("%d\n",sum);
}