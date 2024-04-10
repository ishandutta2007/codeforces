#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<set>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,nxt[1000005],num[300005],op,x,y;
long long sum[300005];
set<int> ind;
void add(int x,long long y)
{
	int i;
	for (i=x;i<=n;i+=(i&(-i))) sum[i]+=y;
}
long long query(int x)
{
	long long ans=0;
	int i;
	for (i=x;i;i-=(i&(-i))) ans+=sum[i];
	return ans;
}
int main()
{
	for (i=1;i<=1000000;i++)
	{
		for (j=1;i*j<=1000000;j++)
		{
			nxt[i*j]++;
		}
	}
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++) scanf("%d",&num[i]);
	for (i=1;i<=n;i++)
	{
		add(i,num[i]);
		if (nxt[num[i]]!=num[i])
		{
			ind.insert(i);
		}
	}
	while (m--)
	{
		scanf("%d%d%d",&op,&x,&y);
		if (op==1)
		{
			set<int>::iterator ub=ind.upper_bound(y);
			vector<int> era;
			for (set<int>::iterator it=ind.lower_bound(x);it!=ub;it++)
			{
				add(*it,-num[*it]);
				add(*it,num[*it]=nxt[num[*it]]);
				if (nxt[num[*it]]==num[*it])
				{
					era.push_back(*it);
				}
			}
			for (i=0;i<era.size();i++) ind.erase(era[i]);
		}
		if (op==2)
		{
			printf("%I64d\n",query(y)-query(x-1));
		}
	}
	return 0;
}