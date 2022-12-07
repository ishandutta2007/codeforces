// By: Little09
// Problem: C. Slay the Dragon
// Contest: Codeforces - Educational Codeforces Round 114 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1574/problem/C
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

const ll inf=2000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m,T; 
ll a[N];

inline ll read()
{
    ll F=1,ANS=0;
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
ll ans=inf,sum;
void check(ll x,ll y,ll w)
{
	if (x>n||x<1) return;
	ll res=0;
	if (a[x]<y) res+=y-a[x];
	if (sum-a[x]<w) res+=w-sum+a[x];
	ans=min(ans,res);
}
void work()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),sum+=a[i];
	sort(a+1,a+n+1);
	m=read();
	while (m--)
	{
		ans=inf;
		ll x=read(),y=read();
		ll t=upper_bound(a+1,a+n+1,x)-a;
		check(t,x,y),check(t-1,x,y);
		printf("%lld\n",ans);
	}
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