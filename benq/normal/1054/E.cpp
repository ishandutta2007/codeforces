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

int n,m; 
deque<char> d[300][300];
string t[300][300];
vector<vi> ans;

void mov(pi a, pi b) {
    char c = d[a.f][a.s].back(); d[a.f][a.s].pop_back();
    d[b.f][b.s].push_front(c);
    ans.pb({a.f+1,a.s+1,b.f+1,b.s+1});
}

void print() {
    F0R(i,n) {
        F0R(j,m) {
            cout << "| ";
            for (char c: d[i][j]) cout << c;
            cout << "\t";
        }
        cout << "\n";
    }
}

void solve1() {
    setIO(); re(n,m);
    F0R(i,n) F0R(j,m) {
        string s; re(s);
        for (char c: s) d[i][j].pb(c);
    }
    FOR(i,1,n) while (sz(d[i][0])) mov({i,0},{0,0});
    FOR(j,1,m) while (sz(d[0][j])) mov({0,j},{0,0});
    FOR(i,1,n) FOR(j,1,m) while (sz(d[i][j])) {
        if (d[i][j].back() == '0') {
            mov({i,j},{0,j});
        } else {
            mov({i,j},{i,0});
        }
    }
    FOR(i,2,n) while (sz(d[i][0])) mov({i,0},{1,0});
    FOR(j,2,m) while (sz(d[0][j])) mov({0,j},{0,1});
    while (sz(d[0][0])) {
        if (d[0][0].back() == '0') {
            mov({0,0},{0,1});
        } else {
            mov({0,0},{1,0});
        }
    }
}

int zeros[300], ones[300];

void solve2() {
    F0R(i,n) F0R(j,m) {
        re(t[i][j]);
        reverse(all(t[i][j]));
        if (i && j) {
            for (char c: t[i][j]) {
                if (c == '0') zeros[j] ++;
                else ones[i] ++;
            }
        }
    }
    string des;
    FORd(j,1,m) des += t[0][j];
    F0Rd(i,n) des += t[i][0];
    
    for (char c: des) {
        if (c == '1') {
            mov({1,0},{0,0});
        } else {
            mov({0,1},{0,0});
        }
    }
    
    FOR(i,2,n) F0R(j,ones[i]) mov({1,0},{i,0});
    FOR(i,2,m) F0R(j,zeros[i]) mov({0,1},{0,i});
    
    FOR(i,1,n) FOR(j,1,m) {
        for (char c: t[i][j]) {
            if (c == '0') mov({0,j},{i,j});
            else mov({i,0},{i,j});
        }
    }
    FORd(j,1,m) {
        for (char c: t[0][j]) mov({0,0},{0,j});
    }
    FORd(i,1,n) {
        for (char c: t[i][0]) mov({0,0},{i,0});
    }
}

int main() {
    solve1();
    solve2();
    cout << sz(ans) << "\n";
    for (auto a: ans) {
        for (auto b: a) cout << b << " ";
        cout << "\n";
    }
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/