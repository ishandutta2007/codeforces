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
	int n,m;
	int a[11000];
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int j,l,r,x,cnt;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&l,&r,&x);
		cnt=0;
		for(j=l;j<=r;j++)
			if (a[j]<=a[x])cnt++;
		if (cnt!=x-l+1)cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}