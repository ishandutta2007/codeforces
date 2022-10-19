#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define prt(n) cout<<(n)<<endl
#define elif else if
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
string ans(string b,int len)
{
	string d="",a="";
	rep(i,len)
	{
		
		if(i==0)
		{
			if(b[i]=='0')
			{
				a+='1';
				d+='1';
			}
			else
			{
				a+='1';
				d+='2';
			}
		}
		else
		{
			if(b[i]=='0')
			{
				if(d[i-1]=='1')
				{
					a+='0';
					d+='0';
				}
				else
				{
					a+='1';
					d+='1';
				}
			}
			else
			{
				if(d[i-1]=='2')
				{
					a+='0';
					d+='1';
				}
				else
				{
					a+='1';
					d+='2';
				}
			}
		}
	}
	return a;
}
int main()
{
	ios::sync_with_stdio(false);
	int a,len;
	string b;
	cin>>a;
	while(a--)
	{
		cin>>len>>b;
		prt(ans(b,len));
	}
	return 0;
}