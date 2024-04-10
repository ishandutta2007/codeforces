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

int a,b,l,r; 

bool classa(int x) {
    x %= a+b;
    if (x == 0) x += a+b;
    return x <= a;
}

int tri(int x) {
    vi lst, seq;
    set<int> inset;
    bool fst = 0;
    FOR(i,1,r+1) {
        int cur;
        if (classa(i)) {
            F0R(i,26) if (find(all(lst),i) == lst.end()) {
                cur = i;
                break;
            }
        } else {
            if (fst) cur = lst.back();
            else {
                fst = 1;
                cur = x;
            }
        }
        if (i >= l) inset.insert(cur);
        lst.pb(cur); seq.pb(cur);
        //cout << i << " " << cur << "\n";
        if (!classa(i)) {
            while (sz(lst) > a) lst.erase(lst.begin());
        }
    }
    // cout << x << " " << seq << "\n";
    return sz(inset);
}

int main() {
    setIO(); re(a,b,l,r);
    int m = l/(a+b);
    while (m*(a+b)+1 < l) m ++;
    while ((m-1)*(a+b)+1 >= l) m --;
    m = m*(a+b)+1;
    if (m-l < a) m += a+b;
    if (m+a-1 <= r) {
        cout << max(a-b,1)+a;
        exit(0);
    }
    while (m > l) m -= a+b;
    if (l <= 2*a) {
        int ans = MOD;
        F0R(i,26) ans = min(ans,tri(i));
        cout << ans;
    } else {
        vi lst;
        set<int> inset;
    //cout << m << " " << r << "\n\n";
        FOR(i,l,r+1) {
            int cur;
            if (classa(i)) {
                F0R(i,26) if (find(all(lst),i) == lst.end()) {
                    cur = i;
                    break;
                }
            } else {
                if (sz(lst)) cur = lst.back();
                else cur = 0;
            }
            if (i >= l) inset.insert(cur);
            lst.pb(cur);
            //cout << i << " " << cur << "\n";
            if (!classa(i)) {
                while (sz(lst) > a) lst.erase(lst.begin());
            }
        }
        cout << sz(inset);
    }
    // cout << l << " " << m << " " << r << "\n";
    // computer moves on 1, a+b+1, 2*(a+b)+1, ... 
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/