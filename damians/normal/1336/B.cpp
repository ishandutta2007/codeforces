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



ll get_val(ll a,ll b, ll c) {
	return (a-b)*(a-b) +(a-c)*(a-c)+(b-c)*(b-c);
}
	
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);
	int t;cin>>t;
	while(t--) {
		vi v[3];
		int n[3];
		FOR(i,3) cin>>n[i];
		FOR(i,3) FOR(j,n[i]) {int x;cin>>x;v[i].pb(x);}
		FOR(i,3) sort(ALL(v[i]));
		ll mn=(1LL<<62);
		FOR(i,3) {
			vector<pii> w;
			FOR(j,3) if (i!=j) {
				FOR(k,SZ(v[j])) w.pb({v[j][k], j});
			}
			sort(ALL(w));
			FOR(k,SZ(w)-1) {
				if (w[k].nd != w[k+1].nd) {
					int x=w[k].st;
					int y=w[k+1].st;
					int g=(x+y)/2;
					int r=lower_bound(ALL(v[i]),g)-v[i].begin();
					REP(z,r-2,r+2) {
						if (z>=0 && z<SZ(v[i])) {
							mn=min(mn,get_val(x,y,v[i][z]));
						}
					}
				}
			}
		}
		cout<<mn<<"\n";
	}


    return 0;
}