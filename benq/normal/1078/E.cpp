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
    // Source: StackOverflow
    
    template<class T> struct like_array : is_array<T>{};
    template<class T, size_t N> struct like_array<array<T,N>> : true_type{};
    template<class T> struct like_array<vector<T>> : true_type{};
    template<class T> bool is_like_array(const T& a) { return like_array<T>::value; }

    // I/O 
    
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
    
    template<class T> ostream& printArray(ostream& os, const T& a, int SZ) {
        os << '{';
        F0R(i,SZ) {
            if (i) {
                os << ", ";
                if (is_like_array(a[i])) cout << "\n";
            }
            os << a[i];
        }
        os << '}';
        return os;
    }
    
    template<class T, size_t SZ> ostream& operator<<(ostream& os, const array<T,SZ>& a) {
        return printArray(os,a,SZ);
    }
    template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
        return printArray(os,a,sz(a));
    }
}

using namespace io;

map<pi,int> m;
vpi pos;

int getVal(pi a) {
    if (!m.count(a)) return -1;
    return m[{a.f,a.s}];
}

pi operator+(const pi& l, const pi& r) { return {l.f+r.f,l.s+r.s}; }

void sim(string x, string y, string s) {
    pos.clear(); m.clear();
    F0Rd(i,sz(x)) m[{-sz(x)+i+1,0}] = x[i]-'0';
    F0Rd(i,sz(y)) m[{-sz(y)+i+1,1}] = y[i]-'0';
    pos.pb({0,0});
    int co = 0;
    cout << "\n";
    for (char c: s) {
        if (c == 'u') pos.pb(pos.back()+mp(0,1));
        else if (c == 'd') pos.pb(pos.back()+mp(0,-1));
        else if (c == 'l') pos.pb(pos.back()+mp(-1,0));
        else if (c == 'r') pos.pb(pos.back()+mp(1,0));
        else if (c == 's') pos.pb(pos.back());
        else if (c == 't') {
            int x = getVal(pos.back());
            F0R(i,x+1) pos.pop_back();
        } else if (c == '0') {
            pos.pb(pos.back());
            m[pos.back()] = 0;
        } else if (c == '1') {
            pos.pb(pos.back());
            m[pos.back()] = 1;
        }
        else exit(5);
        co ++;
        if (co > sz(s)-10) cout << c << ' ' << pos.back() << "\t";
    }
    FORd(i,-10,11) {
        FOR(j,-10,11) {
            if (pos.back() == mp(j,i)) {
                cout << char('B'+getVal({j,i}));
            } else {
                if (!m.count({j,i})) cout << '.';
                else cout << m[{j,i}];
            }
        }
        cout << "\n";
    }
        cout << "\n";
    FORd(i,-1,2) {
        FOR(j,-35,2) {
            if (pos.back() == mp(j,i)) {
                cout << char('B'+getVal({j,i}));
            } else {
                if (!m.count({j,i})) cout << '.';
                else cout << m[{j,i}];
            }
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    // you should actually read the stuff at the bottom
    setIO(); string s;
    s += "d0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0lrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrru";
    s += "ddddddd1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l1lrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrruuuuuuu";
    F0R(i,32) s += "dd0d0d0d0d0uuuuuuuudstdddddddddustustuuuuuudstddddddddustuuuuuu0dl1ruuu1dddddstdstdstdstuuuuuudd0d0d0d0d0uuuuuuduudstddstdddddddustustuuuul1r0u0duu0dddddstdstdstdstuuuuuuudstdd1dddddstuuuuuul";
    s += "ld";
    cout << s;
    /*string t;
    while (cin >> t) {
        if (t == "//") break;
        if (t.substr(0,2) == "??") continue;
        s += t;
    }*/
    // sim("010101","101011",s);
}

/* 
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/