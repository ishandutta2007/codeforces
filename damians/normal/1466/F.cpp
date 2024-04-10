//#pragma comment(linker, "/stack:200000000")
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

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
#define var(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

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
#define TRAV(i,v)for(auto &i:(v))
#define REMIN(x,v) x=min(x,v);
#define REMAX(x,v) x=max(x,v);

mt19937_64 rng(134569);
int rd(int l, int r) {return uniform_int_distribution<int>(l, r)(rng);}

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int MOD=1e9+7;//998244353;


int p[1<<20];
int szuk(int x){if (x==p[x]) return x;return p[x]=szuk(p[x]);}
inline void unia(int x,int y){p[szuk(x)]=szuk(y);}

ll p2[(1<<20)+2];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
  p2[0]=1;
  REP(i,1,(1<<20)) p2[i]=(p2[i-1]*2)%MOD;
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);
  int n,m;cin>>n>>m;
  FOR(i,m+1) p[i]=i;
  vi v;
  FOR(i,n) {
    int k;cin>>k;
    int a,b;
    if (k==1) {
      a=0;
      cin>>b;
    } else {
      cin>>a>>b;
    }
    if (szuk(a)==szuk(b)) {

    } else {
      v.pb(i);
      unia(a,b);
    }
  }
  cout<<p2[SZ(v)]<<" "<<SZ(v)<<"\n";
  FOR(i,SZ(v)) cout<<v[i]+1<<" ";
  cout<<"\n";


    return 0;
}