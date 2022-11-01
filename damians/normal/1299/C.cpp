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

ll a[1<<20];
ll s[1<<20];
pll p[1<<20];

int mxprawo[1<<20];

ll prawo(pll A, pll B, pll C) {
	return ((C.st-B.st)*(B.nd-A.nd)-(C.nd-B.nd)*(B.st-A.st));
}
	
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	int n;cin>>n;
	FOR(i,n) {cin>>a[i];s[i+1]=s[i]+a[i];}
	if (n<=1) {
		if (n==1) {
			cout<<a[0]<<endl;
		}

		return 0;
	}
	REP(i,1,n) p[i]={i,s[i]};
	p[0]={0,0};
	vi v={n};
	REPD(j,n-1,0) {
		while(SZ(v)>1 && prawo(p[j],p[v[SZ(v)-1]],p[v[SZ(v)-2]])>=0) v.pop_back();
		mxprawo[j]=v.back();
		v.pb(j);
	}
		
	//REP(i,1,n) debug()<<imie(i)<<imie(p[i])<<imie(mxprawo[i]);
	//debug()<<range(mxprawo+1,mxprawo+n);
	for(int i=1;i<=n;) {
		if (i==n) {
			cout<<1.0*a[i-1]<<" ";
			break;
		}
		long double val = (s[mxprawo[i-1]]-s[i-1])*1.0/(mxprawo[i-1]-i+1);
		if (a[i-1]<=val) {
			cout<<1.0*a[i-1]<<" ";
			i++;
		} else {
			int z=mxprawo[i-1];
			while(i<=z) {
				cout<<val<<" ";
				i++;
			}
		}
	}
	cout<<endl;


    return 0;
}