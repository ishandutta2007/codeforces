//"n _with_stdio(0);   " !!!!!!
#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
long long n,m,l,r,mid,num[5],pri[5],need[5],ans,i;
string st;
bool check(long long x)
{
	long long i,t=m;
	for (i=1;i<=3;i++)
	{
		t-=max(0ll,(x*need[i]-num[i])*pri[i]);
	}
	return t>=0;
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>st;
	for (i=0;i<st.length();i++)
	{
		if (st[i]=='B') need[1]++;
		if (st[i]=='S') need[2]++;
		if (st[i]=='C') need[3]++;
	}
	for (i=1;i<=3;i++) cin>>num[i]; 
	for (i=1;i<=3;i++) cin>>pri[i]; 
	cin>>m;
	l=0;r=1e15;
	while (l<r)
	{
		mid=(l+r)/2;
		if (check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else r=mid;
	}
	cout<<ans;
	return 0;
}