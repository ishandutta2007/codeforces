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

vector<pii> res;
int avail[1<<20];

vector<vi> go(vector<vi> v,int cr) {
	debug()<<imie(v)<<imie(cr);
	vector<vi> rem;
	for(int l=0,r=0;l<SZ(v);){
		if (r<SZ(v) && v[l][cr]==v[r][cr]) r++;
		else {
			vector<vi> eq(v.begin()+l,v.begin()+r);
			if (r-l>1) {
				eq=go(eq,cr+1);
			}
			rem.insert(rem.end(),ALL(eq));
			l=r;
		}
	}
	while(SZ(rem)>=2) {
		int b=SZ(rem);
		pii pa({rem[b-1].back(),rem[b-2].back()});
		res.pb(pa);
		rem.pop_back();
		rem.pop_back();
	}	
	return rem;
}


	
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);
	int n;cin>>n;
	vector<vi> v;
	FOR(i,n) {
		vi z(4);
		FOR(j,3) cin>>z[j];
		z[3]=i;
		v.pb(z);
		avail[i]=1;
	}
	sort(ALL(v)); 
	go(v,0);
	assert(SZ(res)==n/2);
	FOR(i,(n/2)) cout<<res[i].st+1<<" "<<res[i].nd+1<<endl;

    return 0;
}