// By: Little09
// Problem: F. RBS
// Contest: Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1598/problem/F
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int n;
const int inf=1e9,N=25,M=4e5+5,S=4e6+5;
struct point
{
	int w,sum;
	vector<int>t;
}a[N];
inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}
char s[M];
int dp[S],ans;
inline char readchar()
{
	char C=getchar();
    while (C<33||C>126) C=getchar();
    return C;
}
inline int raed(){return read();}
int main()
{
	n=read();
	for (int i=0;i<n;i++)
	{
		scanf("%s",s+1);
		int len=strlen(s+1);
		int tot=0,res=0;
		for (int j=0;j<=len;j++) a[i].t.push_back(0);
		for (int j=1;j<=len;j++)
		{
			if (s[j]=='(') tot++;
			else tot--;
			if (tot<=res) 
			{
				res=tot;
				a[i].t[-tot]++;
			}
		}
		a[i].w=-res;
		a[i].sum=tot;
		// for (int j=1;j<=len;j++)
		// {
			// cout << a[i].t[j] << " ";
		// }
		// cout << endl;
	}
	for (int i=1;i<=(1<<n)-1;i++) dp[i]=-inf;
	dp[S]=0;
	for (int i=1;i<=(1<<n)-1;i++)
	{
		int sum=0;
		for (int j=0;j<n;j++)
		{
			if (((1<<j)&i)==0) continue;
			sum+=a[j].sum;
		}
		for (int j=0;j<n;j++)
		{
			if (((1<<j)&i)==0) continue;
			sum-=a[j].sum;
			int k=((1<<j)^i);
			if (sum<0) 
			{
				sum+=a[j].sum;
				continue;
			}
			if (dp[k]<0)
			{
				sum+=a[j].sum;
				continue;
			}
			if (sum>a[j].w) 
			{
				dp[i]=max(dp[i],dp[k]);
				sum+=a[j].sum;
				continue;
			}
			if (sum==a[j].w)
			{
				dp[i]=max(dp[i],dp[k]+a[j].t[sum]);
				sum+=a[j].sum;
				continue;
			}
			ans=max(ans,dp[k]+a[j].t[sum]);
			sum+=a[j].sum;
		}
		ans=max(ans,dp[i]);
	}
	cout << ans << endl;
	return 0;
}