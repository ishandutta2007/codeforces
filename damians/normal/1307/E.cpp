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
#define TRAV(i,v)for(auto &i:(v))
 
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int MOD=1e9+7;//998244353;

struct mi {
	typedef decay<decltype(MOD)>::type T;
	T val; 
	explicit operator T() const { return val; }
	mi() { val = 0; }
	mi(ll v) { 
		val = (-MOD <= v && v <= MOD) ? v : v % MOD;
		if (val < 0) val += MOD;
	}
	friend bool operator==(const mi& a, const mi& b) { 
		return a.val == b.val; }
	friend bool operator!=(const mi& a, const mi& b) { 
		return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) { 
		return a.val < b.val; }
	friend ostream& operator<<(ostream& os, const mi& a) { 
		return os << a.val; }
   
	mi operator-() const { return mi(-val); }
	mi& operator+=(const mi& m) { 
		if ((val += m.val) >= MOD) val -= MOD; 
		return *this; }
	mi& operator-=(const mi& m) { 
		if ((val -= m.val) < 0) val += MOD; 
		return *this; }
	mi& operator++() { return *this += 1; }
	mi& operator--() { return *this -= 1; }
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
 
	mi& operator*=(const mi& m) { 
		val = (ll)val*m.val%MOD; return *this; }
	friend mi pow(mi a, ll p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mi inv(const mi& a) { 
		assert(!(a == 0)); return pow(a,MOD-2); }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
};
#define INF (1<<20)

vi s[5555];

vector<pii> cow[5555];
mi opts[5555];
	
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);
	int n,m;cin>>n>>m;
	REP(i,1,n) {
		int x;cin>>x;
		s[x].pb(i);
	}
	FOR(i,m) {
		int f,h;cin>>f>>h;
		if (h<=SZ(s[f])) {
			int pl=s[f][h-1];
			int pr=s[f][SZ(s[f])-h];
			cow[f].pb(mp(pl,pr));
		}
	}
	int mx=0;
	opts[0]=0;
	REP(field,0,n) {
		int sw=-1;
		pii cw;
		FOR(ssw,5555)for(auto ccw:cow[ssw]) if (ccw.st==field) {sw=ssw;cw=ccw;}
		if (sw==-1 && field) continue;
		mi pos=1;
		int sum=1;
		if (field==0) {sum=0;sw=0;}
		else {
			sum=1;
			int dob=0;
			for(auto cw2: cow[sw]) {
				if (cw2!=cw && cw2.nd>field) dob++;
			}
			if (dob) {
				sum++;
				pos*=dob;
				debug()<<imie(field)<<imie(dob);
			}
		}
		FOR(sx,5555) {
			if (sx!=sw && SZ(cow[sx])) {
				if (field==4) debug()<<imie(sx);
				int lok=0;
				int rok=0;
				ll both=0;
				FOR(j,SZ(cow[sx])) {
					if (cow[sx][j].st<field) lok++;
					if (cow[sx][j].nd>field) rok++;
					if (cow[sx][j].st<field && cow[sx][j].nd>field) both++;
				}
				int pos2=lok*rok-both;
				int pos1=lok+rok;
				if (pos2) {
					sum+=2;
					pos*=pos2;
				} else if (pos1) {
					sum+=1;
					pos*=pos1;
				}
			}
		}
		if (sum) {
			debug()<<imie(sum)<<imie(field);
		}
		mx=max(mx,sum);
		opts[sum]+=pos;
	}

	cout<<mx<<" "<<opts[mx]<<endl;
	
	

    return 0;
}