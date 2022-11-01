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

int a[(1<<22)+3];
int m[1<<22];
int check_leaf(int x) {
	if (a[2*x]==0 && a[2*x+1]==0) return x;
	if (a[2*x]>a[2*x+1]) return check_leaf(2*x);
	return check_leaf(2*x+1);
}


void go(int x) {
	if (a[2*x]==0 && a[2*x+1]==0) {a[x]=0;return;}
	if (a[2*x]>a[2*x+1]) {
		a[x]=a[2*x];
		m[a[x]]=x;
		go(2*x);
		return;
	}
	if (a[2*x]<a[2*x+1]) {
		a[x]=a[2*x+1];
		m[a[x]]=x;
		go(2*x+1);
		return;
	}
}
	
	
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);
	int t;cin>>t;
	
	while(t--) {
		vi v;
		int g,h;cin>>h>>g;
		FOR(i,(1<<(h+1))+1) a[i]=0;
		FOR(i,(1<<h)-1) {
			cin>>a[i+1];
			v.pb(a[i+1]);
			m[a[i+1]]=i+1;
		}
		sort(ALL(v));
		reverse(ALL(v));
		ll sum=0;
		vi odp;
		for(auto w:v) {
			int ind=m[w];
			//debug()<<imie(w)<<imie(ind)<<imie(m)<<check_leaf(ind);
			if (check_leaf(ind)>=(1<<(g))) {
				odp.pb(ind);
				go(ind);
			}
			else sum+=w;
		}
		cout<<sum<<"\n";
		FOR(i,SZ(odp)) cout<<odp[i]<<" ";
		cout<<"\n";
	}


    return 0;
}