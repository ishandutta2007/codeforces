#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define LL long long
using namespace std;
int n;
int a[110000];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	if (a[1]==a[2]&&a[2]==a[3])
	{
		LL tmp=0;
		for(int i=1;i<=n;i++)
			if (a[1]==a[i])tmp++;else break;
		cout<<tmp*(tmp-1)*(tmp-2)/6<<endl;
	}
	else
	if (a[1]==a[2])
	{
		LL tmp=0;
		for(int i=3;i<=n;i++)
			if (a[3]==a[i])tmp++; else break;
		cout<<tmp<<endl;
	}
	else
	if (a[2]==a[3])
	{
		LL tmp=0;
		for(int i=2;i<=n;i++)
			if (a[2]==a[i])tmp++; else break;
		cout<<tmp*(tmp-1)/2<<endl;
	}
	else
	{
		LL tmp=0;
		for(int i=3;i<=n;i++)
			if (a[3]==a[i])tmp++; else break;
		cout<<tmp<<endl;
	}
	return 0;
}