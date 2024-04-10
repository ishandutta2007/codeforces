#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
vector<int>pr[500001];
vector<int>yk[500001];
int sq[500001];
int dat[200000];
ll now[500001];
bool flag[200000];
int main()
{
	int num,query;
	scanf("%d%d",&num,&query);
	for(int i=0;i<num;i++)scanf("%d",&dat[i]);
	for(int i=2;i<=500000;i++)
	{
		if(pr[i].empty())
		{
			for(int j=i;j<=500000;j+=i)
			{
				pr[j].push_back(i);
			}
		}
	}
	for(int i=1;i<=500000;i++)
	{
		for(int j=i;j<=500000;j+=i)
		{
			yk[j].push_back(i);
		}
	}
	for(int i=1;i<=500000;i++)
	{
		int t=1;
		for(int j=0;j<pr[i].size();j++)t*=pr[i][j];
		if(t!=i)sq[i]=0;
		else if(pr[i].size()%2==1)sq[i]=1;
		else sq[i]=-1;
	}
	ll ans=0;
	fill(flag,flag+200000,false);
	for(int p=0;p<query;p++)
	{
		int z;
		scanf("%d",&z);
		z--;
		if(!flag[z])
		{
			for(int i=0;i<yk[dat[z]].size();i++)
			{
				int t=yk[dat[z]][i];
				ans-=(now[t]*(now[t]-1)/2)*sq[t];
				now[t]++;
				ans+=(now[t]*(now[t]-1)/2)*sq[t];
			}
			flag[z]=true;
		}
		else
		{
			for(int i=0;i<yk[dat[z]].size();i++)
			{
				int t=yk[dat[z]][i];
				ans-=(now[t]*(now[t]-1)/2)*sq[t];
				now[t]--;
				ans+=(now[t]*(now[t]-1)/2)*sq[t];
			}
			flag[z]=false;
		}
		printf("%I64d\n",-ans);
	}
}