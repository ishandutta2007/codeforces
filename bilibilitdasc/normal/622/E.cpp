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
vector<int> con[500005];
int par[500005];
int dep[500005];
int srt[500005];//second root
vector<int> leaf[500005];
void dfs(int x,int p,int d)
{
	par[x]=p;
	dep[x]=d;
	if(d>=2) srt[x]=srt[p];
	else srt[x]=x;
	rep(i,con[x].size())
	{
		int V=con[x][i];
		if(V==p) continue;
		dfs(V,x,d+1);
	}
}
bool cmp(int x,int y)
{
	return dep[x]>dep[y];
}
int ans;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	rep(i,n-1)
	{
		cin>>u>>v;con[u].pb(v);con[v].pb(u);
	}
	dfs(1,-1,0);
	for(int i=2;i<=n;++i) 
	{
		//cout<<i<<"->"<<par[i]<<"->"<<srt[i]<<endl;
		if(con[i].size()==1)
		leaf[srt[i]].pb(i);
	}
	rep(i,con[1].size())
	{
		v=con[1][i];
		//cout<<v<<":\n";
		sort(leaf[v].begin(),leaf[v].end(),cmp);
		rep(j,leaf[v].size())
		{
		//	cout<<leaf[v][j]<<'\n';
			ans=max(ans,dep[leaf[v][j]]+j);
		}
	}
	cout<<ans<<endl;
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