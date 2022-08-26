#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include<iomanip>
#define sqr(x) (x)*(x)
#define ll long long
using namespace std;
struct letter
{
	int h,w,id;
}le[5005];
int n,w,h,i,j,dp[5005],pr[5005],cnt,ans;
bool cmp(letter x,letter y)
{
	if (x.h<y.h) return 1;
	if (x.h>y.h) return 0;
	return x.w<y.w;
}
void print(int x)
{
	if (pr[x]) print(pr[x]);
	cout<<le[x].id<<' ';
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>w>>h;
	for (i=1;i<=n;i++)
	{
		cnt++;
		cin>>le[cnt].w>>le[cnt].h;
		le[cnt].id=i;
		//if (le[cnt].w<=w||le[cnt].h<=h) cnt--;
	}
	sort(le+1,le+cnt+1,cmp);
	for (i=1;i<=cnt;i++)
	{
		if (le[i].w<=w||le[i].h<=h) continue;
		pr[i]=0;
		for (j=1;j<i;j++)
		{
			if (le[j].w<le[i].w&&le[j].h<le[i].h&&dp[j]>dp[i]&&le[j].w>w&&le[j].h>h)
			{
				dp[i]=max(dp[i],dp[j]);
				pr[i]=j;
			}
		}
		dp[i]++;
	}
	ans=1;
	for (i=2;i<=cnt;i++)
	{
		if (dp[i]>dp[ans]) 
		{
			ans=i;
		}
	}
	cout<<dp[ans]<<endl;
	if (dp[ans]) print(ans);
	return 0;
}