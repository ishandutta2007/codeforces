//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<iomanip>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,p,a[100005],Max,Min;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>p;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)
	{
		Min=max(Min,a[i]-i+1);
	}
	Max=a[p]-0;
	for(int i=1;i+p<=n;++i)
	{
		Max=min(Max,a[i+p]-i);
	}
	cout<<max(Max-Min,0ll)<<endl;
	for(int i=Min;i<Max;++i)
	{
		cout<<i<<' ';
	}
	cout<<endl;
	return 0;
}