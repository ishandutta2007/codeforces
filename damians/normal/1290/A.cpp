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

int a[1<<15];
	
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);
	int t;cin>>t;
	FOR(tc,t) {
		int n,m;cin>>n>>m;
		int k;cin>>k;
		k=min(k,m-1);
		FOR(i,n)cin>>a[i];
		int dl=n-m+1;
		int w=n-k;
		int lo=0,hi=1e9+1,mid;
		debug()<<imie(n)<<imie(m)<<imie(k)<<imie(dl)<<imie(w);
		while(hi-lo>1){
			mid=(hi+lo)/2;
			int l=0,r=w;
			int cnt=0;
			int ile=0;
			debug()<<imie(lo)<<imie(mid)<<imie(hi);
			for(int i=0;i+dl<=w;i++){
				ile++;
				if (a[i]>=mid || a[i+dl-1]>=mid) cnt++;
			}
			if (mid==7) debug()<<imie(cnt)<<imie(ile);
			int mxcnt=cnt;
			while(1) {
				r++;l++;
				if (r>n) break;
				if (a[l-1]>=mid || a[l-1+dl-1]>=mid) cnt--;
				if (a[r-1-dl+1]>=mid || a[r-1]>=mid) cnt++;
				if (mid==7) debug()<<imie(cnt);
				mxcnt=max(cnt,mxcnt);
			}
			if (mxcnt==ile) lo=mid;
			else hi=mid;
		}
		cout<<lo<<"\n";
	}


    return 0;
}