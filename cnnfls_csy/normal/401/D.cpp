#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<map>
#include<set>
#define sqr(x) (x)*(x)
using namespace std;
int m,i,j,mul[15];
long long n,dp[105][500005];
vector<int> all;
set<int> vis;
int hsh(vector<int> cnt)
{
	int i,ans=cnt[0];
	for (i=1;i<=9;i++)
	{
		ans+=mul[i-1]*cnt[i];
	}
	return ans;
}
bool check0(int cnt)
{
	if (cnt%mul[0]==0) return 0;
	int i;
	for (i=1;i<=9;i++)
	{
		if (cnt/mul[i-1]%(all[i]+2)!=0) return 0;
	}
	return 1;
}
bool check1(int cnt)
{
	return cnt==0;
}
void dfs(int cnt)
{
	if (vis.count(cnt)) return;
	if (check0(cnt)) return;
	if (check1(cnt))
	{
		dp[0][cnt]=1;
		return;
	}
	vis.insert(cnt);
	int i;
	for (i=0;i<=9;i++)
	{
		if (i) if (cnt/mul[i-1]%(all[i]+2)==0) continue;
		if (!i) if (cnt%mul[0]==0) continue;
		int nxt=cnt;
		if (i) nxt-=mul[i-1]; else nxt--;
		dfs(nxt);
		for (j=0;j<m;j++)
		{
			dp[(j*10+i)%m][cnt]+=dp[j][nxt];
		}
	}
}
int main()
{
	cin>>n>>m;
	for (i=1;i<=10;i++) all.push_back(0);
	while (n)
	{
		all[n%10]++;
		n/=10;
	}
	mul[0]=all[0]+2;
	for (i=1;i<=9;i++) mul[i]=mul[i-1]*(all[i]+2);
	dfs(hsh(all));
	cout<<dp[0][hsh(all)];
	return 0;
}