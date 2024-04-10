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
#define INF ((1LL)<<30)

int k[1<<20];
ll pw[55];

ll mpow(ll a, ll b)
{
    a=a%MOD;
    ll w=1;
    while(b)
    {
        if (b%2) w=(w*a)%MOD;
        a=(a*a)%MOD;
        b/=2;
    }
    return w;
}

	
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);
	int tc;cin>>tc;
	while(tc--) {
		int n,p;cin>>n>>p;
		pw[0]=1;
		REP(i,1,30) {
			pw[i]=min(pw[i-1]*p, INF);
		}
		FOR(i,n) cin>>k[i];
		if (p==1) {
			cout<<n%2<<"\n";
			continue;
		}
		int j=n-1;
		sort(k,k+n);
		while(1) {
			if (j==-1) break;
			int magn = k[j];
			ll left = 1;
			int i=j-1;
			while(1) {
				if (i==-1) break;
				left*=pw[min(30,magn-k[i])];
				magn=k[i];
				if (left>=INF) break;
				left-=1;
				i--;
				if (!left) break;
				
			}
			if (left) {
				break;
			}
			j=i;
		}
		if (j==-1) {
			cout<<0<<"\n";
		} else {
			ll sum=0;
			sum=mpow(p,k[j]);
			FOR(i,j) sum-=mpow(p,k[i]);
			sum%=MOD;
			sum+=MOD;
			cout<<sum%MOD<<"\n";
		}
		
	}


    return 0;
}