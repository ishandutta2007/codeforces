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
const int MX = 200005;
const ld PI = 4*atan((ld)1);
int block = 450;

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
    
    template<class T> void pr(const T& x) { cout << x << '\n'; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        cout << first << ' '; pr(rest...); 
    }
}

using namespace io;

int n,k,q, a[MX], b[MX], t[MX], bad, ans;
pair<int,vi> stor[MX];

int query(pair<int,vi>& p) {
    return p.s[p.f];
    // auto it = equal_range(all(p.s),p.f); return distance(it.f,it.s);
}

int getBlock(int x) {
    int i = x%k, j = x/k;
    return i+k*(j/block)*block;
}

int getVal(int x) {
    return t[x]^stor[getBlock(x)].f;
}

void ad(int x, int sgn) {
    int i = x%k, j = x/k;
    if (k >= block) {
        for ( ; i+k*j <= n; j++) 
            ans += sgn*(getVal(i+k*j) == 0);
    } else {
        for ( ; i+k*j <= n && j % block != 0; j++) 
            ans += sgn*(getVal(i+k*j) == 0);
        for (; i+k*j <= n; j += block) 
            ans += sgn*query(stor[i+k*j]);
    }
    int ind = i+((n-i)/k)*k;
    bad += sgn*(getVal(ind) != 0);
}

void rebuildBlock(int b) {
    stor[b].s.resz(1<<14);
    F0R(i,block) {
        int ind = b+k*i;
        if (ind <= n) stor[b].s[t[ind]] ++;
        else break;
    }
}

void modify(int x, int y) {
    ad(x,-1);
    int i = x%k, j = x/k;
    
    if (k >= block) {
        for ( ; i+k*j <= n; j++) 
            t[i+k*j] ^= y;
    } else {
        int b = getBlock(x);
        for ( ; i+k*j <= n && j % block != 0; j++) {
            stor[b].s[t[i+k*j]] --; 
            stor[b].s[t[i+k*j] ^= y] ++;
        }
        // rebuildBlock(b);
        for (; i+k*j <= n; j += block) 
            stor[i+k*j].f ^= y;
    }
        
    ad(x,1);
}

void init() {
    // you should actually read the stuff at the bottom
    setIO(); re(n,k,q);
    FOR(i,1,n+1) re(a[i]);
    FOR(i,1,n+1) re(b[i]);
    F0R(i,n+1) {
        t[i] = a[i]^b[i]^a[i+1]^b[i+1];
        if (i >= k) t[i] ^= t[i-k];
    }
    if (k < block) F0R(i,n+1) if (getBlock(i) == i) rebuildBlock(i);
    F0R(i,k) ad(i,1);
}

void print() {
    if (bad) pr(-1);
    else pr(n+1-ans);
}

int main() {
    init();
    print();
    F0R(i,q) {
        char c; int p,v; re(c,p,v);
        
        int& z = ((c == 'a') ? a[p] : b[p]);
        int t = z^v;
        modify(p-1,t), modify(p,t); z = v;
        
        print();
    }
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/