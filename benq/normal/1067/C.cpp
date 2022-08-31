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

int n;
set<pi> good;
map<pi,int> m;
int xd[8] = {2,1,-1,-2,-2,-1,1,2}, yd[8] = {1,2,2,1,-1,-2,-2,-1};

void tri(vpi v) {
    queue<pi> todo; 
    for (auto a: v) {
        good.insert(a);
        todo.push(a);
    }
    while (sz(todo)) {
        pi a = todo.front(); todo.pop();
        F0R(i,8) {
            pi A = {a.f+xd[i],a.s+yd[i]};
            m[A] ++;
            if (m[A] >= 4 && !good.count(A)) {
                good.insert(A);
                todo.push(A);
            }
        }
    }
    //for (auto a: m) if (a.s >= 4 && !good.count(a.f)) cout << a.s << "\n";
    //cout << sz(good) << " " << (ld)sz(v)*sz(v)/sz(good);
}

int mx[1000][1000];

void dumb() {
    /*set<pi> tmp;
    int s = 50;
    F0R(i,s) {
        tmp.insert({i,i});
        tmp.insert({i,i+2});
        tmp.insert({-i,i});
        tmp.insert({-i,i+2});
    }
    F0R(i,s) {
        tmp.insert({-i,i});
        tmp.insert({i,i});
    }
    tmp.insert({0,1});
    tmp.insert({-1,1});
    tmp.insert({1,1});
    // tmp.insert({0,2});
    // F0R(i,4*s-5) tmp.insert({0,i});
    
    tri(vpi(all(tmp)));
    pi mn = {MOD,MOD};
    for (auto a: good) {
        mn.f = min(mn.f,a.f);
        mn.s = min(mn.s,a.s);
    }*/
    // F0R(i,100) if (!good.count({0,i})) cout << "HI " << i << "\n";
    /*for (auto a: good) mx[a.f-mn.f][a.s-mn.s] = 1;
    for (auto a: tmp) mx[a.f-mn.f][a.s-mn.s] = 2;
    cout << "\n";
    F0R(i,100) {
        F0R(j,100) cout << mx[i][j];
        cout << "\n";
    }*/
}

int main() {
    setIO(); re(n);
    vpi v; v.pb({0,0}), v.pb({0,2});
    for (int i = 1; i <= 250; ++i) {
        v.pb({i,i});
        v.pb({i,i+2});
        v.pb({-i,i});
        v.pb({-i,i+2});
    }
    v.resize(n);
    for (auto a: v) cout << a.f << " " << a.s << "\n";
    tri(v);
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/