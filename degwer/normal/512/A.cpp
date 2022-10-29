#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int map[26][26];
vector<int>topo;
bool flag[26];
int ban[26];
void dfs(int node)
{
	if(flag[node])return;
	flag[node]=true;
	for(int i=0;i<26;i++)if(map[node][i])dfs(i);
	topo.push_back(node);
	ban[node]=26-topo.size();
}
int main()
{
	int num;
	scanf("%d",&num);
	vector<string>vec;
	for(int i=0;i<num;i++)
	{
		string str;
		cin>>str;
		vec.push_back(str);
	}
	bool f=true;
	for(int i=0;i<num-1;i++)
	{
		bool fl=false;
		for(int j=0;j<min(vec[i].size(),vec[i+1].size());j++)
		{
			if(vec[i][j]!=vec[i+1][j])
			{
				map[vec[i][j]-'a'][vec[i+1][j]-'a']=1;
				fl=true;
				break;
			}
		}
		if(fl==false&&vec[i].size()>vec[i+1].size())f=false;
	}
	fill(flag,flag+26,false);
	for(int i=0;i<26;i++)
	{
		if(!flag[i])
		{
			dfs(i);
		}
	}
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<26;j++)
		{
			if(map[i][j]==1&&ban[i]>ban[j])f=false;
		}
	}
	if(f)
	{
		for(int i=0;i<26;i++)printf("%c",topo[25-i]+'a');printf("\n");
	}
	else printf("Impossible\n");
}