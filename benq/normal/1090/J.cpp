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

template<class T, int SZ> struct RMQ {
    T stor[SZ][32-__builtin_clz(SZ)];
    
    T comb(T a, T b) {
        return min(a,b);
    }
    
    void build(vector<T>& x) {
        F0R(i,sz(x)) stor[i][0] = x[i];
        FOR(j,1,32-__builtin_clz(SZ)) F0R(i,SZ-(1<<(j-1))) 
            stor[i][j] = comb(stor[i][j-1],
                        stor[i+(1<<(j-1))][j-1]);
    }
    
    T query(int l, int r) {
        int x = 31-__builtin_clz(r-l+1);
        return comb(stor[l][x],stor[r-(1<<x)+1][x]);
    }
};

struct SuffixArray {
    int N;
    vi idx;
    string str;
    RMQ<int,MX> R; 
    
    void compress(vi& v) {
        vi V = v; sort(all(V)); V.erase(unique(all(V)),V.end());
        for (int& i: v) i = lb(all(V),i)-V.begin()+1;
    }
    
    vi A, L; // A stores lexicographic value, L stores suffixes in order
    
    int get(int x) { return x >= N ? 0 : A[x]; }
    
    void sort_by(int x) { // stable sort elements in a by b
        vi cum(N+1); F0R(i,N) cum[get(i+x)] ++;
        int sum = 0; F0R(i,N+1) cum[i] = (sum += cum[i], sum-cum[i]);
        
        vi L2(N);
        for (int i: L) L2[cum[get(i+x)]++] = i;
        swap(L,L2);
    }
    
    void init(string _str) {
        str = _str; N = sz(str);
        A.resize(N); F0R(i,N) A[i] = str[i]; compress(A); 
        L.resize(N); F0R(i,N) L[i] = i;
        
        for (int cnt = 1; cnt < N; cnt <<= 1) { 
            sort_by(cnt), sort_by(0);
        
            vi A2(N);
            F0R(i,N) {
                if (i == 0) A2[L[i]] = 1;
                else A2[L[i]] = A2[L[i-1]]+
                    (mp(get(L[i]),get(L[i]+cnt)) != mp(get(L[i-1]),get(L[i-1]+cnt)));
            }
            
            swap(A,A2);
        }
        
        vi v = lcpArray(); R.build(v);
    }
    
    vi lcpArray() { // KACTL
        int h = 0;
        vi inv(N), res(N);
        F0R(i,N) inv[L[i]] = i;
        F0R(i,N) if (inv[i]) {
            int p0 = L[inv[i] - 1];
            while (max(i,p0)+h < N && str[i+h] == str[p0+h]) h++;
            res[inv[i]] = h;
            if (h) h--;
        }
        return res;
    }
    
    int lcp(int a, int b) {
        if (max(a,b) >= sz(A)) return 0;
        if (a == b) return N-a;
        int t0 = A[a], t1 = A[b];
        if (t0 > t1) swap(t0,t1);
        return R.query(t0,t1-1);
    }
};

SuffixArray S; // S.init("bcabcb");

string s,t;

int lcp(int x, int y) {
    if (x > y) swap(x,y);
    int len = S.lcp(sz(s),x);
    if (len < y-x) return x+len;
    return y+S.lcp(sz(s)+y-x,sz(s));
    // if ()
    // s.substr(0,x) + t, s.substr(0,y) + t 
    // t vs. s.substr(x,y-x)+t
}

int getChar(int x, int len) {
    if (len < x) return s[len]-'a';
    if (len-x < sz(t)) return t[len-x]-'a';
    return -1;
}

int fst(int x, int y) {
    int len = lcp(x,y);
    return getChar(x,len) < getChar(y,len);
    // s.substr(0,x) + t, s.substr(0,y) + t 
    
}

struct cmp {
    bool operator()(int x, int y) { 
        return fst(x,y); 
    }
};

set<int,cmp> cur;
Tree<pi> T;
vi v;
ll ans;
int co = 0;

void ad(int x, int t) {
    if (t == 1) T.insert({x,co++});
    else T.erase(T.lb({x,-MOD}));
}

void ins(int x, int ind) {
    if (ind == 1) cur.insert(x);
    auto it = cur.find(x);
    if (it != cur.begin()) {
        ad(lcp(*prev(it),*it),ind);
        if (next(it) != cur.end()) ad(lcp(*prev(it),*next(it)),-ind);
    }
    if (next(it) != cur.end()) ad(lcp(*it,*next(it)),ind);
    if (ind == -1) cur.erase(x);
}

int main() {
    // you should actually read the stuff at the bottom
    setIO(); re(s,t); S.init(s+t);
    FOR(i,1,sz(s)+1) v.pb(i);
    FOR(i,2,sz(s)+sz(t)+1) {
        // x, i-x <= sz(t);
        // x <= sz(s)
        // 1 <= i-x <= sz(t)
        // x <= i-1, x >= i-sz(t)
        if (i-1 <= sz(s)) ins(i-1,1);
        if (i-sz(t)-1 >= 1) ins(i-sz(t)-1,-1);
        // lcp < i 
        ans += 1+T.order_of_key({i,-MOD});
        /*cout << i << "\n";
        for (int j: cur) cout << j << " ";
        cout << "\n";
        for (auto j: T) cout << j << " ";
        cout << "\n";
        cout << "----\n";*/
    }
    cout << ans;
    
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/