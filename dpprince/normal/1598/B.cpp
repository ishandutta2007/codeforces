// By: Little09
// Problem: B. Groups
// Contest: Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1598/problem/B
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
int a[N][6];

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
bool check(int x,int y)
{
	int cnt0=0,cnt1=0,cnt2=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i][x]==0&&a[i][y]==0) return 0;
		if (a[i][x]==1&&a[i][y]==1) cnt2++;
		else if (a[i][x]==1) cnt0++;
		else cnt1++;
	}
	if (cnt1<=n/2&&cnt0<=n/2) return 1;
	return 0;
}
void work()
{
	n=read();
	for (int i=1;i<=n;i++) 
	{
		for (int j=1;j<=5;j++)
		{
			a[i][j]=read();
		}
	}
	for (int i=1;i<=5;i++)
	{
		for (int j=i+1;j<=5;j++)
		{
			if (check(i,j)) 
			{
				printYES;
				return;
			}
		}
	}
	printNO;
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