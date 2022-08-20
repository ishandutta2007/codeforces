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
const int MX = 100001;

/**
* Description: more convenient functions for input / output
  * experimentation with C++11 features
*/

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

template<class T, int SZ> struct RMQ {
    T stor[SZ][32-__builtin_clz(SZ)];
    
    T comb(T a, T b) {
        return min(a,b);
    }
    
    void build(vector<T>& x) {
        F0R(i,sz(x)) stor[i][0] = x[i];
        FOR(j,1,32-__builtin_clz(SZ)) F0R(i,SZ-(1<<(j-1))) 
            stor[i][j] = comb(stor[i][j-1],
                        stor[i+(1<<(j-1))][j-1]);
    }
    
    T query(int l, int r) {
        int x = 31-__builtin_clz(r-l+1);
        return comb(stor[l][x],stor[r-(1<<x)+1][x]);
    }
};

struct SuffixArray {
    int N;
    vi idx;
    string str;
    
    void compress(vi& v) {
        vi V = v; sort(all(V)); V.erase(unique(all(V)),V.end());
        for (int& i: v) i = lb(all(V),i)-V.begin()+1;
    }
    
    vi A, L; // L stores order of suffixes
    
    int get(int x) { return x >= N ? 0 : A[x]; }
    
    void sort_by(int x) { // stable sort elements in a by b
        vi cum(N+1); F0R(i,N) cum[get(i+x)] ++;
        int sum = 0; F0R(i,N+1) cum[i] = (sum += cum[i], sum-cum[i]);
        
        vi L2(N);
        for (int i: L) L2[cum[get(i+x)]++] = i;
        swap(L,L2);
    }
    
    void init(string _str) {
        str = _str; N = sz(str);
        A.resize(N); F0R(i,N) A[i] = str[i]; compress(A); 
        L.resize(N); F0R(i,N) L[i] = i;
        
        for (int cnt = 1; cnt < N; cnt <<= 1) { 
            sort_by(cnt), sort_by(0);
        
            vi A2(N);
            F0R(i,N) {
                if (i == 0) A2[L[i]] = 1;
                else A2[L[i]] = A2[L[i-1]]+
                    (mp(get(L[i]),get(L[i]+cnt)) != mp(get(L[i-1]),get(L[i-1]+cnt)));
            }
            
            swap(A,A2);
        }
    }
    
    vi lcp() { // KACTL
        int n = sz(str), h = 0;
        vi inv(n), res(n);
        F0R(i,N) inv[L[i]] = i;
        F0R(i,N) if (inv[i]) {
            int p0 = L[inv[i] - 1];
            while (max(i,p0)+h < N && str[i+h] == str[p0+h]) h++;
            res[inv[i]] = h;
            if (h) h--;
        }
        return res;
    }
};

int n, r[500001], ans;
string s;
SuffixArray S;
RMQ<int,500005> R;

int getlcp(int a, int b) {
    // S.A[a], S.A[b] 2, 3 --> min(2)
    int t0 = S.A[a], t1 = S.A[b];
    if (t0 > t1) swap(t0,t1);
    return R.query(t0,t1-1);
}

struct cmp {
    bool operator()(const pi& l, const pi& r) {
        int x = min(getlcp(l.f,r.f),min(l.s,r.s));
        if (x == l.s) {
            if (x == r.s) {
                return l.f < r.f;
            } else {
                return 1;
            }
        } else {
            if (x == r.s) {
                return 0;
            } else {
                return s[l.f+x] < s[r.f+x];
            }
        }
    }    
};

set<pi,cmp> T;

bool in(pi x) {
    if (x.s == 0) return 1;
    auto it = T.lb(x);
    return it != T.end() && min(getlcp(x.f,it->f),min(x.s,it->s)) == x.s;
}

bool ok(int l, int r) {
    //cout << "OOPS " << l << " " << r << "\n";
    return in({l,r-l}) || in({l+1,r-l});
}

int main() {
    setIO(); re(n,s);
    S.init(s);
    vi v = S.lcp();
    R.build(v);
    
    r[sz(s)] = sz(s)-1;
    F0Rd(i,sz(s)) {
        r[i] = r[i+1];
        while (!ok(i,r[i])) {
            T.insert({r[i],r[r[i]]-r[i]+1});
            r[i] --;
        }
        ans = max(ans,r[i]-i+1);
    }
    
    cout << ans;
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/