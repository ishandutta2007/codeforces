#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#define LL long long
using namespace std;
LL a,b;
int judge(LL x,LL y)
{
	if (x==1&&y==1)return 1;
	LL p=x*y;
	LL l=1;
	LL r=1000001;
	LL mid;
	while (l<r)
	{
		mid=(l+r)/2 + 1;
		if (mid*mid*mid>p)r=mid-1;
		else l=mid;
	}
	if (l*l*l!=p)return 0;
	if (x%l==0&&y%l==0)return 1;
	return 0;
}
int main()
{
	//freopen("1.in","r",stdin);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d%I64d",&a,&b);
		if (judge(a,b)==1)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}