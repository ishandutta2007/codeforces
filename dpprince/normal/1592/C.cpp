// By: Little09
// Problem: C. Bakry and Partitioning
// Contest: Codeforces - Codeforces Round #746 (Div. 2)
// URL: https://codeforces.ml/contest/1592/problem/C
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
int n,m,T,sum; 
int a[N],s[N],size[N],d[N],du;
vector<int>t[N];
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
void dfs(int x,int fa)
{
	s[x]=a[x];
	for (int i=0;i<t[x].size();i++) 
	{
		if (fa==t[x][i]) continue;
		dfs(t[x][i],x);
		s[x]^=s[t[x][i]];
		size[x]+=size[t[x][i]];
	}
	if (s[x]==sum) size[x]++;
}
bool check1()
{
	if (sum==0) return 1;
	return 0;
}
bool res=0;
void dfs2(int x,int fa)
{
	int tot=0;
	if (s[x]==0) du++;
 	for (int i=0;i<t[x].size();i++) 
	{
		if (fa==t[x][i]) continue;
		dfs2(t[x][i],x);
		if (size[t[x][i]]>=1) tot++;
	}
	if (tot>=2) res=1;
	if (s[x]==sum&&du>0) res=1;
	if (s[x]==0) du--;
}
bool check2()
{
	res=0,du=0;
	dfs2(1,0);
	return res;
}
void work()
{
	n=read(),m=read(),sum=0;
	for (int i=1;i<=n;i++) a[i]=read(),s[i]=0,sum^=a[i];
	for (int i=1;i<=n;i++) size[i]=0,d[i]=0;
	for (int i=1;i<=n;i++) t[i].clear();
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		t[x].push_back(y),t[y].push_back(x);
	}
	dfs(1,0);
	bool flag=check1();
	if (m!=2) flag=flag|check2();
	if (flag) printYES;
	else printNO;
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