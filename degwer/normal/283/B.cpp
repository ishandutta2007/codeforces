#include<stdio.h>
#include<vector>
#include<algorithm>
#define LIMIT 400000
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
ll dist[200000][2];
bool flag[200000][2];
int par[LIMIT];
int ran[LIMIT];
ll ren[LIMIT];
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
int arr[200000];
int num;
ll dfs(int na,int nb)
{
	if(na<0||na>=num)
	{
		return 0;
	}
	if(na==0&&nb==0)
	{
		return -1;
	}
	if(ren[find(na*2+nb)]<0)
	{
		return dist[na][nb]=-1;
	}
	if(flag[na][nb])
	{
		return dist[na][nb];
	}
	flag[na][nb]=true;
	ll ans;
	if(nb==0)
	{
		ans=dfs(na+arr[na],1);
	}
	else
	{
		ans=dfs(na-arr[na],0);
	}
	if(ans==-1)
	{
		return dist[na][nb]=-1;
	}
	return dist[na][nb]=ans+arr[na];
}
int main()
{
	init();
	scanf("%d",&num);
	for(int i=1;i<num;i++)
	{
		scanf("%d",&arr[i]);
		if(i+arr[i]<num)
		{
			if(find(i*2)==find((i+arr[i])*2+1))
			{
				ren[find(i*2)]=-1000000000;
			}
			unite(i*2,(i+arr[i])*2+1);
		}
		if(i-arr[i]>=0)
		{
			if(find(i*2+1)==find((i-arr[i])*2))
			{
				ren[find(i*2+1)]=-1000000000;
			}
			unite(i*2+1,(i-arr[i])*2);
		}
	}
	for(int i=0;i<num;i++)
	{
		flag[i][0]=flag[i][1]=false;
	}
	for(int i=1;i<num;i++)
	{
		for(int j=0;j<2;j++)
		{
			dfs(i,j);
		}
	}
	for(int i=1;i<num;i++)
	{
		if(dist[i][1]!=-1)
		{
			printf("%I64d\n",dist[i][1]+i);
		}
		else
		{
			printf("-1\n");
		}
	}
}