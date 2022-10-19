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
int a[100005];
int b[100005];
int p1[100005];
int p2[100005];
vector<int> to[100005];
vector<int> from[100005];
int in[100005];
vector<int> dfn;
bool vis[100005];
int scc[100005],cnt;
bool c1(int i,int j){return a[i]<a[j];}
bool c2(int i,int j){return b[i]<b[j];}
void dfs_dfn(int x)
{
	vis[x]=1;rep(i,to[x].size())if(!vis[to[x][i]])dfs_dfn(to[x][i]);dfn.pb(x);
}
void dfs_scc(int x,int c)
{
	scc[x]=c;rep(i,from[x].size())if(scc[from[x][i]]==-1)dfs_scc(from[x][i],c);
}
void Q()
{
	scanf("%d",&n);
	rep(i,n)scanf("%d",a+i);rep(i,n)scanf("%d",b+i);rep(i,n)p1[i]=p2[i]=i;cnt=0;
	rep(i,n){to[i].clear();from[i].clear();}dfn.clear();memset(scc,-1,sizeof(int)*n);
	sort(p1,p1+n,c1);sort(p2,p2+n,c2);memset(vis,0,sizeof(int)*n);memset(in,0,sizeof(int)*n);
	for(int i=1;i<n;++i)to[p1[i]].pb(p1[i-1]);for(int i=1;i<n;++i)to[p2[i]].pb(p2[i-1]);
	for(int i=1;i<n;++i)from[p1[i-1]].pb(p1[i]);for(int i=1;i<n;++i)from[p2[i-1]].pb(p2[i]);
	rep(i,n)if(!vis[i])dfs_dfn(i);per(i,n)if(scc[dfn[i]]==-1)dfs_scc(dfn[i],cnt++);
	rep(i,n)rep(j,to[i].size())if(scc[i]!=scc[to[i][j]])++in[scc[to[i][j]]];
	rep(i,n)putchar(in[scc[i]]==0?'1':'0');putchar(10);
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