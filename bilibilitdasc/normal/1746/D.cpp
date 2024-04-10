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
int t,n,k;
int p[200005];
ll s[200005];
vector<int> ch[200005];
vector<ll> num[200005];
ll dp[200005][2];
int cnt[200005];
void dfs(int v)
{
	if(ch[v].empty())
	{
		dp[v][0]=cnt[v]*s[v];
		dp[v][1]=(cnt[v]+1)*s[v];
	}
	else
	{
		int Cnt1=cnt[v]%int(ch[v].size());
		int Cnt2=Cnt1+1;
		ll current=0;
		rep(i,ch[v].size())
		{
			int u=ch[v][i];
			cnt[u]=cnt[v]/int(ch[v].size());
			dfs(u);
			num[v].pb(dp[u][1]-dp[u][0]);current+=dp[u][0];
		}
		sort(num[v].begin(),num[v].end(),greater<int>());
		dp[v][0]=accumulate(num[v].begin(),num[v].begin()+Cnt1,current)+cnt[v]*s[v];
		dp[v][1]=accumulate(num[v].begin(),num[v].begin()+Cnt2,current)+(cnt[v]+1)*s[v];
	}
//	cout<<dp[v][0]<<','<<dp[v][1]<<' '<<v<<endl;
}
void Q()
{
	cin>>n>>k;cnt[1]=k;
	rep1(i,n)
	{
		ch[i].clear();num[i].clear();
	}
	rep1(i,n-1)
	{
		cin>>p[i+1];ch[p[i+1]].pb(i+1);
	}
	rep1(i,n) cin>>s[i];
	dfs(1);
	cout<<dp[1][0]<<'\n';
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;while(t--)Q();return 0; 
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