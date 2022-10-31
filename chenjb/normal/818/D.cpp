#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#define LL long long 
#define inf 1000000007
using namespace std;
struct node
{
	int num,amount;
	friend bool operator <(node x,node y)
	{
		return x.amount>y.amount;
	}
};
priority_queue < node > q;
int n,A;
int c[110000];
int v[1100000];
int sum[1100000];
int main()
{
	cin>>n>>A;
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	memset(sum,0,sizeof(sum));
	while (!q.empty())q.pop();
	for(int i=1;i<=1000000;i++)
	{
		if (i!=A) q.push((node){i,0});
		v[i]=1;
	}
	v[A]=0;
	int i=1;
	for(int i=1;i<=n;i++)
	{
		//cout<<q.size()<<endl;
		sum[c[i]]++;
		if (c[i]==A)
		{
			//cout<<q.top().num<<" "<<q.top().amount<<endl;
			while (q.size()!=0&&q.top().amount<sum[A])
			{
				if (sum[q.top().num]==q.top().amount) v[q.top().num]=0;
				q.pop();
			}
			continue;
		}
		if (v[c[i]]==0)continue;
		if (sum[c[i]]>=sum[A])q.push((node){c[i],sum[c[i]]});
	}
	if (q.size()==0)cout<<-1<<endl;
	else cout<<q.top().num<<endl;
	return 0;
}