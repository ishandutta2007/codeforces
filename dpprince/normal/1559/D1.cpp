// By: Little09
// Problem: D1. Mocha and Diana (Easy Version)
// Contest: Codeforces - Codeforces Round #738 (Div. 2)
// URL: https://codeforces.com/contest/1559/problem/D1
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

const int N=5005;
int n,m[2]; 
int a[N];
int fa[N][2];
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
int find(int x,int tp)
{
	if (x==fa[x][tp]) return x;
	return fa[x][tp]=find(fa[x][tp],tp);
}
void merge(int x,int y,int tp)
{
	int x1=find(x,tp),y2=find(y,tp);
	if (x1==y2) return;
	fa[x1][tp]=y2;
}
bool check(int x,int y,int tp)
{
	int x1=find(x,tp),y2=find(y,tp);
	if (x1==y2) return 0;
	return 1;
}
int T;
int ans[N][2],cnt;
void work()
{
	n=read(),m[0]=read(),m[1]=read();
	for (int i=1;i<=n;i++) fa[i][0]=fa[i][1]=i;
	for (int i=1;i<=m[0];i++)
	{
		int x=read(),y=read();
		merge(x,y,0);
	}
	for (int i=1;i<=m[1];i++)
	{
		int x=read(),y=read();
		merge(x,y,1);
	}
	cnt=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			if (check(i,j,0)&&check(i,j,1))
			{
				merge(i,j,0),merge(i,j,1);
				ans[++cnt][0]=i;
				ans[cnt][1]=j;
			}
		}
	}
	cout << cnt << endl;
	for (int i=1;i<=cnt;i++) printf("%d %d\n",ans[i][0],ans[i][1]);
	return;
}

int main()
{
	int tp=1;
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