#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
#include <map>
#include <cassert>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
int get(int st,int k,int limit)
{
	int l=st+1; 
	int r=2*st;  if (st==0)r=limit;
	if (1ll*(l+l+k-1)*k/2>limit)return -1;
	while (l<r)
	{
		int mid=(l+r)/2 + 1;
		int flag=0;
		if (1ll*(mid+mid+k-1)*k/2<=limit)l=mid;
		else r=mid-1;
	}
	long long now=0;
	long long t=1;
	for(int i=1;i<=k;i++)
	{
		now=now+t*l;
		t<<=1;
		if (now>=limit)return l;
	}
	return -1;
}
int main()
{
	int n,k;
	cin>>n>>k;
	if (get(0,k,n)==-1){ puts("NO"); return 0; }
	int pre=0;
	puts("YES");
	for(int i=1;i<=k;i++)
	{
		if (i!=1)putchar(' ');
		int t=get(pre,k-i+1,n);
		assert(t!=-1);
		printf("%d",t);
		n-=t;
		pre=t;
	}
	puts("");
	return 0;
}