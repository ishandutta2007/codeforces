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
bool can[3005][3005];
int dp[3005],pre[3005],n,m,i,j,ans,l,cnt;
char sam;
string st;
void print(int x,int y)
{
	if (x>1)
	{
		print(pre[x-1]+1,x);
		cout<<' ';
	}
	int i;
	for (i=x;i<y;i++) cout<<st[i];
}
int main()
{
	cin>>st;
	st=" "+st;
	l=st.length();
	for (i=0;i<l;i++)
	{
		for (j=0;j<l;j++)
		{
			can[i][j]=1;
		}
	}
	for (i=1;i<l;i++)
	{
		cnt=0;sam='0';
		for (j=i;j<l;j++)
		{
			if (can[i][j-1]==0)
			{
				can[i][j]=0;
				continue;
			}
			if (st[j]=='a'||st[j]=='e'||st[j]=='i'||st[j]=='o'||st[j]=='u')
			{
				cnt=0;
				sam='0';
			}
			else
			{
				cnt++;
				if (sam=='0') sam=st[j];
					else if (sam!=st[j]) sam='1';
			}
			if (cnt>=3&&sam=='1')
			{
				can[i][j]=0;
			}
		}
	}
	for (i=1;i<=3000;i++) dp[i]=1<<30;
	for (i=1;i<l;i++)
	{
		for (j=0;j<i;j++)
		{
			if (can[j+1][i]&&dp[j]<dp[i])
			{
				dp[i]=dp[j];
				pre[i]=j;
			}
		}
		dp[i]++;
	}
	print(pre[l-1]+1,l);
	return 0;
}