#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
#define LIMIT 300
int par[LIMIT];
int ran[LIMIT];
int ren[LIMIT];
void init()
{
	for(int i=0;i<LIMIT;i++)
	{
		par[i]=i;
		ran[i]=0;
		ren[i]=1;
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
		ren[a]+=ren[b];
	}
	else
	{
		par[a]=b;
		ren[b]+=ren[a];
	}
	if(ran[a]==ran[b])
	{
		ran[b]++;
	}
}
vector<int>dat[LIMIT];
int pt[LIMIT];
int main()
{
	init();
	int num;
	scanf("%d",&num);
	vector<int>vec;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		zan--;
		vec.push_back(zan);
	}
	for(int i=0;i<num;i++)
	{
		for(int j=0;j<num;j++)
		{
			char zan;
			scanf(" %c",&zan);
			if(zan=='1')unite(i,j);
		}
	}
	for(int i=0;i<num;i++)
	{
		dat[find(i)].push_back(vec[i]);
	}
	for(int i=0;i<num;i++)
	{
		sort(dat[i].begin(),dat[i].end());
	}
	vector<int>ans;
	for(int i=0;i<num;i++)
	{
		ans.push_back(dat[find(i)][pt[find(i)]]);
		pt[find(i)]++;
	}
	for(int i=0;i<num;i++)
	{
		if(i!=0)printf(" ");
		printf("%d",ans[i]+1);
	}
	printf("\n");
}