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
const int MOD=1e9+7;


#define INF (1LL<<60)
#define M (1<<18)

ll d[2*M];
ll mx[2*M];
int aa,bb;
ll vv;

void czysc()
{
    FOR(i,2*M) d[i]=0;
    FOR(i,2*M) mx[i]=0;
}

void dodp(int l,int p,int nr)
{
    if (p<aa || l>bb) return;
    if (aa<=l && p<=bb) d[nr]+=vv;
    else
    {
        dodp(l,(l+p)/2,nr*2);
        dodp((l+p)/2+1,p,nr*2+1);
    }
    mx[nr]=(l==p?d[nr]:d[nr]+max(mx[nr*2],mx[nr*2+1]));
}

void dod(int a,int b,ll val)//dodaje do wszystkich z [a,b] wartosc val
{
    aa=a;bb=b;vv=val;
    dodp(0,M-1,1);
}

ll wezmaxp(int l,int p,int nr)
{
    if (p<aa || l>bb) return -INF;
    if (aa<=l && p<=bb) return mx[nr];
    return d[nr]+max(wezmaxp(l,(l+p)/2,nr*2),wezmaxp((l+p)/2+1,p,nr*2+1));
}

ll wezmax(int a,int b)//max prz. [a,b]
{
    aa=a;bb=b;
    return wezmaxp(0,M-1,1);
}

	
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);
	int n;cin>>n;
	vi p(n+1);
	REP(i,1,n) cin>>p[i];
	vi a(n+1);
	ll sum=0;
	ll best=INF;
	REP(i,1,n) {cin>>a[i];sum+=a[i];}
	REP(i,1,n) dod(0,p[i]-1,a[i]);
	REP(i,1,n) {
		dod(0,p[i]-1,-a[i]);
		dod(p[i],n,a[i]);
		//debug()<<imie(i)<<wezmax(0,n);
		if (i<n) best=min(best, sum-wezmax(0,n));
	}
	cout<<best<<"\n";
	


    return 0;
}