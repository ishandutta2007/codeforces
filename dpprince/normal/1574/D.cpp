// By: Little09
// Problem: D. The Strongest Build
// Contest: Codeforces - Educational Codeforces Round 114 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1574/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
int a[11][N],c[N];
struct point
{
	int w[11];
	int dis;
	bool operator < (const point & o) const
	{
	    if (dis!=o.dis) return dis<o.dis;
	    for (int i=1;i<=n;i++) if (w[i]!=o.w[i]) return w[i]<o.w[i];
	    return 0; 
	}
}b[N];
set<point>s;
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
point ans;
void update(point x)
{
	if (ans<x) ans=x;
}
int main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		c[i]=read();
		for (int j=1;j<=c[i];j++) a[i][j]=read();
	}
	m=read();
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++)
		{
			b[i].w[j]=read();
			b[i].dis+=a[j][b[i].w[j]];
		}
		s.insert(b[i]);
	}
	m++;
	ans.dis=0;
	for (int i=1;i<=n;i++) b[m].w[i]=c[i],b[m].dis+=a[i][c[i]];
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (b[i].w[j]>1)
			{
				point u=b[i];
				u.dis-=a[j][u.w[j]];
				u.w[j]--;
				u.dis+=a[j][u.w[j]];
				if (s.find(u)==s.end()) 
				{
					update(u);
				}
			}
		}
		if (s.find(b[i])==s.end()) update(b[i]);
	}
	for (int i=1;i<=n;i++) printf("%d ",ans.w[i]);
	return 0;
}