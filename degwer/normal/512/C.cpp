#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int>pii;
int pat[402][402];
bool flag[402];
vector<int>now;
vector<int>arr;
bool isok=false;
vector<int>dat[10001];
int pt[10001];
void dfs(int node)
{
	if(isok)return;
	if(flag[node])return;
	flag[node]=true;
	now.push_back(node);
	if(node==1){isok=true;return;}
	if(isok)return;
	for(int i=0;i<402;i++)
	{
		if(pat[node][i]>0)
		{
			arr.push_back(0);
			dfs(i);
			if(isok)return;
			arr.pop_back();
		}
	}
	now.pop_back();
}
int flow()
{
	int ans=0;
	for(;;)
	{
		fill(flag,flag+402,false);
		now.clear();
		arr.clear();
		isok=false;
		dfs(0);
		if(!isok)return ans;
		for(int i=0;i<now.size()-1;i++)
		{
			if(arr[i]==0)
			{
				pat[now[i]][now[i+1]]--;
				pat[now[i+1]][now[i]]++;
			}
			else
			{
				pat[now[i]][now[i+1]]++;
				pat[now[i+1]][now[i]]--;
			}
		}
		ans++;
	}
}
bool map[20001];
vector<int>ap1[200],ap2[200];
int main()
{
	fill(map,map+20000,true);
	for(int i=2;i<=20000;i++)
	{
		for(int j=i+i;j<=20000;j+=i)
		{
			map[j]=false;
		}
	}
	int num;
	scanf("%d",&num);
	vector<int>v1,v2;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		if(zan%2==1)v1.push_back(zan);
		else v2.push_back(zan);
		dat[zan].push_back(i+1);
	}
	if(v1.size()!=v2.size())
	{
		printf("Impossible\n");
		return 0;
	}
	for(int i=0;i<v1.size();i++)
	{
		pat[0][i+2]=2;
	}
	for(int i=0;i<v2.size();i++)
	{
		pat[i+2+v1.size()][1]=2;
	}
	for(int i=0;i<v1.size();i++)for(int j=0;j<v2.size();j++)if(map[v1[i]+v2[j]])pat[i+2][j+2+v1.size()]=1;
	int t=flow();
	if(t!=v1.size()*2)
	{
		printf("Impossible\n");
		return 0;
	}
	for(int i=0;i<v1.size();i++)
	{
		for(int j=0;j<v2.size();j++)
		{
			if(pat[j+2+v1.size()][i+2]){ap1[i].push_back(j);ap2[j].push_back(i);}
		}
	}
	vector<vector<int> >a;
	bool f[200];
	fill(f,f+200,false);
	for(int i=0;i<v1.size();i++)
	{
		if(f[i])continue;
		vector<int>v;
		int now=i;
		int bef=-1;
		for(;;)
		{
			f[now]=true;
			v.push_back(v1[now]);
			if(bef!=ap1[now][0])
			{
				bef=now;
				now=ap1[now][0];
			}
			else
			{
				bef=now;
				now=ap1[now][1];
			}
			v.push_back(v2[now]);
			if(bef!=ap2[now][0])
			{
				bef=now;
				now=ap2[now][0];
			}
			else
			{
				bef=now;
				now=ap2[now][1];
			}
			if(now==i)break;
		}
		a.push_back(v);
	}
	printf("%d\n",int(a.size()));
	for(int i=0;i<a.size();i++)
	{
		printf("%d",a[i].size());
		for(int j=0;j<a[i].size();j++)printf(" %d",dat[a[i][j]][pt[a[i][j]]++]);
		printf("\n");
	}
}