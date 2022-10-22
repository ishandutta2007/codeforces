//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
string a,now,md;
int n,k;
bool can[200001],flag;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>k>>a;
	cout<<n<<endl;
	now=a.substr(0,k);
	flag=true;
	for(int i=0;i<n;++i)
	{
		if(now[i%k]<a[i])
		{
			++now[k-1];
			for(int j=k-1;now[j]>'9';--j)
			{
				now[j]-=10;
				++now[j-1];
			}
			flag=false;
			break;
		}
		if(now[i%k]>a[i])
		{
			break;
		}
	}
	if(flag)
	{
		for(int i=0;i<n;++i)
		{
			cout<<now[i%k];
		}
		return 0;
	}
	for(int l=1;l<=k;++l)
	{
		flag=true;
		for(int i=0;i<n;++i)
		{
			if(now[i%k]<a[i])
			{
				now[k-l]+=9;
				for(int j=k-l;now[j]>'9';--j)
				{
					now[j]-=10;
					++now[j-1];
				}
				flag=false;
				break;
			}
			if(now[i%k]>a[i])
			{
				break;
			}
		}
		if(flag)
		{
			for(int i=0;i<n;++i)
			{
				cout<<now[i%k];
			}
			return 0;
		}
	}
	return 0;
}