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
const int MX = 1<<18;
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

template<class T, int SZ> struct pseg {
    static const int LIMIT = 20000000;
    int l[LIMIT], r[LIMIT], nex = 0;
    T val[LIMIT], lazy[LIMIT];
    
    //// HELPER
    int copy(int cur) {
        int x = nex++;
        val[x] = val[cur], l[x] = l[cur], r[x] = r[cur], lazy[x] = lazy[cur];
        return x;
    }
    T comb(T a, T b) { return a+b; }
    void pull(int x) { 
        assert(!lazy[x] && !lazy[l[x]] && !lazy[r[x]]); 
        val[x] = comb(val[l[x]],val[r[x]]); 
    }
    void push(int cur, int L, int R) {
        if (!lazy[cur]) return;
        val[cur] = R-L+1-val[cur];
        if (L != R) {
            l[cur] = copy(l[cur]); lazy[l[cur]] ^= 1;
            r[cur] = copy(r[cur]); lazy[r[cur]] ^= 1;
        }
        lazy[cur] = 0;
    }
    int build(vector<T>& arr, int L, int R) {
        int cur = nex++;
        if (L == R) {
            if (L < sz(arr)) val[cur] = arr[L];
            return cur;
        }
        
        int M = (L+R)/2;
        l[cur] = build(arr,L,M), r[cur] = build(arr,M+1,R);
        pull(cur); return cur;
    }
    
    //// PUBLIC
    vi loc;
    void build(vector<T>& arr) { loc.pb(build(arr,0,SZ-1)); }
    
    void tour(int x, int L = 0, int R = MX-1) {
        push(x,L,R);
        if (L == R) {
            if (val[x]) cout << L << ' ';
            return;
        }
        int M = (L+R)/2;
        tour(l[x],L,M), tour(r[x],M+1,R);
    }
    
    pi sub(int cur, int y, int L = 0, int R = MX-1) {
        int x = copy(cur); push(x,L,R);
        if (y < L) return {1,x};
        if (L == R) {
            lazy[x] = 1; push(x,L,R);
            return {!val[x],x};
        }
        if (R <= y && val[x] == R-L+1) {
            lazy[x] = 1; push(x,L,R);
            return {1,x};
        }
        int M = (L+R)/2;
        auto a = sub(r[x],y,M+1,R); r[x] = a.s; 
        if (!a.f) {
            push(l[x],L,M);
            pull(x);
            return {0,x};
        }
        auto b = sub(l[x],y,L,M); l[x] = b.s; pull(x);
        return {b.f,x};
    }
};

pseg<int,MX> p;

int n, id;

struct creature {
    int attack, offset, loc, dead;
    ld tmp = 1;
    creature() {
        attack = offset = loc = 0;
        dead = -1;
    }
};

creature m[MX];

void fight(int a, int b, int i) {
    m[a].tmp -= pow((ld)2,b);
    b = m[a].offset-1-b;
    auto z = p.sub(m[a].loc,b);
    m[a].loc = z.s; if (z.f) m[a].dead = i;
    /*if (a == 5) {
        cout << i << " " << a << " " << b << " " << m[a].dead << " " << m[a].offset << " " << m[a].tmp << "\n";
        if (i > 38) {
            cout << "OOPS ";
            p.push(m[a].loc,0,MX-1);
            cout << p.val[m[a].loc] << "\n";
            p.tour(m[a].loc); exit(0);
            // if (i > 32) exit(0);
        }
    }*/
}

int main() {
    vi v; p.build(v); 
    setIO(); re(n);
    FOR(i,1,n+1) {
        int t; re(t);
        if (t == 1) {
            m[++id] = creature();
        } else if (t <= 3) {
            int ID; re(ID); if (m[ID].dead != -1) continue;
            if (t == 2) {
                m[ID].attack ++;
            } else if (t == 3) {
                m[ID].offset ++;
                m[ID].tmp *= 2;
            } 
        } else if (t == 4) {
            int ID; re(ID); m[++id] = m[ID]; 
            if (m[ID].dead != -1) m[id].dead = i;
        } else {
            int a,b; re(a,b); if (m[a].dead != -1 || m[b].dead != -1) continue;
            fight(a,m[b].attack,i), fight(b,m[a].attack,i);
        }
    }
    pr(id);
    FOR(i,1,id+1) cout << m[i].dead << " ";
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/