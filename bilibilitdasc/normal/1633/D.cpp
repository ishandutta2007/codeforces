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
int t;
int n,k;
queue<int> x;
int dis[1005];
int b[1005];
int c[1005];
void bfs()
{
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;x.push(1);
	while(!x.empty())
	{
		int v=x.front();x.pop();
		rep1(i,v)
		{
			int u=v+v/i;
			if(u>1000) continue;
			if(dis[u]>dis[v]+1)
			{
				dis[u]=dis[v]+1;
				x.push(u);
			}
		}
	}
}
int dp[12000];
void Q()
{
	cin>>n>>k;
	rep1(i,n)
	{
		cin>>b[i];b[i]=dis[b[i]];
	}
	rep1(i,n) cin>>c[i];
	k=min(12*n,k);
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;++i)
	{
		for(int j=k;j>=b[i];--j)
		{
			dp[j]=max(dp[j-b[i]]+c[i],dp[j]);
		}
	}
	cout<<dp[k]<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	bfs();
	cin>>t;
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