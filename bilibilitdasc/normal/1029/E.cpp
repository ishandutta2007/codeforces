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
int n,u,v;
vector<int> con[200005];
int dp[200005][4];
int ans(const int&v,const int&p,const int&d)
{
	if(dp[v][d]!=0x3f3f3f3f) return dp[v][d];
	if(con[v].size()==1&&p!=-1) return dp[v][d]=(d==3);
	if(d==3)
	{
		int max3minus1=-0x3f3f3f3f;bool flag=0;
		dp[v][d]=0;
		rep(i,con[v].size())
		{
			if(con[v][i]!=p)
			{
				int u=con[v][i];
				int res1=ans(u,v,1)+1;int res3=ans(u,v,3);
				if(res1<=res3)
				{
					flag=1;
					dp[v][d]+=res1;
				}
				else
				{
					dp[v][d]+=res3;
					max3minus1=max(max3minus1,res3-res1);
				}
			}
		}
		if(!flag) dp[v][d]-=max3minus1;
		return dp[v][d];
	}
	dp[v][d]=0;
	rep(i,con[v].size())
	{
		if(con[v][i]!=p)
		{
			int u=con[v][i];
			dp[v][d]+=min(ans(u,v,d+1),ans(u,v,1)+1);
		}
	}
	return dp[v][d];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	memset(dp,0x3f,sizeof(dp));
	rep(i,n-1)
	{
		cin>>u>>v;
		con[u].pb(v);con[v].pb(u);
	}
	cout<<ans(1,-1,0)<<endl;
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