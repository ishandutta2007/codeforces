#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
vector<int>pat[100000];
vector<int>ko[100000];
int par[100000];
bool flag[100000];
bool cut[100001];
int siz[100000];
int root[100000];
int now;
int gr=-1;
void dfs(int node)
{
	if(flag[node]||cut[node])
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
int mx[100000];
int getsz(int node,int r)
{
	if(cut[node])
	{
		return 0;
	}
	int sum=0;
	int maxi=0;
	for(int i=0;i<ko[node].size();i++)
	{
		if(!cut[ko[node][i]])
		{
			int j=getsz(ko[node][i],r);
			sum+=j;
			maxi=max(maxi,j);
		}
	}
	siz[node]=sum+1;
	root[node]=r;
	mx[node]=maxi;
	return sum+1;
}
void getg(int node)
{
	if(cut[node])
	{
		return;
	}
	if(siz[root[node]]-siz[node]<=now&&mx[node]<=now)
	{
		gr=node;
	}
	for(int i=0;i<ko[node].size();i++)
	{
		if(!cut[ko[node][i]])
		{
			getg(ko[node][i]);
		}
	}
}
char ans[100000];
int main()
{
	int num;
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
	fill(cut,cut+num,false);
	dfs(0);
	par[0]=100000;
	cut[100000]=true;
	int cnt=0;
	now=(num+1)/2;
	for(char n='A';;n++)
	{
		vector<int>vec;
		for(int i=0;i<num;i++)
		{
			if(cut[par[i]]&&(!cut[i]))
			{
				getsz(i,i);
				getg(i);
				ans[gr]=n;
				cnt++;
				vec.push_back(gr);
			}
		}
		for(int i=0;i<vec.size();i++)
		{
			cut[vec[i]]=true;
		}
		if(cnt==num)
		{
			break;
		}
		now=(now+1)/2;
	}
	for(int i=0;i<num;i++)
	{
		if(i!=0)
		{
			printf(" ");
		}
		printf("%c",ans[i]);
	}
	printf("\n");
}