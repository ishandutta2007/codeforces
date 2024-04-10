#include <bits/stdc++.h>
//#define CinCout
#define rep(i,n) for(int i=0,_##i##__end=(n);i<_##i##__end;++i)
#define per(i,n) for(int i=(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1,_##i##__end=(n);i<=_##i##__end;++i)
#define per1(i,n) for(int i=(n);i>=1;--i)
#define repk(i,a,b) for(int i=(a),_##i##__end=(b);i<=_##i##__end;++i)
#define perk(i,a,b) for(int i=(a),_##i##__end=(b);i>=_##i##__end;++i)
#define rep0(i,a,b) for(int i=(a),_##i##__end=(b);i<_##i##__end;++i)
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
int T,n;
ll tot;
char s[2005];
char t[2005];
ll bs[2005][3],bt[2005][3],sa[2005][3],ta[2005][3];
ll fac[4005],ivf[4005];
ll qp(ll a,ll b)
{
	ll res=1;while(b){if(b&1)res=res*a%mod2;a=a*a%mod2;b>>=1;}return res;
}
void init()
{
	fac[0]=1;rep1(i,4000) fac[i]=fac[i-1]*i%mod2;ivf[4000]=qp(fac[4000],mod2-2);per(i,4000)ivf[i]=ivf[i+1]*(i+1)%mod2;
}
ll C(ll n,ll m)
{
	if(m<0||m>n) return 0; return fac[n]*ivf[m]%mod2*ivf[n-m]%mod2;
}
ll calc(int i,int j)
{
	return abs(i-j)*C(bs[i][2]+bt[j][2],bs[i][1]+bs[i][2]-bt[j][1])%mod2*C(sa[i][2]+ta[j][2],sa[i][1]+sa[i][2]-ta[j][1])%mod2;
}
void Q()
{
	scanf("%d%s%s",&n,s,t);tot=0;
	for(int i=1;i<n;++++i)
	{
		if(s[i]!='?') s[i]^=1;
		if(t[i]!='?') t[i]^=1;
	}
	bs[0][0]=bs[0][1]=bs[0][2]=bt[0][0]=bt[0][1]=bt[0][2]=0;
	rep(i,n-1)
	{
		switch(s[i])
		{
			case '0':
				bs[i+1][0]=bs[i][0]+1;
				bs[i+1][1]=bs[i][1];
				bs[i+1][2]=bs[i][2];
				break;
			case '1':
				bs[i+1][0]=bs[i][0];
				bs[i+1][1]=bs[i][1]+1;
				bs[i+1][2]=bs[i][2];
				break;
			case '?':
				bs[i+1][0]=bs[i][0];
				bs[i+1][1]=bs[i][1];
				bs[i+1][2]=bs[i][2]+1;
				break;
			default:
				exit(114514);
		}
		switch(t[i])
		{
			case '0':
				bt[i+1][0]=bt[i][0]+1;
				bt[i+1][1]=bt[i][1];
				bt[i+1][2]=bt[i][2];
				break;
			case '1':
				bt[i+1][0]=bt[i][0];
				bt[i+1][1]=bt[i][1]+1;
				bt[i+1][2]=bt[i][2];
				break;
			case '?':
				bt[i+1][0]=bt[i][0];
				bt[i+1][1]=bt[i][1];
				bt[i+1][2]=bt[i][2]+1;
				break;
			default:
				exit(1919810);
		}
	}
	sa[n-1][0]=sa[n-1][1]=sa[n-1][2]=ta[n-1][0]=ta[n-1][1]=ta[n-1][2]=0;
	per(i,n-1)
	{
		switch(s[i+1])
		{
			case '0':
				sa[i][0]=sa[i+1][0]+1;
				sa[i][1]=sa[i+1][1];
				sa[i][2]=sa[i+1][2];
				break;
			case '1':
				sa[i][0]=sa[i+1][0];
				sa[i][1]=sa[i+1][1]+1;
				sa[i][2]=sa[i+1][2];
				break;
			case '?':
				sa[i][0]=sa[i+1][0];
				sa[i][1]=sa[i+1][1];
				sa[i][2]=sa[i+1][2]+1;
				break;
			default:
				exit(-114514);
		}
		switch(t[i+1])
		{
			case '0':
				ta[i][0]=ta[i+1][0]+1;
				ta[i][1]=ta[i+1][1];
				ta[i][2]=ta[i+1][2];
				break;
			case '1':
				ta[i][0]=ta[i+1][0];
				ta[i][1]=ta[i+1][1]+1;
				ta[i][2]=ta[i+1][2];
				break;
			case '?':
				ta[i][0]=ta[i+1][0];
				ta[i][1]=ta[i+1][1];
				ta[i][2]=ta[i+1][2]+1;
				break;
			default:
				exit(-114514);
		}
	}
	//rep(i,n) rep(j,3)
//	{
//		printf("bs[%d][%c]=%d\n",i,"01?"[j],bs[i][j]);
//		printf("bt[%d][%c]=%d\n",i,"01?"[j],bt[i][j]);
//		printf("sa[%d][%c]=%d\n",i,"01?"[j],sa[i][j]);
//		printf("ta[%d][%c]=%d\n",i,"01?"[j],ta[i][j]);
//		
//	}
	rep(i,n) rep(j,n)
	{
		if(s[i]!='0'&&t[j]!='0')
		{
			tot=(tot+calc(i,j))%mod2;//printf("calc(%d,%d)=%d\n",i,j,int(calc(i,j)));
		}
	}
	printf("%d\n",int(tot));
}
int main()
{
	scanf("%d",&T);init();
	while(T--)Q();
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