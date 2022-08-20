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
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { re(first); re(rest...); }
    
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    void re(cd& x) { ld a,b; re(a,b); x = cd(a,b); }
    
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    
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
    
    template<class T> void pr(const T& x) { cout << x << '\n'; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        cout << first << ' '; pr(rest...); 
    }
}

using namespace io;

int k;
pi pre[8][8];
bool oc[8][8], done[8][8];
vector<string> ans;
int xd[8] = {2,1,-1,-2,-2,-1,1,2};
int yd[8] = {1,2,2,1,-1,-2,-2,-1};

bool valid(pi x) {
    if (x.f < 0 || x.f > 7 || x.s < 0 || x.s > 7) return 0;
    if (done[x.f][x.s] || pre[x.f][x.s] != mp(-1,-1)) return 0;  
    return 1;
}

string con(pi x) {
    string ret; ret += char('a'+x.f); ret += char('1'+x.s);
    return ret;
}

string rev(string x) {
    return x.substr(3,2)+"-"+x.substr(0,2);
}

void move(pi x, pi y) {
    assert(oc[x.f][x.s] && !oc[y.f][y.s]);
    ans.pb(con(x)+"-"+con(y));
    oc[x.f][x.s] = 0; oc[y.f][y.s] = 1;
}

void fill(int x, int y) {
    F0R(i,8) F0R(j,8) pre[i][j] = {-1,-1};
    queue<pi> q; q.push({x,y}); pre[x][y] = {-MOD,-MOD};
    while (sz(q)) {
        auto a = q.front(); q.pop();
        if (oc[a.f][a.s]) {
            while (a != mp(x,y)) {
                move(a,pre[a.f][a.s]);
                a = pre[a.f][a.s];
            }
            return;
        }
        F0R(i,8) {
            pi A = {a.f+xd[i],a.s+yd[i]};
            if (!valid(A)) continue;
            pre[A.f][A.s] = a; q.push(A);
        }
    }
}

int main() {
    // you should actually read the stuff at the bottom
    setIO(); re(k);
    if (k > 32) {
        F0R(i,8) F0R(j,8) oc[i][j] = 1;
    }
    F0R(i,k) {
        string s; re(s); 
        if (k <= 32) oc[s[0]-'a'][s[1]-'1'] = 1;
        else oc[s[0]-'a'][s[1]-'1'] = 0;
    }
    F0R(i,k) {
        int x,y;
        if (k <= 32) x = i%8, y = i/8;
        else x = 7-(i%8), y = 7-i/8;
        fill(x,y);
        done[x][y] = 1;
    }
    pr(sz(ans));
    if (k <= 32) {
        trav(x,ans) pr(x);
    } else {
        trav(x,ans) pr(rev(x));
    }
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/