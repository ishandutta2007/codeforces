//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int t,n,sum;
string s;
string wei(string a)
{
	string tmp="";
	for(int i=a.length()-1;i>=0;--i)
	{
		if((a[i]-'0')&1)
		{
			for(int j=0;j<=i;++j)
			{
				tmp+=a[j];
			}
			return tmp;
		}
	}
	return tmp;
}
string he(string a)
{
	int sum=0,len=a.length();
	for(int i=len-1;i>=0;--i)
	{
		sum+=a[i]-'0';
	}
	if(sum&1)
	{
		string tmp="";
		for(int i=len-2;i>=0;--i)
		{
			if((a[i]-'0')&1)
			{
				for(int j=0;j<i;++j)
				{
					tmp+=a[j];
				}
				for(int j=i+1;j<len;++j)
				{
					tmp+=a[j];
				}
				return tmp;
			}
		}
		return tmp;
	}
	else
	{
		return a;
	}
}
string qu0(string a)
{
	int len=a.length();
	string tmp="";
	for(int i=0;i<len;++i)
	{
		if(a[i]!='0')
		{
			for(int j=i;j<len;++j)
			{
				tmp+=a[j];
			}
			return tmp;
		}
	}
	return tmp;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>t;
	while(t)
	{
		--t;
		cin>>n>>s;
		s=wei(s);
		s=he(s);
		s=qu0(s);
		cout<<(s==""?"-1":s)<<endl;
	}
	return 0;
}