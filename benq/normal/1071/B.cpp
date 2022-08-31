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

int n,k, worth[2000][2000];
string g[2000];
int dp[2000][2000];

void genNex() {
    vpi tmp[3999];
    F0R(i,n) F0R(j,n) tmp[i+j].pb({i,j});
    F0Rd(sum,2*n-2) {
        vector<pair<pi,pi>> v;
        for (auto a: tmp[sum]) {
            int bes = MOD;
            if (a.f+1 < n) bes = min(bes,worth[a.f+1][a.s]);
            if (a.s+1 < n) bes = min(bes,worth[a.f][a.s+1]);
            v.pb({{g[a.f][a.s],bes},a});
        }
        sort(all(v));
        F0R(i,sz(v)) {
            worth[v[i].s.f][v[i].s.s] = i;
            // cout << sum << " " << i << " " << v[i] << "\n";
        }
    }
    /*F0R(i,n) {
        F0R(j,n) cout << worth[i][j] << "\t";
        cout << "\n";
    }*/
}

string gen(int x, int y) {
    string ret;
    while (mp(x,y) != mp(n-1,n-1)) {
        pi t = {MOD,MOD};
        if (x+1 < n) t = min(t,{worth[x+1][y],0});
        if (y+1 < n) t = min(t,{worth[x][y+1],1});
        if (t.s == 0) {
            x ++; 
        } else {
            y ++; 
        }
        ret += g[x][y];
    }
    return ret;
}

string gen(pi x) { return gen(x.f,x.s); }

int main() {
    setIO(); re(n,k);
    F0R(i,n) re(g[i]);
    genNex();
    pair<int,vpi> bes = {0,{{-1,-1}}};
    F0R(i,n) F0R(j,n) {
        if (i) dp[i][j] = max(dp[i][j],dp[i-1][j]);
        if (j) dp[i][j] = max(dp[i][j],dp[i][j-1]);
        if (g[i][j] == 'a') dp[i][j]++;
        int len = i+j+1;
        if (len <= dp[i][j]+k) {
            if (len > bes.f) bes = {len,{}};
            if (len == bes.f) bes.s.pb({i,j});
        }
    }
    if (bes.f == 0) cout << g[0][0]+gen(0,0);
    else {
        string a = gen(bes.s[0]);
        for (auto b: bes.s) a = min(a,gen(b));
        F0R(i,bes.f) a = 'a'+a;
        cout << a;
    }
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/