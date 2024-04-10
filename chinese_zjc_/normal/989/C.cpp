//This code was made by Chinese_zjc_
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int a,b,c,d;
char s[51][51];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>a>>b>>c>>d;
	cout<<"50 50\n";
	for(int i=1;i<=25;++i)
	{
		fill(s[i]+1,s[i]+26,'D');
		fill(s[i]+26,s[i]+51,'A');
	}
	for(int i=26;i<=50;++i)
	{
		fill(s[i]+1,s[i]+51,'A');
	}
	--a;
	--d;
	for(int i=0;i<a;++i)
	{
		s[(((i<<1)/24)<<1)+1][(i<<1)%24+1]='A';
	}
	for(int i=0;i<b;++i)
	{
		s[(((i<<1)/24)<<1)+1][(i<<1)%24+26]='B';
	}
	for(int i=0;i<c;++i)
	{
		s[(((i<<1)/24)<<1)+26][(i<<1)%24+1]='C';
	}
	for(int i=0;i<d;++i)
	{
		s[(((i<<1)/24)<<1)+26][(i<<1)%24+26]='D';
	}
	for(int i=1;i<=50;++i)
	{
		for(int j=1;j<=50;++j)
		{
			cout<<s[i][j];
		}
		cout<<endl;
	}
	return 0;
}