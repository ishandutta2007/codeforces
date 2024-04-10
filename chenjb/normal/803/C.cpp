#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#define LL long long
LL max(LL a,LL b)
{
	if (a>b)return a; else return b;
}
using namespace std;
int main()
{
	LL n,k;
	LL ansp=0;
	cin>>n>>k;
	if (k>=200000)ansp=0;
	else
	{
		LL t=(LL)(1+k)*k/2;
		LL maxp=n/t;
		LL p;
		int flag=0;
		for(int i=(int)(sqrt(n));i>=1;i--)
		if (n%i==0)
		{
			p=n/i;
			if (p>=t)ansp=max(ansp,i);
			if (i>=t)ansp=max(ansp,p);
		}
	}
	if (ansp==0)printf("-1\n");
	else
	{
		for(LL i=1;i<k;i++)
		{
			printf("%I64d ",i*ansp);
			n=n-i*ansp;
		}
		printf("%I64d\n",n);
	}
	return 0;
}