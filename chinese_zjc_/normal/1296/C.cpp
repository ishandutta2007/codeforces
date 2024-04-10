//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
struct S{
	int x,y,p;
	bool operator < (const S tmp)const
	{
		return x==tmp.x?(y==tmp.y?p<tmp.p:y<tmp.y):x<tmp.x;
	}
}sum[200001];
int t,n,ans1,ans2,now;
string s;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>t;
	while(t)
	{
		--t;
		cin>>n;
		cin>>s;
		s=' '+s;
		sum[0].x=0;
		sum[0].y=0;
		sum[0].p=0;
		ans1=200001;
		ans2=INF;
		for(int i=1;i<=n;++i)
		{
			sum[i]=sum[i-1];
			++sum[i].p;
			if(s[i]=='U')
			{
				++sum[i].y;
			}
			else
			if(s[i]=='D')
			{
				--sum[i].y;
			}
			else
			if(s[i]=='L')
			{
				--sum[i].x;
			}
			else
			if(s[i]=='R')
			{
				++sum[i].x;
			}
		}
		sort(sum,sum+1+n);
		for(int i=0;i<n;++i)
		{
			if(sum[i].x==sum[i+1].x&&sum[i].y==sum[i+1].y&&sum[i+1].p-sum[i].p<ans2-ans1)
			{
				ans1=sum[i].p+1;
				ans2=sum[i+1].p;
			}
		}
		if(ans2==INF)
		{
			cout<<-1<<endl;
		}
		else
		{
			cout<<ans1<<' '<<ans2<<endl;
		}
	}
	return 0;
}