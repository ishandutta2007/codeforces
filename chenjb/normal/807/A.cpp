#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#define LL long long 
#define inf 1000000007
using namespace std;
int main()
{
	int flag1=0,flag2=0;
	int n,a[1010],b[1010];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		if (a[i]!=b[i])flag1=1;
	}
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			if (a[i]<a[j])flag2=1;
	if (flag1)cout<<"rated"<<endl;
	else if (!flag1&&flag2)cout<<"unrated"<<endl;
	else cout<<"maybe"<<endl;
	return 0;
}