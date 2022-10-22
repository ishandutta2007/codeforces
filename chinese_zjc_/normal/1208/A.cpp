//This code was made by Chinese_zjc_
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int t,f[100001],n,s,x;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>t;
	while(t)
	{
		--t;
		cin>>f[0]>>f[1]>>n;
		s=0;
		for(int i=2;i<=n;++i)
		{
			f[i]=f[i-1]^f[i-2];
			for(int j=1;j<i;++j)
			{
				if(f[j-1]==f[i-1]&&f[j]==f[i])
				{
					s=i-j;
					x=j-1;
					break;
				}
			}
			if(s)
			{
				cout<<f[(n-x)%s+x]<<endl;
				break;
			}
		}
		if(!s)
		{
			cout<<f[n]<<endl;
		}
	}
	return 0;
}