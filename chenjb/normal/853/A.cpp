#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
struct node
{
	int id;
	long long w;
	friend bool operator <(node x,node y)
	{
		return x.w<y.w;
	}
}a[310000];
using namespace std;
priority_queue< node > Q;
int ans[310000],n,k;
long long sum;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)a[i].id=i;
	for(int i=1;i<=n;i++)scanf("%I64d",&a[i].w);
	int now=1;
	while (!Q.empty())Q.pop();
	sum=0;
	for(int i=k+1;i<=k+n;i++)
	{
		while (now<=n&&now<=i)
		{
			Q.push(a[now]);
			now++;
		}
		node x=Q.top();
		Q.pop();
		sum=sum+1ll*(i-x.id)*x.w;
		ans[x.id]=i;
	}
	cout<<sum<<endl;
	cout<<ans[1];
	for(int i=2;i<=n;i++)printf(" %d",ans[i]);
	puts("");
}