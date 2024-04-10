//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int t,n,a[300001],Max;
bool flag;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>t;
	while(t)
	{
		--t;
		cin>>n;
		Max=n;
		for(int i=1;i<=n;++i)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;++i)
		{
			if(a[i]<i-1)
			{
				Max=i-1;
				break;
			}
		}
		flag=true;
		for(int i=Max+1;i<=n;++i)
		{
			a[i]=min(a[i],a[i-1]-1);
			if(a[i]<0)
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
	return 0;
}