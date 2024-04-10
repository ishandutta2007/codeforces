//This code was made by Chinese_zjc_
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,l,r,ans1,ans2;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>l>>r;
	for(int i=1,x=1;i<=l;++i,x<<=1)
	{
		ans1+=x;
	}
	ans1+=(n-l);
	for(int i=1,x=1;i<=r;++i,x<<=1)
	{
		ans2+=x;
	}
	ans2+=(1<<(r-1))*(n-r);
	cout<<ans1<<" "<<ans2;
	return 0;
}