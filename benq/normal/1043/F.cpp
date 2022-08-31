#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 300005;

namespace io {
    template<typename Test, template<typename...> class Ref>
    struct is_specialization : std::false_type {};

    template<template<typename...> class Ref, typename... Args>
    struct is_specialization<Ref<Args...>, Ref>: std::true_type {};
    // https://stackoverflow.com/questions/16337610/how-to-know-if-a-type-is-a-specialization-of-stdvector

    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
    
    // INPUT 
    
    // double input seems slow on CF
    void re(double& x) { string t; cin >> t; x = stod(t); } 
    void re(ld& x) { string t; cin >> t; x = stold(t); }
    template<class T> void re(T& x) { cin >> x; }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { 
        re(first); re(rest...); 
    }
    template<class T1, class T2> istream& operator>>(istream& is, pair<T1,T2>& p) {
        is >> p.f >> p.s; return is;
    }
    template<class T> istream& operator>>(istream& is, vector<T>& a) {
        F0R(i,sz(a)) is >> a[i];
        return is;
    }
    
    // OUTPUT 
    
    template<class T> void pr(const T& x) { cout << x << '\n'; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        cout << first << ' '; pr(rest...); 
    }
    template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) {
        os << '{' << a.f << ", " << a.s << '}'; return os;
    }
    template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
        os << '{';
        F0R(i,sz(a)) {
            if (i) {
                os << ", ";
                if (is_specialization<T, vector>::value) os << '\n';
            }
            os << a[i];
        }
        os << '}';
        return os;
    }
}

using namespace io;

int co[MX];

template<int SZ> struct sieve { 
	bitset<SZ> comp;
	vi pr;
	vi tmp[SZ];
	vi TMP[SZ];

    vi v;
    
    void search(vi& t, int ind, int cur) {
        if (ind == sz(t)) {
            v.pb(cur);
            return;
        }
        search(t,ind+1,cur);
        search(t,ind+1,cur*t[ind]);
    }
    
	sieve() {
		for (int i = 2; i < SZ; ++i) if (!comp[i]) {
		    for (int j = i; j < SZ; j += i) {
		        comp[j] = 1;
		        tmp[j].pb(i);
		    }
		}
		FOR(i,1,SZ) {
		    v.clear();
		    search(tmp[i],0,1);
		    TMP[i] = v;
		}
	}
};

sieve<MX> S;

int n, ans = MOD;
vi a, tri;
set<vi> done;
// at most 6 distinct primes

void solve(int x) {
    if (x == 1) {
        ans = 1; 
        return;
    }
    if (done.count(S.tmp[x])) return;
    done.insert(S.tmp[x]);
    
    vi CO(sz(S.TMP[x]));
    F0Rd(i,sz(S.TMP[x])) {
        CO[i] += co[S.TMP[x][i]];
        for (int j = i; j >= 0; j = i&(j-1)) {
            if (j != i) CO[j] -= CO[i];
            if (j == 0) break;
        }
    }    
    vi MN(sz(CO),MOD); 
    F0R(i,sz(CO)) if (CO[i]) MN[i] = 1;
    F0Rd(i,sz(CO)) FOR(j,i,sz(CO)) MN[i&j] = min(MN[i&j],MN[i]+MN[j]);
    ans = min(ans,MN[0]+1);
    /*vi v;
    F0R(i,sz(CO)) if (CO[i]) {
        bool bad = 0;
        for (int j = i; j >= 0; j = i&(j-1)) {
            if (CO[j]) {
                if (j == i) continue;
                bad = 1;
                if (j == 0) break;
            }
            if (j == 0) break;
        }
        if (!bad) v.pb(i);
    }
    cout << v << "\n";*/
} 

int main() {
    setIO(); re(n);
    int g = 0;
    F0R(i,n) {
        int x; re(x);
        tri.pb(x);
        g = __gcd(g,x);
        // cout << "HI " << x << " " << S.TMP[x] << "\n";
        for (int j: S.TMP[x]) co[j] ++;
    }
    if (g != 1) {
        cout << -1;
        exit(0);
    }
    for (int i: tri) solve(i);
    cout << ans;
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/