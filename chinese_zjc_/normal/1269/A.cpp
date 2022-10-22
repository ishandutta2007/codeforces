//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,a,b;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	b=4;
	a=n+4;
	while(true)
	{
		b+=2;
		a+=2;
		if(a%3==0)
		{
			cout<<a<<' '<<b;
			return 0;
		}
	}
	return 0;
}