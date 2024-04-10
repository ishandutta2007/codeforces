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
char l[22],r[22];
int k;
int cnt[22][1111][2];
int dp[22][1111][2];
void add(int&a,int b)
{
	a+=b;if(a>=mod1) a-=mod1;
}
int ins(int s,int x)
{
	if(!x&&!s) return s;
	return s|1<<x;
}
int popcnt(int x)
{
	int res=0;
	while(x)
	{
		++res;x&=x-1;
	}
	return res;
}
void trans(int l,int s,char* x)
{
	// Untighten
	rep(i,10)
	{
		add(cnt[l+1][ins(s,i)][0],cnt[l][s][0]);
		add(dp[l+1][ins(s,i)][0],(dp[l][s][0]*10ll+1ll*cnt[l][s][0]*i)%mod1);
	}
	// tighten
	rep(i,x[l]-'0')
	{
		add(cnt[l+1][ins(s,i)][0],cnt[l][s][1]);
		add(dp[l+1][ins(s,i)][0],(dp[l][s][1]*10ll+1ll*cnt[l][s][1]*i)%mod1);
	}
	add(cnt[l+1][ins(s,x[l]-'0')][1],cnt[l][s][1]);
	add(dp[l+1][ins(s,x[l]-'0')][1],(dp[l][s][1]*10ll+1ll*cnt[l][s][1]*(x[l]-'0'))%mod1);
}
int calc(char *x)
{
	int l=strlen(x);
	memset(cnt,0,sizeof(cnt));
	memset(dp,0,sizeof(dp));
	cnt[0][0][1]=1;
	rep(i,l) rep(j,1024)
	{
		trans(i,j,x);
	}
	int tot=0;
	rep(i,1024)
	{
		if(popcnt(i)<=k)
		{
			add(tot,dp[l][i][0]);
			add(tot,dp[l][i][1]);
		}
	}
	return tot;
}
bool check(char *x)
{
	int qaq=0;
	rep(i,strlen(x)) qaq|=1<<(x[i]-'0');
	return popcnt(qaq)<=k;
}
int val(char *x)
{
	ll tot=0;
	rep(i,strlen(x)) tot=(tot*10+x[i]-'0')%mod1;
	return tot;
}
int ans;
int main()
{
	scanf("%s%s%d",l,r,&k);
	ans=calc(r)-calc(l)+mod1;
	ans%=mod1;
	if(check(l))
	{
		add(ans,val(l));
	}
	printf("%d\n",ans);
	return 0;
}
/* things to check
1.  int overflow or long long memory need
2.  recursion/array/binary search/dp/loop bounds
3.  precision
4.  special cases(n=1,bounds)
5.  delete debug statements
6.  initialize(especially multi-tests)
7.  = or == , n or m ,++ or -- , i or j , > or >= , < or <=
8.  keep it simple and stupid
9.  do not delete, use // instead
10. operator priority
11. is there anything extra to output?
12. ...
*/

/* something to think about
1. greedy? dp? searching? dp with matrix/ segment tree? binary search?
2. If contains "not", why not  or few affect?
*/