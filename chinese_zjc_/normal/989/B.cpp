//This code was made by Chinese_zjc_
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,p,i;
string s;
bool flag;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>p;
	cin>>s;
	for(i=0;i<n-p;++i)
	{
		if(s[i]=='.'&&s[i+p]=='.')
		{
			flag=true;
			s[i]='1';
			s[i+p]='0';
			break;
		}
		if(s[i]=='.')
		{
			flag=true;
			s[i]=!(s[i+p]-'0')+'0';
			break;
		}
		if(s[i+p]=='.')
		{
			flag=true;
			s[i+p]=!(s[i]-'0')+'0';
			break;
		}
		if(s[i]!=s[i+p])
		{
			flag=true;
			break;
		}
	}
	if(!flag)
	{
		puts("No");
		return 0;
	}
	for(int i=0;i<n;++i)
	{
		if(s[i]=='.')
		{
			s[i]='0';
		}
	}
	cout<<s;
	return 0;
}