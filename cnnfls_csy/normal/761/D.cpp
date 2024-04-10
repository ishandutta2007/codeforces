#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<queue>
using namespace std;
priority_queue<pair<int,int>,vector<pair<int,int>/**/>,greater<pair<int,int>/**/>/**/> d;
int a[100005],b[100005],c[100005],n,m,i,j,xx,l,r;
pair<int,int> x;
int main()
{
	cin>>n>>l>>r;
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&xx);
		d.push(make_pair(xx,i));
	}
	b[d.top().second]=l;
	c[d.top().second]=l-a[d.top().second];
	for (i=2;i<=n;i++)
	{
		x=d.top();d.pop();
		if (c[x.second]+a[d.top().second]+1>r)
		{
			cout<<-1;
			return 0;
		}
		b[d.top().second]=max(c[x.second]+a[d.top().second]+1,l);
		c[d.top().second]=b[d.top().second]-a[d.top().second];
	}
	for (i=1;i<=n;i++)
	printf("%d ",b[i]);
	return 0;
}/**/