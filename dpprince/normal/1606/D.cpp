// By: Little09
// Problem: D. Red-Blue Matrix
// Contest: Codeforces - Educational Codeforces Round 116 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1606/problem/D
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes puts("Yes")
#define printYES puts("YES")
#define printNo puts("No")
#define printNO puts("NO")

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m,T; 
struct point
{
	vector<int>a;
	int id;
}b[N];
bool cmp(point x,point y)
{
	return x.a[1]<y.a[1];
}
vector<int>dp[4][N];
int f[2][N];
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
inline char readchar()
{
	char C=getchar();
    while (C<33||C>126) C=getchar();
    return C;
}
inline int raed(){return read();}
char w[N];
void print(int x)
{
	puts("YES");
	for (int i=1;i<=n;i++)
	{
		if (i<=x) w[b[i].id]='B';
		else w[b[i].id]='R';
	}
	for (int i=1;i<=n;i++) printf("%c",w[i]);
}
void work()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) b[i].a.clear();
	for (int i=1;i<=n;i++) 
	{
		for (int j=0;j<4;j++)
		{
			dp[j][i].clear();
		}
	}
	for (int i=1;i<=n;i++)
	{
		b[i].a.push_back(0);
		for (int j=0;j<4;j++) dp[j][i].push_back(0);
		for (int j=1;j<=m;j++)
		{
			int x=read();
			b[i].a.push_back(x);
			for (int k=0;k<4;k++) dp[k][i].push_back(0);
		}
		b[i].id=i;
	}
	sort(b+1,b+n+1,cmp);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (i==1&&j==1) dp[0][i][j]=b[i].a[j];
			else if (i==1) dp[0][i][j]=max(max(dp[0][i][j-1],0),b[i].a[j]);
			else if (j==1) dp[0][i][j]=max(max(0,dp[0][i-1][j]),b[i].a[j]);
			else dp[0][i][j]=max(max(dp[0][i][j-1],dp[0][i-1][j]),b[i].a[j]);
		}
	}
	for (int i=n;i>=1;i--)
	{
		for (int j=1;j<=m;j++)
		{
			if (i==n&&j==1) dp[1][i][j]=b[i].a[j];
			else if (j==1) dp[1][i][j]=min(min(100000000,dp[1][i+1][j]),b[i].a[j]);
			else if (i==n) dp[1][i][j]=min(min(dp[1][i][j-1],100000000),b[i].a[j]);
			else dp[1][i][j]=min(min(dp[1][i][j-1],dp[1][i+1][j]),b[i].a[j]);
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=m;j>=1;j--)
		{
			if (i==1&&j==m) dp[2][i][j]=b[i].a[j];
			else if (i==1) dp[2][i][j]=min(min(dp[2][i][j+1],100000000),b[i].a[j]);
			else if (j==m) dp[2][i][j]=min(min(100000000,dp[2][i-1][j]),b[i].a[j]);
			else dp[2][i][j]=min(min(dp[2][i][j+1],dp[2][i-1][j]),b[i].a[j]);
		}
	}
	for (int i=n;i>=1;i--)
	{
		for (int j=m;j>=1;j--)
		{
			if (i==n&&j==m) dp[3][i][j]=b[i].a[j];
			else if (i==n) dp[3][i][j]=max(max(dp[3][i][j+1],0),b[i].a[j]);
			else if (j==m) dp[3][i][j]=max(max(0,dp[3][i+1][j]),b[i].a[j]);
			else dp[3][i][j]=max(max(dp[3][i][j+1],dp[3][i+1][j]),b[i].a[j]);
		}
	}
	for (int i=1;i<n;i++)
	{
		for (int j=1;j<m;j++)
		{
			if (dp[0][i][j]<dp[1][1+i][j]&&dp[2][i][j+1]>dp[3][i+1][j+1])
			{
				print(i);
				printf(" %d\n",j);
				return;
			}
		}
	}
	puts("NO");
	return;
}

int main()
{
	int tp=0;
	//0 : many test cases
	//1 : one test case
	if (tp==0) T=read();
	else T=1;
	while (T--)
	{
		work();
	}
	return 0;
}