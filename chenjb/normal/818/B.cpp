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
#define LL long long 
#define inf 1000000007
using namespace std;
int n,m;
int l[110];
int a[110];
int tmp[110];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>l[i];
	int flag=1;
	memset(a,255,sizeof(a));
	for(int i=2;i<=m;i++)
	{
		int t=l[i]-l[i-1];
		if (t<=0)t=n-l[i-1]+l[i];
		if (a[l[i-1]]==-1){ a[l[i-1]]=t; continue; }
		else if (a[l[i-1]]!=t)flag=0;
	}
	memset(tmp,0,sizeof(tmp));
	for(int i=1;i<=n;i++)
	{
		if (a[i]==-1)continue;
		if (a[i]<=0||a[i]>n)flag=0;
		if (!tmp[a[i]]){ tmp[a[i]]=1; continue; }
		if (tmp[a[i]])flag=0;
	}
	for(int i=1;i<=n;i++)
	{
		if (a[i]==-1)
			for(int j=1;j<=n;j++)
				if (!tmp[j])
				{
					a[i]=j;
					tmp[j]=1;
					break;
				}
	}
	if (!flag)cout<<-1<<endl;
	else
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	return 0;
}