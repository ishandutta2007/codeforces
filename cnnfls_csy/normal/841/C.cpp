#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
struct ii
{
	int ans,x,id;
}num[200005];
bool cmp(ii x,ii y)
{
	if (x.x>y.x) return 1;
	if (x.x<y.x) return 0;
	return x.id<y.id;
}
bool cmp2(ii x,ii y)
{
	if (x.id<y.id) return 1;
	if (x.id>y.id) return 0;
	return x.ans<y.ans;
}
int n,k,i,j,na[200005];
int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>na[i];
	}
	for (i=1;i<=n;i++)
	{
		cin>>num[i].x;
	}
	for (i=1;i<=n;i++)
	{
		num[i].id=i;
	}
	sort(num+1,num+n+1,cmp);
	sort(na+1,na+n+1);
	//reverse(na+1,na+n+1);
	for (i=1;i<=n;i++)
	{
		num[i].ans=na[i];
	}
	sort(num+1,num+n+1,cmp2);
	for (i=1;i<=n;i++)
	{
		cout<<num[i].ans<<' ';
	}
	return 0;
}