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
int n,m,i,j,cnt[5],num[10005];
int main()
{
	cin>>m>>n;
	cnt[4]=m;cnt[2]=m*2;
	for (i=1;i<=n;i++)
	{
		cin>>num[i];
	}
	for (i=1;i<=n;i++)
	{
		while (cnt[4]&&num[i]>=4)
		{
			cnt[4]--;
			num[i]-=4;
		}
	}
	sort(num+1,num+n+1);
	reverse(num+1,num+n+1);
	for (i=1;i<=n;i++)
	{
		while (cnt[4]&&num[i]==3)
		{
			cnt[4]--;
			num[i]=0;
		}
		while (cnt[2]&&num[i]>0)
		{
			cnt[2]--;
			num[i]-=2;
		}
	}
	for (i=1;i<=n;i++)
	{
		while (cnt[4]&&num[i]<=2&&num[i]>0)
		{
			cnt[4]--;
			if (num[i]==1) cnt[2]++; 
				else cnt[1]++;
			num[i]=0;
		}
	}
	for (i=1;i<=n;i++)
	{
		while (cnt[2]&&num[i]>1)
		{
			cnt[2]--;
			num[i]-=2;
		}
		while (cnt[1]&&num[i]>0)
		{
			num[i]--;
			cnt[1]--;
		}
		while (cnt[2]&&num[i]>0)
		{
			cnt[2]--;
			num[i]-=2;
		}
	}
	for (i=1;i<=n;i++)
	{
		if (num[i]>0)
		{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	return 0;
}