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
using ld=long double;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;


struct frac {
	ll n,d;
	frac() { n = 0, d = 1; }
	frac(ll _n, ll _d) {
		n = _n, d = _d;
		ll g = __gcd(n,d); n /= g, d /= g;
		if (d < 0) n *= -1, d *= -1;
	}
	frac(ll _n) : frac(_n,1) {}
 
	friend frac abs(frac F) { return frac(abs(F.n),F.d); }
 
	friend bool operator<(const frac& l, const frac& r) { return l.n*r.d < r.n*l.d; }
	friend bool operator==(const frac& l, const frac& r) { return l.n == r.n && l.d == r.d; }
	friend bool operator!=(const frac& l, const frac& r) { return !(l == r); }
 
	friend frac operator+(const frac& l, const frac& r) { return frac(l.n*r.d+r.n*l.d,l.d*r.d); }
	friend frac operator-(const frac& l, const frac& r) { return frac(l.n*r.d-r.n*l.d,l.d*r.d); }
	friend frac operator*(const frac& l, const frac& r) { return frac(l.n*r.n,l.d*r.d); }
	friend frac operator*(const frac& l, int r) { return l*frac(r,1); }
	friend frac operator*(int r, const frac& l) { return l*r; }
	friend frac operator/(const frac& l, const frac& r) { return l*frac(r.d,r.n); }
	friend frac operator/(const frac& l, const int& r) { return l/frac(r,1); }
	friend frac operator/(const int& l, const frac& r) { return frac(l,1)/r; }
 
	friend frac& operator+=(frac& l, const frac& r) { return l = l+r; }
	friend frac& operator-=(frac& l, const frac& r) { return l = l-r; }
	template<class T> friend frac& operator*=(frac& l, const T& r) { return l = l*r; }
	template<class T> friend frac& operator/=(frac& l, const T& r) { return l = l/r; }
 
	friend ostream& operator<<(ostream& strm, const frac& a) {
		strm << a.n;
		if (a.d != 1) strm << "/" << a.d;
		return strm;
	}
};

const int MOD = 998244353; 

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

const int M (1<<17);


ll x[M+1];
ll v[M+1][2];
mi p[M+1][2];


frac t;

double collide_time(int i1,int i2,int dir1,int dir2){
	ll v1=v[i1][dir1];
	ll v2=v[i2][dir2];
	if (v1==v2) return 0;
	return (x[i2]-x[i1])*1.0/(v1-v2);
}

struct no
{
    mi p[2][2];
    no(){FOR(i,2)FOR(j,2)p[i][j]=0;}
    friend no operator+(no A, const no&B) {
        no w;
        FOR(i,2)FOR(j,2) {
			w.p[i][j]=0;
			FOR(k1,2) {
					w.p[i][j]+=A.p[i][k1]*B.p[k1][j];
			}
		}
		//debug()<<A.p[0][0]<<" "<<A.p[0][1]<<" "<<A.p[1][0]<<" "<<A.p[1][1];
		//debug()<<B.p[0][0]<<" "<<B.p[0][1]<<" "<<B.p[1][0]<<" "<<B.p[1][1];
		//debug()<<w.p[0][0]<<" "<<w.p[0][1]<<" "<<w.p[1][0]<<" "<<w.p[1][1];
        return w;
    }
};

no d[2*M];






void upd(int k){
	k+=M;
	while(1){
		k/=2;
		//debug()<<imie(k);
		d[k]=d[k*2]+d[k*2+1];
		if (k==1) break;
	}
}



	
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);
	//64593/532672

	//cout<<mi(64593)/mi(532672)<<endl;return 0;
	FOR(i,M+1) x[i]=1e9+1;
	FOR(i,M+1)FOR(j,2) v[i][j]=1e9+1;
	FOR(i,M+1)FOR(j,2) p[i][j]=1-j;
	int n;cin>>n;
	if (n==1) {cout<<0<<endl;return 0;}
	FOR(i,n){
		cin>>x[i];
		cin>>v[i][0];
		v[i][1]=-v[i][0];
		int pr;cin>>pr;
		p[i][0]=mi(pr)/mi(100);
		p[i][1]=mi(100-pr)/mi(100);
	}
	vector<pair<frac,pair<int,pii> > >tm;
	FOR(i,n-1)FOR(k1,2)FOR(k2,2){
		if (v[i][k1]==v[i+1][k2]) continue;
		frac cd=frac(x[i]-x[i+1],v[i+1][k2]-v[i][k1]);
		if (frac(0,1)<cd) tm.pb({cd,{i,{k1,k2}}});
	}
	//t=0;
	FOR(i,M)
	{
		FOR(k1,2)FOR(k2,2) d[i+M].p[k1][k2]=p[i][k1];

	}
	REPD(i,M-1,1) {d[i]=d[i*2]+d[i*2+1];}
	//debug()<<"before all"<<imie(d[1].p[1][0]);
	
	//FOR(i,n) FOR(k1,2)FOR(k2,2) debug()<<imie(i)<<imie(mp(k1,k2))<<imie(d[i+M].p[k1][k2]);
	
	sort(ALL(tm));
	mi expect=0;
	mi prob=1;
	for(auto ti:tm){
		t=ti.st;
		int ind=ti.nd.st;
		int k1=ti.nd.nd.st;
		int k2=ti.nd.nd.nd;
		d[ind+M].p[k1][k2]=0;
		//debug()<<"before"<<imie(d[1].p[1][0]);
		upd(ind);
		//debug()<<imie(d[1].p[1][0]);
		mi nprob=0;
		FOR(l1,2) nprob+=d[1].p[l1][0];
		expect+=(prob-nprob)*mi(t.n)/mi(t.d);
		//debug()<<imie(ti)<<imie(prob)<<imie(nprob)<<imie(expect);
		prob=nprob;
		
	}
	
	cout<<expect<<endl;

	


    return 0;
}