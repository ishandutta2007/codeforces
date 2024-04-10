// By: Little09
// Problem: F1. Alice and Recoloring 1
// Contest: Codeforces - Codeforces Round #746 (Div. 2)
// URL: https://codeforces.ml/contest/1592/problem/F1
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

const int N=505;
int n,m,T; 
int a[N][N],sum[N][N],c[N][N],w[N][N];

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

int main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			char x=readchar();
			if (x=='W') a[i][j]=0;
			else a[i][j]=1;
		}
	}
	for (int i=n;i>=1;i--)
	{
		for (int j=m;j>=1;j--)
		{
			int s=(sum[i+1][j+1]^sum[i][j+1]^sum[i+1][j]);
			sum[i][j]=a[i][j];
			c[i][j]=(s^a[i][j]);
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			ans+=c[i][j];
		}
	}
	if (c[n][m]==1)
	{
		for (int i=1;i<n;i++)
		{
			for (int j=1;j<m;j++)
			{
				if (c[i][j]==1&&c[i][m]==1&&c[n][j]==1)
				{
					printf("%d\n",ans-1);
					return 0;
				}
			}
		}	
	}
	printf("%d\n",ans);
	return 0;
}