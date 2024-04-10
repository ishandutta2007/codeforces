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
const int MX = 1<<17;

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

template<class T, int SZ> struct LazySegTree {
    T mn[2*SZ], lazy[2*SZ]; // set SZ to a power of 2
    
    LazySegTree() {
        memset (mn,0,sizeof mn);
        memset (lazy,0,sizeof lazy);
    }
    
    void push(int ind, int L, int R) {
        mn[ind] += lazy[ind];
        if (L != R) lazy[2*ind] += lazy[ind], lazy[2*ind+1] += lazy[ind];
        lazy[ind] = 0;
    }
    
    void pull(int ind) {
        mn[ind] = min(mn[2*ind],mn[2*ind+1]);
    }
    
    void build() {
        F0Rd(i,SZ) pull(i);
    }
    
    T qmin(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return INF;
        if (lo <= L && R <= hi) return mn[ind];
        
        int M = (L+R)/2;
        return min(qmin(lo,hi,2*ind,L,M), qmin(lo,hi,2*ind+1,M+1,R));
    }
    
    void upd(int lo, int hi, ll inc, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lazy[ind] = inc;
            push(ind,L,R);
            return;
        }
        
        int M = (L+R)/2;
        upd(lo,hi,inc,2*ind,L,M); upd(lo,hi,inc,2*ind+1,M+1,R);
        pull(ind);
    }
};

LazySegTree<ll,MX> L[2];

int n;

void init() {
    setIO(); re(n); 
    vl a(n); re(a);
    FOR(i,1,n) a[i] -= a[i-1];
    F0R(i,n) L[i&1].mn[MX^(i/2)] = a[i];
    F0R(i,2) L[i].build();
    // build segtree 
}

void upd(int num, int val) {
    if (num&1) {
        L[0].upd(0,(n-1)/2,val);
        L[1].upd(num/2,(n-1)/2,-val);
    } else {
        L[0].upd(0,(num+1)/2-1,val);
    }
}

int di(int x) {
    if (x&1) x --;
    return x/2;
}

bool query(int a, int b) {
    ll tmp = 0; if (a) tmp = L[(a-1)&1].qmin((a-1)/2,(a-1)/2);
    
    int B = b; if ((b-a)&1) B --;
    if (L[a&1].qmin(di(a),di(B))+tmp <= 0) return 0; // 3,4
    B = b; if ((b-a-1)&1) B --; // 0,0 
    if (L[(a+1)&1].qmin(di(a+1),di(B))-tmp+1 <= 0) return 0;
    
    if ((b-a)&1) return L[b&1].qmin(b/2,b/2)-tmp+1 == 1;
    return L[b&1].qmin(b/2,b/2)+tmp == 1;
}

int main() {
    init();
    int q; re(q);
    F0R(i,q) {
        int t,a,b; re(t,a,b);
        if (t == 1) {
            int k; re(k);
            upd(b+1,k); upd(a,-k);
        } else {
            cout << query(a,b) << "\n";
        }
    }
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/