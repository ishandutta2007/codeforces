// By: Little09
// Problem: B. Mocha and Red and Blue
// Contest: Codeforces - Codeforces Round #738 (Div. 2)
// URL: https://codeforces.com/contest/1559/problem/B
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

const int N=500005;
int n,m,T; 
char a[N];

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
void paint(int l,int r)
{
	if (l>=r)
	{
		char t=a[l];
		for (int i=l;i>=r;i--)
		{
			a[i]=t;
			t='B'+'R'-t;
		}
	}
	else
	{
		char t=a[l];
		for (int i=l;i<=r;i++)
		{
			a[i]=t;
			t='B'+'R'-t;
		}
	}
}
void work()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=readchar();
	int last=1;
	for (int i=1;i<=n;i++)
	{
		if (a[i]=='R'||a[i]=='B') 
		{
			paint(i,last);
			last=i+1;
		}
	}
	if (last==1) a[1]='B',last++;
	if (last!=n+1) paint(last-1,n);
	for (int i=1;i<=n;i++) cout << a[i];
	cout << endl;
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