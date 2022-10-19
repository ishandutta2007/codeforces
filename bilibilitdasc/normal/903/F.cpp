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
//ios_base::sync_with_stdio(false);???cin
unsigned time_related_rand()
{
	return ll(chrono::high_resolution_clock::now().time_since_epoch().count());
}
/* 
c840
d951
ea62
fb73
*/
int dp[1024][4096];
//             0 1 2 3 4   5   6   7    8    9
int cover[114]={1,2,4,8,51,102,204,1911,3822,65535};
int cost[114];
int n;
char c[4][1024];
int v[1024];
int main()
{
	scanf("%d",&n);
	scanf("%d%d%d%d",&cost[0],&cost[4],&cost[7],&cost[9]);
	cost[3]=cost[2]=cost[1]=cost[0];
	cost[6]=cost[5]=cost[4];
	cost[8]=cost[7];
	#define combine(x,y,z) cover[z]=cover[x]|cover[y];cost[z]=cost[x]+cost[y];
	combine(7,8,10);combine(6,7,11);combine(4,8,12);combine(3,7,13);combine(0,8,14);
	combine(4,6,15);combine(4,2,16);combine(4,3,17);combine(5,0,18);combine(5,3,19);
	combine(6,0,20);combine(6,1,21);combine(0,1,22);combine(0,2,23);combine(0,3,24);
	combine(1,2,25);combine(1,3,26);combine(2,3,27);combine(22,2,28);combine(22,3,29);
	combine(0,27,30);combine(1,27,31);combine(22,27,32);combine(4,27,33);combine(5,24,34);
	cover[36]=0;cost[36]=0;
	combine(6,22,35);
	scanf("%s%s%s%s",c[0],c[1],c[2],c[3]);
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	rep(i,n)
	{
		if(c[0][i]=='*') v[i]+=1;
		if(c[1][i]=='*') v[i]+=2;
		if(c[2][i]=='*') v[i]+=4;
		if(c[3][i]=='*') v[i]+=8; 
	}
	rep(i,n)
	{
		rep(j,4096)
		{
			if(j[i[dp]]!=0x3f3f3f3f)
			{
	//			cout<<i<<' '<<j<<' '<<j[i[dp]]<<endl;
				int __=j<<4|v[i];
				for(int _=0;_<=36;++_)
				{
					int ___=__&(~cover[_]);
					if(___<4096)
					{
						dp[i+1][___]=min(dp[i+1][___],j[i[dp]]+cost[_]);
					}
				}
			}
		}
	}
	cout<<dp[n][0]<<endl;
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
2. If contains "not", why not ?????? or few affect?
*/