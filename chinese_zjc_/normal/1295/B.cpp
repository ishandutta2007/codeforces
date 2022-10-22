//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int t,n,x,cnt,Max,Min,ans,now;
string s;
bool flag;
signed main()
{
//	std::ios::sync_with_stdio(false);
	cin>>t;
	while(t)
	{
		--t;
		cin>>n>>x;
		cin>>s;
		cnt=0;
		ans=0;
		for(int i=0;i<n;++i)
		{
			if(s[i]=='0')
			{
				++cnt;
			}
			else
			{
				--cnt;
			}
		}
		flag=false;
		now=0;
		for(int i=0;i<n;++i)
		{
			if(cnt==0)
			{
				if(now==x)
				{
					flag=true;
					break;
				}
			}
			else
			{
				if((x-now)%cnt==0&&(x-now)*cnt>=0)
				{
					++ans;
				}
			}
			if(s[i]=='0')
			{
				++now;
			}
			else
			{
				--now;
			}
		}
		if(flag)
		{
			ans=-1;
		}
		cout<<ans<<endl;
	}
	return 0;
}