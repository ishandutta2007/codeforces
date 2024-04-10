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
int num[100005],l[100005],r[100005],n,m,i,j;
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for (i=1;i<=n;i++) cin>>num[i];
	if (m==1)
	{
		int mx=1<<30;
		for (i=1;i<=n;i++) mx=min(mx,num[i]);
		cout<<mx;
		return 0;
	}
	else if (m==2)
	{
		l[0]=r[n+1]=1<<30;
		for (i=1;i<=n;i++)
		{
			l[i]=min(l[i-1],num[i]);
		}
		for (i=n;i;i--)
		{
			r[i]=min(r[i+1],num[i]);
		}
		int mx=-1<<30;
		for (i=1;i<n;i++)
		{
			mx=max(mx,max(l[i],r[i+1]));
		}
		cout<<mx;
		return 0;
	}
	int mx=-1<<30;
	for (i=1;i<=n;i++) mx=max(mx,num[i]);
	cout<<mx;
	return 0;
}