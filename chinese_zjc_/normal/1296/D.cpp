//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,k,a,b,ans,s[200001];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>a>>b>>k;
	for(int i=1;i<=n;++i)
	{
		cin>>s[i];
		s[i]%=a+b;
		if(s[i]==0)
		{
			s[i]=a+b;
		}
	}
	sort(s+1,s+1+n);
	for(int i=1;i<=n;++i)
	{
		k-=s[i]/a-(s[i]%a==0);
		if(k<0)
		{
			break;
		}
		++ans;
	}
	cout<<ans;
	return 0;
}