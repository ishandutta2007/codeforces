#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<set>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,x,cnt[1000005],a;
bool no[1000005];
set<int> used;
int main()
{
	cin>>n>>a;
	for (i=1;i<=n;i++)
	{
		cin>>x;
		cnt[x]++;
		if (cnt[x]-1<cnt[a]) no[x]=1;
		used.insert(x);
	}
	for (i=1;i<=1000000;i++)
	{
		if (i!=m&&!no[i]&&cnt[i]>=cnt[a]&&used.count(i))
		{
			cout<<i;
			return 0;	
		}
	}
	cout<<-1;
	return 0;
}