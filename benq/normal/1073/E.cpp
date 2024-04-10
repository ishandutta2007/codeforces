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

const int MOD = 998244353;
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


namespace modOp {
    int ad(int a, int b, int mod = MOD) { return (a+b)%mod; }
    int sub(int a, int b, int mod = MOD) { return (a-b+mod)%mod; }
    int mul(int a, int b, int mod = MOD) { return (ll)a*b%mod; }
    
    int AD(int& a, int b, int mod = MOD) { return a = ad(a,b,mod); }
    int SUB(int& a, int b, int mod = MOD) { return a = sub(a,b,mod); }
    int MUL(int& a, int b, int mod = MOD) { return a = mul(a,b,mod); }
    
    int po (int b, int p, int mod = MOD) { return !p?1:mul(po(mul(b,b,mod),p/2,mod),p&1?b:1,mod); }
    int inv (int b, int mod = MOD) { return po(b,mod-2,mod); }
    
    int invGeneral(int a, int b) { // 0 < a < b, gcd(a,b) = 1
        if (a == 0) return b == 1 ? 0 : -1;
        int x = invGeneral(b%a,a); 
        return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
    }
}

using namespace modOp;

ll l,r,k;

int po10[20];
int dig[20];
map<int,pi> ans[20][2];

pi tri(int pos, bool less, int mask) {
    if (__builtin_popcount(mask) > k) return {0,0};
    if (ans[pos][less].count(mask)) return ans[pos][less][mask];
    if (pos == 0) return {1,0};
    pi res = {0,0};
    if (less) {
        F0R(i,10) {
            auto a = tri(pos-1,1,mask|(1<<i));
            res = {ad(res.f,a.f),ad(res.s,ad(mul(a.f,mul(i,po10[pos-1])),a.s))};
        }
    } else {
        F0R(i,dig[pos-1]+1) {
            auto a = tri(pos-1,i != dig[pos-1],mask|(1<<i));
            res = {ad(res.f,a.f),ad(res.s,ad(mul(a.f,mul(i,po10[pos-1])),a.s))};
        }
    }
    return ans[pos][less][mask] = res;
}

int get(ll x) {
    F0R(i,20) F0R(j,2) ans[i][j].clear();
    string s = to_string(x);
    F0R(i,sz(s)) dig[i] = s[sz(s)-1-i]-'0';
    int ans = 0;
    FOR(i,1,sz(s)) {
        FOR(j,1,10) {
            pi a = tri(i-1,1,1<<j);
            AD(ans,ad(mul(a.f,mul(j,po10[i-1])),a.s));
        }
    }
    //cout << "A " << ans << "\n";
    FOR(j,1,s[0]-'0'+1) {
        pi a = tri(sz(s)-1,j != (s[0]-'0'),1<<j);
        //cout << "OOPS " << j << " " << a.f << " " << a.s << "\n";
        AD(ans,ad(mul(a.f,mul(j,po10[sz(s)-1])),a.s));
    }
    //cout << ans << "\n";
    return ans;
}

int main() {
    po10[0] = 1;
    FOR(i,1,20) po10[i] = mul(po10[i-1],10);
    setIO(); re(l,r,k);
    cout << sub(get(r),get(l-1));
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/