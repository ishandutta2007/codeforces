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
const int MOD=1e9+7;//998244353;

vi kr[1<<20];


int h[1<<20];
int child[1<<20];
int par[1<<20];
int hm[1<<20];


void dfs(int u,int p) {
	for(auto v: kr[u]) {
		if (v==p) continue;
		hm[u]++;
		h[v]=h[u]+1;
		par[v]=u;
		dfs(v,u);
	}
}

	
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);
	int n,k;
	cin>>n>>k;
	FOR(i,n-1) {
		int a,b;cin>>a>>b;
		a--;b--;
		kr[a].pb(b);
		kr[b].pb(a);
	}
	dfs(0,-1);
	set<pii> s;
	FOR(i,n) if (i && hm[i]==0) s.insert({-h[i],i});
	ll sum=0;
	int taken = 0;
	while(taken<k) {
		pii pa = *(s.begin());
		s.erase(pa);
		int u=pa.nd;
		sum-=child[u];
		sum+=h[u];
		if (u) {
			int p=par[u];
			child[p]+=child[u]+1;
			hm[p]--;
			if (hm[p]==0) {
				s.insert({-h[p]+child[p],p});
			}
		}
		taken++;
	}
	cout<<sum<<endl;
	


    return 0;
}