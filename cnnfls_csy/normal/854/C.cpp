#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<queue>
#define sqr(x) (x)*(x)
using namespace std;
priority_queue<pair<int,int>/**/> pq;
int n,m,i,j,ans[300005],x,num[300005];
long long sum;
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		cin>>num[i];
	}
	for (i=1;i<=m;i++) pq.push(make_pair(num[i],i));
	for (i=m+1;i<=m+n;i++)
	{
		if (i<=n) pq.push(make_pair(num[i],i));
		ans[pq.top().second]=i;
		sum+=((long long)(i-pq.top().second))*(long long)(pq.top().first);
		pq.pop();
	}
	cout<<sum<<endl;
	for (i=1;i<=n;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}