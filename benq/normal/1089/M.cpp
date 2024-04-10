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

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)
#define resz resize

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

namespace io {
    // TYPE ID (StackOverflow)
    
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
    
    template<class T> void re(T& x) { cin >> x; }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest);
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);
    
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { re(first); re(rest...); }
    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
    
    // OUTPUT 
    
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
    template<class T> ostream& operator<<(ostream& os, const set<T>& a) {
        os << vector<T>(all(a)); return os;
    }
    template<class T1, class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {
        os << vector<pair<T1,T2>>(all(a)); return os;
    }
    
    template<class T> void pr(const T& x) { cout << x << '\n'; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        cout << first << ' '; pr(rest...); 
    }
}

using namespace io;

int n, adj[9][9], in[9], comp[9], co;
bool ADJ[9][9];
string ans[18][36];

int main() {
    // you should actually read the stuff at the bottom
    setIO(); re(n);
    F0R(i,9) comp[i] = -1;
    F0R(i,n) F0R(j,n) re(adj[i][j]);
    F0R(k,n) F0R(i,n) F0R(j,n) if (adj[i][k] && adj[k][j]) adj[i][j] = 1;
    F0R(i,n) adj[i][i] = 0;
    
    F0R(i,n) if (comp[i] == -1) {
        comp[i] = co ++;
        F0R(j,n) if (adj[i][j] && adj[j][i]) comp[j] = comp[i];
    }
    // F0R(i,n) pr(comp[i]);
    F0R(i,n) F0R(j,n) if (adj[i][j] && comp[i] != comp[j] && !ADJ[comp[i]][comp[j]]) {
        ADJ[comp[i]][comp[j]] = 1;
        // pr(comp[i],comp[j]);
        in[comp[j]] ++;
    }
    queue<int> todo; F0R(i,co) if (!in[i]) todo.push(i);
    // pr("AH",sz(todo));
    // pr(co,sz(todo));
    vi order;
    while (sz(todo)) {
        int x = todo.front(); todo.pop(); order.pb(x);
        F0R(j,co) if (ADJ[x][j]) {
            in[j] --;
            if (in[j] == 0) todo.push(j);
        }
    }
    /*F0R(i,co) pr(in[i]);
    pr(co,order);*/
    assert(sz(order) == co);
    F0R(i,sz(order)) {
        F0R(j,36) F0R(k,36) {
            ans[2*i][j] += '.';
            ans[2*i+1][j] += '#';
        }
        F0R(j,9) F0R(k,9) {
            ans[2*i][4*j+1][4*k+2] = '#';
            ans[2*i][4*j+3][4*k+2] = '#';
            ans[2*i][4*j+2][4*k+1] = '#';
            ans[2*i][4*j+2][4*k+3] = '#';
            ans[2*i+1][4*j+2][4*k+2] = '.';
        }
    }
    F0R(i,sz(order)) {
        F0R(j,9) if (comp[j] == order[i]) ans[2*i][0][j] = char('1'+j);
        // color nums 
        FOR(j,i+1,sz(order)) if (ADJ[order[i]][order[j]]) {
            ans[2*i][4*i+1][4*j+2] = '.';
            ans[2*i][4*i+3][4*j+2] = '.';
            ans[2*i][4*i+2][4*j+1] = '.';
            ans[2*i][4*i+2][4*j+3] = '.';
            ans[2*j][4*i+1][4*j+2] = '.';
            ans[2*j][4*i+3][4*j+2] = '.';
            ans[2*j][4*i+2][4*j+1] = '.';
            ans[2*j][4*i+2][4*j+3] = '.';
            ans[2*j+1][4*i+2][4*j+2] = '#';
        }
    }
    pr(36,36,2*sz(order));
    F0R(i,2*sz(order)) {
        F0R(j,36) pr(ans[i][j]);
        pr("");
    }
    exit(0);
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/