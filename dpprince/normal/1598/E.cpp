// By: Little09
// Problem: E. Staircases
// Contest: Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1598/problem/E
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

const int N=1005;
ll n,m,q,sum; 
int a[N][N];
ll dp[N][N][2],ans;

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
inline void change(int x,int y,int tp)
{
	ans-=dp[x][y][tp];
	if (a[x][y]==1) dp[x][y][tp]=0;
	else if (tp==0) dp[x][y][tp]=1+dp[x][y+1][1];
	else dp[x][y][tp]=1+dp[x+1][y][0];
	ans+=dp[x][y][tp];
}
void update(int x,int y,int tp)
{
	if (x==0||y==0) return;
	change(x,y,tp);
	if (tp==0) update(x-1,y,1);
	else update(x,y-1,0);
}

int main()
{
	n=read(),m=read(),q=read();
	for (int i=n;i>=1;i--)
	{
		for (int j=m;j>=1;j--)
		{
			change(i,j,0),change(i,j,1);
		}
	}
	sum=n*m;
	for (int i=1;i<=q;i++)
	{
		int x=read(),y=read();
		a[x][y]^=1;
		if (a[x][y]==1) sum--;
		else sum++;
		update(x,y,0);
		update(x,y,1);
		printf("%lld\n",ans-sum);
	}
	return 0;
}