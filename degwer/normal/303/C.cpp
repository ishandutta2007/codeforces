#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
typedef pair<int,int>pii;
vector<pii>dat[1000001];
#define LIMIT 1000001
int par[LIMIT];
int ran[LIMIT];
bool isok[1000001];
void init()
{
	for(int i=0;i<LIMIT;i++)
	{
		par[i]=i;
		ran[i]=0;
	}
}
int find(int a)
{
	if(par[a]==a)
	{
		return a;
	}
	else
	{
		return par[a]=find(par[a]);
	}
}
void unite(int a,int b)
{
	a=find(a);
	b=find(b);
	if(a==b)
	{
		return;
	}
	if(ran[a]>ran[b])
	{
		par[b]=a;
	}
	else
	{
		par[a]=b;
	}
	if(ran[a]==ran[b])
	{
		ran[b]++;
	}
}
vector<int>uni(vector<pii>vec)
{
	vector<int>zan;
	for(int i=0;i<vec.size();i++)
	{
		zan.push_back(vec[i].first);
		zan.push_back(vec[i].second);
	}
	sort(zan.begin(),zan.end());
	int now=-1;
	vector<int>ret;
	for(int i=0;i<zan.size();i++)
	{
		if(now!=zan[i])
		{
			ret.push_back(zan[i]);
			now=zan[i];
		}
	}
	return ret;
}
int main()
{
	int num,gen;
	scanf("%d%d",&num,&gen);
	init();
	vector<int>vec;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		vec.push_back(zan);
	}
	fill(isok,isok+1000001,true);
	for(int i=0;i<num;i++)
	{
		for(int j=i+1;j<num;j++)
		{
			int a=abs(vec[i]-vec[j]);
			if(dat[a].size()<gen)
			{
				dat[a].push_back(make_pair(i,j));
			}
			else
			{
				isok[a]=false;
			}
		}
	}
	int g=gen*(gen+1)/2;
	for(int i=num-gen;;i++)
	{
		vector<pii>now;
		vector<int>used;
		int cnt=0;
		bool f=false;
		for(int j=i;j<=1000000;j+=i)
		{
			if(!isok[j])
			{
				f=true;
				break;
			}
			if(now.size()+dat[j].size()>g)
			{
				f=true;
				break;
			}
			for(int k=0;k<dat[j].size();k++)
			{
				now.push_back(dat[j][k]);
			}
		}
		if(f)
		{
			continue;
		}
		//printf("kouho:%d\n",i);
		//for(int p=0;p<now.size();p++)
		//{
		//	printf(" %d %d\n",now[p].first,now[p].second);
		//}
		used=uni(now);
		if(used.size()>gen+gen)
		{
			continue;
		}
		for(int j=0;j<now.size();j++)
		{
			unite(now[j].first,now[j].second);
		}
		for(int j=0;j<used.size();j++)
		{
			if(find(used[j])==used[j])
			{
				cnt++;
			}
		}
		//printf("%d %d\n",int(used.size()),cnt);
		if(int(used.size())-cnt<=gen)
		{
			printf("%d\n",i);
			return 0;
		}
		for(int j=0;j<used.size();j++)
		{
			par[used[j]]=used[j];
			ran[used[j]]=0;
		}
	}
}