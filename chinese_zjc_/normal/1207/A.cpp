//This code was made by Chinese_zjc_
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int t,p,a,b,ai,bi,ans; 
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>t;
	while(t)
	{
		--t;
		cin>>p>>a>>b>>ai>>bi;
		p>>=1;
		if(ai>bi)
		{
			if(p>a)
			{
				cout<<a*ai+min(p-a,b)*bi<<endl;
			}
			else
			{
				cout<<p*ai<<endl;
			}
		}
		else
		{
			if(p>b)
			{
				cout<<b*bi+min(p-b,a)*ai<<endl;
			}
			else
			{
				cout<<p*bi<<endl;
			}
		}
	}
	return 0;
}