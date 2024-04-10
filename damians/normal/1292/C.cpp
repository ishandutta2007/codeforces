//#pragma comment(linker, "/stack:200000000")
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

 
using namespace __gnu_pbds;
using namespace std;
 
template <typename T>
using ordered_set =
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define un(x) x.erase(unique(ALL(x)),x.end())
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
 
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

#define maxn 3003
vi kr[maxn];
int par[maxn][maxn];
int sz[maxn][maxn];
ll dp[maxn][maxn];

void dfs(int u,int p,int root){
	sz[u][root]=1;
	par[u][root]=p;
	for(auto v:kr[u]){
		if (v==p) continue;
		dfs(v,u,root);
		sz[u][root]+=sz[v][root];
	}
}

ll go(int u,int v){
	//debug()<<imie(u)<<imie(v);
	//debug()<<imie(par[v][u])<<imie(par[u][v]);
	if (dp[u][v]!=-1) return dp[u][v];
	ll res=0;
	res=max(res,sz[u][v]*1LL*sz[v][u]+go(par[u][v],v));
	res=max(res,sz[u][v]*1LL*sz[v][u]+go(par[v][u],u));
	return dp[u][v]=res;
}
	
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);
	
	int n;cin>>n;
	FOR(i,n-1)
	{
		int a,b;cin>>a>>b;a--;b--;
		kr[a].pb(b);
		kr[b].pb(a);
	}
	FOR(root,n) dfs(root,-1,root);
	FOR(u,n)FOR(v,n) dp[u][v]=u==v?0:-1;
	ll mx=0;
	FOR(u,n)FOR(v,n) mx=max(mx,go(u,v));
	cout<<mx<<"\n";
	
	//FOR(i,n)FOR(v,n) mx=max(dp

    return 0;
}