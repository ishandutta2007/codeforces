//This code was made by Chinese_zjc_
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
string s,a;
int ans,len;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>s;
	len=s.length();
	ans=len>>1;
	if(len%2==1)
	{
		for(int i=1;i<len;++i)
		{
			if(s[i]=='1')
			{
				++ans;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}