#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
int num,way,dam;
int dat[100000];
vector<int>pat[100000];
int gen[100000];
int flag[100000];
int now[100000];
void dfs(int node)
{
	if(flag[node]==-1)return;
	flag[node]=-1;
	for(int i=0;i<pat[node].size();i++)
	{
		now[pat[node][i]]--;
		if(now[pat[node][i]]<gen[pat[node][i]])dfs(pat[node][i]);
	}
}
vector<int>calc(double med)
{
	for(int i=0;i<num;i++)gen[i]=int(ceil(pat[i].size()*med));
	for(int i=0;i<num;i++)flag[i]=0;
	for(int i=0;i<num;i++)now[i]=pat[i].size();
	for(int i=0;i<num;i++)if(dat[i]==-1)dfs(i);
	vector<int>ret;
	for(int i=0;i<num;i++)if(flag[i]==0)ret.push_back(i);
	return ret;
}
int main()
{
	scanf("%d%d%d",&num,&way,&dam);
	for(int i=0;i<dam;i++)
	{
		int z;
		scanf("%d",&z);
		z--;
		dat[z]=-1;
	}
	for(int i=0;i<way;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		za--;
		zb--;
		pat[za].push_back(zb);
		pat[zb].push_back(za);
	}
	double beg=0.0,end=1.0;
	for(int p=0;p<48;p++)
	{
		double med=(beg+end)/2.0;
		if(calc(med).empty())end=med;
		else beg=med;
		if(beg==end)break;
	}
	//printf("%lf\n",beg);
	vector<int>r=calc(beg);
	printf("%d\n",r.size());
	for(int i=0;i<r.size();i++)
	{
		if(i!=0)printf(" ");
		printf("%d",r[i]+1);
	}
	printf("\n");
}