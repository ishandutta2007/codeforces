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
int n,m,u,v,x,y,z;
vector<int> con[5005];
vector<int> num[10005];
int c[5005],cnt;
bool dp[10005][5005];
int chs[10005];
int val;
void dfs(int x,int cl)
{
	if(c[x]!=-1)
	{
		if(c[x]!=cl)
		{
			cout<<"NO"<<endl;
			exit(0);
		}
		return;
	}
	c[x]=cl;
	rep(i,con[x].size())
	{
		dfs(con[x][i],cl^1);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m>>x>>y>>z;
	rep(i,m)
	{
		cin>>u>>v;
		con[u].pb(v);con[v].pb(u);
	}
	memset(c,-1,sizeof(c));
	rep1(i,n)
	{
		if(c[i]==-1)
		{
			dfs(i,(cnt++)<<1);
		}
		num[c[i]].pb(i);
	}
	dp[0][0]=1;
	for(int i=0;i<cnt;++i)
	{
		for(int j=min(num[i<<1].size(),num[i<<1|1].size());j<=y;++j)
		{
			if(j>=num[i<<1].size()&&dp[j-num[i<<1].size()][i])
			{
				dp[j][i+1]=1;
			}
			else if(j>=num[i<<1|1].size()&&dp[j-num[i<<1|1].size()][i])
			{
				dp[j][i+1]=1;
			}
		}
	}
	if(!dp[y][cnt])
	{
		cout<<"NO"<<endl;
		return 0;
	}
	val=y;
	per(i,cnt)
	{
		if(val>=num[i<<1].size()&&dp[val-num[i<<1].size()][i])
		{
			val-=num[i<<1].size();
			chs[i<<1]=2;
			chs[i<<1|1]=1;
		}
		else
		{
			val-=num[i<<1|1].size();
			chs[i<<1]=1;
			chs[i<<1|1]=2;
		}
	}
	cout<<"YES"<<endl;
	rep1(i,n)
	{
		if(chs[c[i]]==2) cout<<2;
		else
		{
			if(x)
			{
				--x;cout<<1; 
	 		}
	 		else
	 		{
	 		    cout<<3;	
			}
		}
	}
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