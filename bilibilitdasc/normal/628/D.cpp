#include <bits/stdc++.h>
#define rep(i,n) for(int i=0,_##i##__end=(n);i<_##i##__end;++i)
#define per(i,n) for(int i=(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1,_##i##__end=(n);i<=_##i##__end;++i)
#define per1(i,n) for(int i=(n);i>=1;--i)
#define repk(i,a,b) for(int i=(a),_##i##__end=(b);i<=_##i##__end;++i)
#define perk(i,a,b) for(int i=(a),_##i##__end=(b);i>=_##i##__end;++i)
#define rep0(i,a,b) for(int i=(a),_##i##__end=(b);i<_##i##__end;++i)
#define pb push_back
#define mp make_pair
#define debug(x) cout<<#x<<'='<<x<<endl
#define nextp next_permutation
#define pq priority_queue
#define fi first
#define se second
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
const int N=2005;
int m,d;
int dp[N][N][2];
char l[N],r[N];
int L;//strlen(l)
void upd(int &x,int y)
{
	x+=y;if(x>=mod2)x-=mod2;
}
void trans(int x,int y,int st,char *f)
{
	if(st==0)
	{
		for(int i=0;i<=9;++i)
		{
			if((x&1)^(i!=d))
			{
				upd(dp[x+1][(y*10+i)%m][0],dp[x][y][0]);
			}
		}
	}
	else if(st==1)
	{
		for(int i=0;;++i)
		{
			if(i==f[x]-'0')
			{
				if((x&1)^(i!=d))
				{
					upd(dp[x+1][(y*10+i)%m][1],dp[x][y][1]);
				}
				break;
			}
			else
			{
				if((x&1)^(i!=d))
				{
					upd(dp[x+1][(y*10+i)%m][0],dp[x][y][1]);
				}
			}
		}
	}
}
bool check(char *f)
{
	int res=0;
	for(int i=0;f[i];++i)
	{
		if((i&1)^(f[i]-'0'==d))
		return 0;
		res=(res*10+f[i]-'0')%m;
	}
	return res==0;
}
int calc_ans(char *f)
{
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=f[0]-'0';++i)
	{
		if(i!=d)
		dp[1][i%m][i==f[0]-'0']+=1;
	}
	for(int i=1;i<L;++i) for(int j=0;j<m;++j) for(int st=0;st<2;++st)
	trans(i,j,st,f);
	return (dp[L][0][0]+dp[L][0][1])%mod2;
}
int res;
int main()
{
	scanf("%d%d%s%s",&m,&d,l,r);
	L=strlen(l);
	//cout<<calc_ans(r)<<' ';cout<<calc_ans(l)<<endl;
	res=calc_ans(r)-calc_ans(l);
	if(res<0) res+=mod2;
	if(check(l))
	{
		++res;
		if(res==mod2) res=0;
	}
	printf("%d\n",res);
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