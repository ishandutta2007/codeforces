#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#define LL long long 
using namespace std;
int main()
{	
	int a[2000],b[2000],v[2000];
	int n;
	int tmp[2000];
	int tot;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		int pre=a[i];
		int cnt=0;
		for(int j=1;j<=n;j++)
			if (j!=i&&a[j]!=b[j])cnt++;
		if (cnt>1)continue;
		if (cnt==1)a[i]=b[i];
		if (cnt==0)
		{
			memset(v,0,sizeof(v));
			for(int j=1;j<=n;j++)
				if (i!=j)v[a[j]]=1;
			for(int j=1;j<=n;j++)
				if (!v[j]&&j!=pre&&j!=b[i])
				{
					a[i]=j;
					break;
				}
		}
		int shit=1;
		memset(v,0,sizeof(v));
		for(int j=1;j<=n;j++)
			if (!v[a[j]])v[a[j]]=1; else shit=0;
		if (shit)break;
		a[i]=pre;
	}
	cout<<a[1];
	for(int i=2;i<=n;i++)cout<<" "<<a[i];
}