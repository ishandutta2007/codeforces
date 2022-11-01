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

int a[1<<20];
int aa[1<<20];
int n;


int cnt[1<<10];
set<int> absent;

void check(vi v) {
	FOR(i,SZ(v)) {
		int k=v[i];
		int mex=0;
		while(1) {
			bool is=0;
			FOR(j,n) if (aa[j]==mex) {is=1;}
			if (is) mex++;
			else break;
		}
		aa[k]=mex;
	}
	debug()<<imie(vi(aa,aa+n));
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);
	int t;cin>>t;
	while(t--) {
		cin>>n;
		debug()<<imie(n);
		FOR(i,n) cin>>a[i];
		FOR(i,n) aa[i]=a[i];
		FOR(i,n+1) cnt[i]=0;
		FOR(i,n) cnt[a[i]]++;
		absent.clear();
		FOR(i,n+1) if (cnt[i]==0) absent.insert(i);
		vi moves;
		set<int> bad;
		FOR(i,n) {
			if (a[i]!=i) bad.insert(i);
		}
		debug()<<imie(cnt[2]);
		debug()<<imie(absent.count(2));
		while(SZ(bad)) {
			int mex=*(absent.begin());
			debug()<<imie(mex);
			cnt[mex]++;
			absent.erase(mex);
			if (mex!=n) {
				if (bad.count(mex)) {
					bad.erase(mex);
				}
				moves.pb(mex);
				int e=a[mex];
				a[mex]=mex;
				cnt[e]--;
				if (cnt[e]==0) absent.insert(e);
			} else {
				int g = *(bad.begin());
				moves.pb(g);
				int e=a[g];
				a[g]=mex;
				cnt[e]--;
				if (cnt[e]==0) absent.insert(e);
			}
		}
		cout<<SZ(moves)<<"\n";
		FOR(i, SZ(moves)) cout<<moves[i]+1<<" ";
		cout<<"\n";
		//check(moves);;
	}


    return 0;
}