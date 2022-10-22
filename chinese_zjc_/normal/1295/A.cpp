//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,now;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	while(n)
	{
		--n;
		cin>>now;
		if(now&1)
		{
			cout<<7;
			now-=3;
		}
		while(now)
		{
			cout<<1;
			now-=2;
		}
		cout<<endl;
	}
	return 0;
}