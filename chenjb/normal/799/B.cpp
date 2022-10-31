#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#define LL long long 
using namespace std;
struct node
{
	int p,a,b;
	friend bool operator <(node x,node y)
	{
		return x.p<y.p;
	}
}tmp[201000];
int a[4][201000];
int v[201000];
int tot[4],head[4];
int n,m;
int main()
{
	memset(tot,0,sizeof(tot));
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&tmp[i].p);
	for(int i=1;i<=n;i++)scanf("%d",&tmp[i].a);
	for(int i=1;i<=n;i++)scanf("%d",&tmp[i].b);
	sort(tmp+1,tmp+n+1);
	for(int i=1;i<=n;i++)
	{
		a[tmp[i].a][++tot[tmp[i].a]]=i;
		if (tmp[i].a!=tmp[i].b)
			a[tmp[i].b][++tot[tmp[i].b]]=i;
	}
	memset(v,0,sizeof(v));
	head[1]=head[2]=head[3]=1;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int t;
		scanf("%d",&t);
		while (head[t]<=tot[t]&&v[a[t][head[t]]]==1)head[t]++;
		if (head[t]>tot[t])printf("-1\n");
		else 
		{
			printf("%d ",tmp[a[t][head[t]]].p);
			v[a[t][head[t]]]=1;
		}
	}
	return 0;
}