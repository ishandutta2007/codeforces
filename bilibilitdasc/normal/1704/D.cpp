#include <bits/stdc++.h>
//#define CinCout
#define rep(i,n) for(int i=0,_##i##__end=(n);i<_##i##__end;++i)
#define per(i,n) for(int i=(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1,_##i##__end=(n);i<=_##i##__end;++i)
#define per1(i,n) for(int i=(n);i>=1;--i)
#define pb push_back
#define mp make_pair
#define debugv(x) cout<<#x<<'='<<x<<",line "<<__LINE__-1<<endl
#define debug cout<<"at line "<<__LINE__-1<<" in function "<<__FUNCTION__<<endl
#define nextp next_permutation
#define pq priority_queue
#define fi first
#define se second
#ifdef CinCout
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#else
#define Yes puts("Yes")
#define No puts("No")
#define YES puts("YES")
#define NO puts("NO")
#endif
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
int t,n,m;
ll v,s[100005];
int read()
{
	int res=0;char c=getchar();
	while(48>c||57<c) c=getchar();
	while(48<=c&&c<=57)
	{
		res=res*10+(c&15);c=getchar();
	}
	return res;
}
ll read1()
{
	ll res=0;char c=getchar();
	while(48>c||57<c) c=getchar();
	while(48<=c&&c<=57)
	{
		res=res*10+(c&15);c=getchar();
	}
	return res;
}
void write(int x)
{
	if(x>9) write(x/10);
	putchar((x%10)|48);
}
void write(ll x)
{
	if(x>9) write(x/10);
	putchar((x%10)|48);
}
void write(int x,char c)
{
	write(x);putchar(c);
}
void write(ll x,char c)
{
	write(x);putchar(c);
}
void Q()
{
	n=read();m=read();
	rep(i,n)
	{
		s[i]=0;
		per1(j,m)
		{
			s[i]+=j*read1();
		}
	}
	if(s[1]!=s[0]&&s[2]!=s[0])
	{
		write(1,' ');write(s[1]-s[0],'\n');return ;
	}
	int idx=0;
	rep(i,n) if(s[i]!=s[0]) idx=i;
	write(idx+1,' ');write(s[0]-s[idx],'\n');
}
int main()
{
	t=read();
	while(t--)
	Q();
	return 0;
}