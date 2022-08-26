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
long long n,m,i,j,x,lst;
vector<long long> seq[100005],ans;
long long hibit(long long x)
{
	long long i;
	for (i=61;i>=0;i--)
	{
		if ((1ll<<i)&x) return i;
	}
}
int main()
{
	scanf("%I64d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%I64d",&x);
		seq[hibit(x)].push_back(x);
	}
	lst=0;
	for (i=1;i<=n;i++)
	{
		for (j=0;j<=61;j++)
		{
			if (seq[j].empty()) continue;
			if ((1ll<<j)&lst) continue;
			x=seq[j].back();
			seq[j].pop_back();
			ans.push_back(x);
			lst^=x;
			break;
		}
		if (j>61)
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	for (i=1;i<=n;i++) printf("%I64d ",ans[i-1]);
	return 0;
}