//#pragma comment(linker, "/stack:200000000")
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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
const int MOD=998244353;

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

namespace polynomial{
	typedef mi T;using poly=vector<T>;
	poly& trimZeros(poly& p){
		while(SZ(p) && p.back()==0) p.pop_back();
		return p;}
	T eval(const poly& p, T x){
		T res=0; REPD(i,SZ(p)-1,0) res=res*x+p[i];
		return res;}
	poly& operator+=(poly& l, const poly& r){
		l.resize(max(SZ(l),SZ(r)));
		FOR(i,SZ(r)) l[i]+=r[i];
		return l;}
	poly& operator-=(poly& l, const poly& r){
		l.resize(max(SZ(l),SZ(r)));
		FOR(i,SZ(r)) l[i]-=r[i];
		return l;}
	poly& operator*=(poly& p, const T& x){
		for(auto& coef: p) coef*=x; 
		return p;}
	poly& operator/=(poly& p, const T& x){
		for(auto& coef: p) coef/=x; 
		return p;}
	poly operator+(poly l, const poly& r){ return l+=r;}
	poly operator-(poly l, const poly& r){ return l-=r;}
	poly operator*(poly l, const T&x){ return l*=x;}
	poly operator/(poly l, const T&x){return l/=x;}
	poly operator*(const poly& l, const poly& r){
		if (!SZ(l) || !SZ(r)) return {};
		poly p(SZ(l)+SZ(r)-1);
		FOR(i,SZ(l))FOR(j,SZ(r))p[i+j]+=l[i]*r[j];
		return p;}
	poly& operator*=(poly& l, const poly& r){ return l=l*r;}
	pair<poly,poly> div_qr(poly l, poly r){
		poly q(SZ(l)-SZ(r)+1);
		T coef=r.back();coef=1/coef;r*=coef;
		while(SZ(r)<=SZ(l)){
			q[SZ(l)-SZ(r)]=l.back();
			FOR(i,SZ(r)) l[SZ(l)-SZ(r)+i]-=l.back()*r[i];
			trimZeros(l);
		}
		q*=coef;
		return {q,l};
	}
	poly lagrange(vector<pair<T,T>> av){
		poly r,pr={1};
		FOR(i,SZ(av)) pr*=poly({-av[i].st,1});
		FOR(j,SZ(av)) {
			T prc={1};FOR(i,SZ(av)) if (i!=j) prc*=(av[j].st-av[i].st);
			r+=(div_qr(pr,poly({-av[j].st,1})).st)*(av[j].nd/prc);
		}
		r=trimZeros(r);
		return r;
	}
		
		
}

using namespace polynomial;

poly sumpoly(poly p) {
	vector<pair<T,T>> evals(SZ(p)+2);
	FOR(x,SZ(p)+2) if (x) evals[x]={x,eval(p,x-1)}; else evals[x]={0,0};
	REP(x,1,SZ(evals)-1) evals[x].nd+=evals[x-1].nd;
	return lagrange(evals);
}

mi comb(int n,int k) {
	debug()<<imie(n)<<imie(k);
	mi gora=1;
	REP(i,n-k+1,n) gora*=i;
	mi dol=1;
	REP(i,1,k) dol*=i;
	return gora/dol;
}

mi dp[52][108];
int l[52],r[52];
int lI[108],rI[108];
	
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);
	int n;cin>>n;
	FOR(i,n){cin>>l[n-i]>>r[n-i];r[n-i]++;}
	l[0]=0;
	r[0]=998244352;
	l[n+1]=998244351;
	r[n+1]=998244352;
	n++;
	vi ends;
	FOR(i,n+1){ends.pb(l[i]);ends.pb(r[i]);}
	sort(ALL(ends));un(ends);
	int s=SZ(ends)-1;
	FOR(i,s) {lI[i]=ends[i];rI[i]=ends[i+1];}
	REP(k,1,n){
		FOR(i,s){
			REPD(d,k-1,0){
				if (!(l[d+1]<=lI[i] && rI[i]<=r[d+1])) break;
				mi mn=1;
				if (d>0) {
					mn=0;
					FOR(j,i) mn+=dp[d][j];
				}
				mi val=comb(k-d+rI[i]-lI[i]-1,k-d)*mn;
				//debug()<<imie(k)<<imie(i)<<imie(d)<<imie(val);
				dp[k][i]+=val;
			}
			debug()<<imie(k)<<imie(i)<<imie(mp(lI[i],rI[i]))<<imie(dp[k][i]);
		}
	}
	debug()<<imie(lI[s-1])<<imie(rI[s-1]);
	mi cnt=dp[n][s-1];
	debug()<<imie(cnt);
	mi pro=1;
	REP(i,1,n) pro*=(r[i]-l[i]);
	cout<<cnt/pro<<endl;
			
	


    return 0;
}