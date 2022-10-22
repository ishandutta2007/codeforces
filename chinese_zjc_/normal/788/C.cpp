//This code was made by Chinese_zjc_
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<vector>
#include<stack>
#include<algorithm>
#define int long long
#define INF (1ll<<62)
using namespace std;
int n,m,dp[5000001],tmp,Min=INF,Max;
bool a[1001],in[5000001];
queue <int> dl;
signed main()
{
	ios::sync_with_stdio(false);
	cin>>m>>n;
	while(n)
	{
		--n;
		cin>>tmp;
		a[tmp]=true;
		Min=min(Min,tmp);
		Max=max(Max,tmp);
	}
//	cout<<Min<<' '<<m<<' '<<Max<<endl;
	if(Min>m||m>Max)
	{
//		cout<<"wtdakioi"<<endl;
cout<<-1<<endl;
		return 0;
	}
	dl.push(2500000);
	while(!in[2500000])
	{
		int now=dl.front();
		for(int i=0;i<=1000;++i)
		{
			if(a[i]&&!in[now-m+i]&&now-m+1>=2499000&&now-m+1<=2501000)
			{
				in[now-m+i]=true;
				dp[now-m+i]=dp[now]+1;
				dl.push(now-m+i);
			}
		}
		dl.pop();
	}
	cout<<dp[2500000]<<endl;
	return 0;
}