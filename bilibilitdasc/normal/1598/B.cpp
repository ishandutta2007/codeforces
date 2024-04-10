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
int t,n;
int can[1005][5];
int cnt[5];
void Q()
{
	scanf("%d",&n);
	memset(cnt,0,sizeof(cnt));
	rep(i,n)
	{
		scanf("%d%d%d%d%d",&can[i][0],&can[i][1],&can[i][2],&can[i][3],&can[i][4]);
		if(can[i][0]) ++cnt[0];
		if(can[i][1]) ++cnt[1];
		if(can[i][2]) ++cnt[2];
		if(can[i][3]) ++cnt[3];
		if(can[i][4]) ++cnt[4];
	}
	for(int i=0;i<5;++i) for(int j=0;j<i;++j)
	{
		bool flag=1;
		rep(k,n) if(!can[k][i]&&!can[k][j])
		{
			flag=0;
		}
		if(flag)
		{
			if(cnt[i]>=n/2&&cnt[j]>=n/2)
			{
				printf("YES\n");return;
			}
		}
	}
	printf("NO\n");
}
int main()
{
	scanf("%d",&t);
	while(t--)
	Q();
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