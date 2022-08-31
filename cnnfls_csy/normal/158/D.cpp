#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
#define pb push_back
using namespace std;
int n,m,i,j,k,a[100005],s,ma=-1<<25;
vector<int> v;
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (i=1;i<=sqrt(n);i++)
	{
		if (n%i==0)
		{
			v.pb(i);
			if (i!=n/i) v.pb(n/i);
		}
	}
	for (i=0;i<v.size();i++)
	{
		if (n/v[i]>2)
		{
			for (j=1;j<=v[i];j++)
			{
				s=0;
				for (k=1;k<=n/v[i];k++)
				{
					s+=a[v[i]*(k-1)+j];
				}
				ma=max(ma,s);
			}
		}
	}
	cout<<ma;
	return 0;
}