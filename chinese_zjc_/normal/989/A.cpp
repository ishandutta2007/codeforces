//This code was made by Chinese_zjc_
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
string s;
int len;
bool has[3][105];
void doit(int a,char b)
{
	has[b-'A'][a]=true;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>s;
	s="."+s+".";
	len=s.length();
	for(int i=1;i<len-1;++i)
	{
		if(s[i]=='.')
		{
			continue;
		}
		doit(i-1,s[i]);
		doit(i,s[i]);
		doit(i+1,s[i]);
	}
	for(int i=0;i<len;++i)
	{
		if(has[0][i]&&has[1][i]&&has[2][i])
		{
			puts("Yes");
			return 0;
		}
	}
	puts("No");
	return 0;
}