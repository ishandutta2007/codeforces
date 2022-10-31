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
int n;
int a[5100];
int f[5100];
int last[5100],first[5100],v[5100];
int main()
{	

	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	memset(last,255,sizeof(last));
	for(int i=1;i<=n;i++)last[a[i]]=i;
	memset(first,255,sizeof(first));
	for(int i=n;i>=1;i--)first[a[i]]=i;
	f[0]=0;
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1];
		if (i!=last[a[i]])continue;
		memset(v,0,sizeof(v));
		int now=0;
		int tmp=first[a[i]];
		int flag=1;
		for(int j=i;j>=tmp;j--)
		{
			if (!v[a[j]])now^=a[j];
			tmp=min(tmp,first[a[j]]);
			if (last[a[j]]>i)flag=0;
			v[a[j]]=1;
		}
		if (!flag)continue;
		for(int j=first[a[i]];j>=1;j--)
		{
			if (!v[a[j]])now^=a[j];
			tmp=min(tmp,first[a[j]]);
			if (last[a[j]]>i)break;
			if (j<=tmp)f[i]=max(f[i],f[j-1]+now);
		}
	}
	cout<<f[n]<<endl;
	return 0;
}