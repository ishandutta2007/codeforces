#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
using namespace std;
int main()
{
	int n;
	int a[300000];
	int ans[300000];
	int tmp;
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	tmp=-1;
	for(int i=1;i<=n;i++)
	{
		if (a[i]==0)tmp=i;
		if (tmp==-1)ans[i]=2147483647;
		else ans[i]=(i-tmp);
	}
	tmp=-1;
	for(int i=n;i>=1;i--)
	{
		if (a[i]==0)tmp=i;
		if (tmp!=-1)ans[i]=min(ans[i],tmp-i);
	}
	for(int i=1;i<n;i++)printf("%d ",ans[i]);
	printf("%d\n",ans[n]);
	return 0;
}