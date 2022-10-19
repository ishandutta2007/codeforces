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
int T,n,m;
char s[55],t[55];
char comb(char a,char b)
{
	if(a=='?'||b=='?') return '?';
	if(a!=b) return '?';
	return a;
}
bool mtch(char a,char b)
{
	if(a=='?'||b=='?') return 1;
	return a==b;
}
void Q()
{
	scanf("%d%d%s%s",&n,&m,s,t);
	rep(i,n-m)
	{
		s[i+1]=comb(s[i],s[i+1]);
	}
	rep(i,m)
	{
		if(!mtch(s[n-m+i],t[i]))
		{
			puts("NO");
			return;
		}
	}
	puts("YES");
}
int main()
{
	scanf("%d",&T);
	while(T--)
	Q();
	return 0;
}