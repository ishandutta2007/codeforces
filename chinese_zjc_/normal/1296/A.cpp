//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int t,n,a[2001],sum;
bool odd,even;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>t;
	while(t)
	{
		--t;
		cin>>n;
		odd=false;
		even=false;
		sum=0;
		for(int i=1;i<=n;++i)
		{
			cin>>a[i];
			if(a[i]&1)
			{
				odd=true;
			}
			else
			{
				even=true;
			}
			sum+=a[i];
		}
		if(sum&1)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			if(odd&&even)
			{
				cout<<"YES"<<endl;
			}
			else
			{
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}