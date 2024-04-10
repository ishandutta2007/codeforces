#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int n,k,top=0;
struct node{int x,t;}p[100007],tp[100007];



int num=0,vis[100007];

bool cmp(node a,node b)
{
	return (a.t==b.t)?a.x<b.x:a.t>b.t;
}

bool cmp1(node a,node b)
{
	return a.t<b.t;
}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&p[i].x);
	for(int i=1;i<=n;i++) scanf("%d",&p[i].t);
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(vis[p[i].x]==0)
		{
			num++;
			vis[p[i].x]++;
		}
		else
		{
			tp[++top]=p[i];
		}
	}
	sort(tp+1,tp+top+1,cmp1);
	long long sum=0;
	for(int i=1;i<=k-num;i++) sum+=tp[i].t;
	cout<<sum<<endl;
	return 0;
}
/*
8 7
1 1 3 1 5 3 7 1
5 7 4 8 1 3 5 2
*/