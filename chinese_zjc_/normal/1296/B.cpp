//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int s[10],t,n,sum;
string a;
int power(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
		{
			ans*=a;
		}
		b>>=1;
		a*=a;
	}
	return ans;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>t;
	while(t)
	{
		--t;
		sum=0;
		cin>>a;
		n=a.length();
		a=' '+a;
		for(int i=1;i<=n>>1;++i)
		{
			swap(a[i],a[n-i+1]);
		}
		for(int i=1;i<=n;++i)
		{
			s[i]=a[i]-'0';
		}
		for(int i=n,j=power(10,n-1);i>0;--i,j/=10)
		{
			while(s[i])
			{
				s[i-1]+=s[i];
				sum+=s[i]*j;
				s[i]=s[i-1]/10;
				s[i-1]%=10;
				s[0]=0;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}