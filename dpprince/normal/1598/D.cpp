// By: Little09
// Problem: D. Training Session
// Contest: Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1598/problem/D
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

const int N=500005;
int m,T; 
ll n,ans;

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
vector<int>t[N],q[N];
ll a[N][2],c[N],sum[2],ir,as;
inline void update(int x)
{
	ir-=c[x];
	c[x]=a[x][0]*a[x][1];
	ir+=c[x];
}
void del(int x,int tp)
{
	for (int i=0;i<t[x].size();i++)
	{
		int v=t[x][i];
		a[v][tp]--;
		update(v);
		sum[tp]--;
	}
}
void add(int x,int tp)
{
	for (int i=0;i<t[x].size();i++)
	{
		int v=t[x][i];
		a[v][tp]++;
		update(v);
		sum[tp]++;
	}
}
void solve(int x)
{
	for (int i=0;i<t[x].size();i++)
	{
		int v=t[x][i];
		ll u0=sum[0]-a[v][0];
		ll u1=sum[1]-a[v][1];
		ll res=u0*u1-(ir-c[v]);
		ans+=res;
	}
}
void work()
{
	n=read(),ans=0,as=0,sum[0]=0,sum[1]=0,ir=0;
	for (int i=1;i<=n;i++) t[i].clear();
	for (int i=1;i<=n;i++) q[i].clear();
	for (int i=1;i<=n;i++) a[i][0]=0;
	for (int i=1;i<=n;i++) a[i][1]=0;
	for (int i=1;i<=n;i++) c[i]=0;
	for (int i=1;i<=n;i++) 
	{
		int x=read(),y=read();
		t[x].push_back(y);
		q[y].push_back(x);
	}
	for (int i=1;i<=n;i++) add(i,1);
	for (int i=1;i<=n;i++)
	{
		del(i,1);
		solve(i);
		add(i,0);
	}
	ll tot=0;
	for (int i=1;i<=n;i++)
	{
		ll u=t[i].size();
		as+=u*tot*(n-u-tot);
		tot+=u;
	}
	tot=0;
	for (int i=1;i<=n;i++)
	{
		ll u=q[i].size();
		as+=u*tot*(n-u-tot);
		tot+=u;
	}
	printf("%lld\n",as-ans);
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