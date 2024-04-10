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
const int MX = 100005;
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

int nor(ll x) { return (x%MOD+MOD)%MOD; }

using namespace modOp;

int n, L[MX], R[MX], sumL[MX], sumLr[MX];
vi A;

template<class T, int SZ> struct LazySegTree {
    T sum[2*SZ], mn[2*SZ], lazy[2*SZ]; // set SZ to a power of 2
    
    LazySegTree() {
        memset (sum,0,sizeof sum);
        memset (mn,0,sizeof mn);
        memset (lazy,0,sizeof lazy);
    }
    
    void push(int ind, int L, int R) {
        sum[ind] += (R-L+1)*lazy[ind];
        mn[ind] += lazy[ind];
        if (L != R) lazy[2*ind] += lazy[ind], lazy[2*ind+1] += lazy[ind];
        lazy[ind] = 0;
    }
    
    void pull(int ind) {
        sum[ind] = sum[2*ind]+sum[2*ind+1];
        mn[ind] = min(mn[2*ind],mn[2*ind+1]);
    }
    
    void build() {
        F0Rd(i,SZ) pull(i);
    }
    
    T qsum(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return 0;
        if (lo <= L && R <= hi) return sum[ind];
        
        int M = (L+R)/2;
        return qsum(lo,hi,2*ind,L,M) + qsum(lo,hi,2*ind+1,M+1,R);
    }

    T qmin(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return INF;
        if (lo <= L && R <= hi) return mn[ind];
        
        int M = (L+R)/2;
        return min(qmin(lo,hi,2*ind,L,M), qmin(lo,hi,2*ind+1,M+1,R));
    }
    
    void upd(int lo, int hi, ll inc, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lazy[ind] = inc;
            push(ind,L,R);
            return;
        }
        
        int M = (L+R)/2;
        upd(lo,hi,inc,2*ind,L,M); upd(lo,hi,inc,2*ind+1,M+1,R);
        pull(ind);
    }
};

LazySegTree<ll,1<<17> LL,RR;
vpi LL2, RR2;

int sum (int a, int b) {
    return (ll)(a+b)*(b-a+1)/2%MOD;
}

void init() {
    // you should actually read the stuff at the bottom
    setIO(); re(n); A.resz(n); re(A);
    map<int,int> s;
    F0R(i,n) {
        if (s.count(A[i])) L[i] = s[A[i]]+1;
        else L[i] = 0;
        s[A[i]] = i;
    }
    s.clear();
    F0Rd(i,n) {
        if (s.count(A[i])) R[i] = s[A[i]]-1;
        else R[i] = n-1;
        s[A[i]] = i;
    }
}

int ans = 0, cur = 0, ri;

int get(int i, int r) {
    return mul(RR.qsum(r,r)-r,i-LL.qsum(r,r));
}

int getRR(int l, int r) {
    r = min(r,ri);
    if (l > r) return 0;
    return sub(nor(RR.qsum(l,r)),sum(l,r));
}

int getLL(int ind, int l, int r) {
    r = min(r,ri);
    if (l > r) return 0;
    return sub(mul(ind,r-l+1),nor(LL.qsum(l,r)));
}

void updi(int ind) {
    SUB(cur,getRR(ind,ri));
}

void updLL(int ind) { // ckmax(LL[?],L[ind]);
    int sofar = ind-1;
    while (sz(LL2) && LL2.back().s <= L[ind]) {
        LL.upd(sofar+1,LL2.back().f,L[ind]-LL2.back().s);
        SUB(cur,mul(L[ind]-LL2.back().s,getRR(sofar+1,LL2.back().f)));
        sofar = LL2.back().f; LL2.pop_back();
    }
    LL2.pb({sofar,L[ind]});
}

void updRR(int ind) {
    int sofar = ind-1;
    while (sz(RR2) && RR2.back().s >= R[ind]) {
        RR.upd(sofar+1,RR2.back().f,R[ind]-RR2.back().s);
        SUB(cur,mul(RR2.back().s-R[ind],getLL(ind,sofar+1,RR2.back().f)));
        sofar = RR2.back().f; RR2.pop_back();
    }
    RR2.pb({sofar,R[ind]});
}

int main() {
    init();
    ri = n-1;
    set<int> S;
    RR.upd(0,n-1,n-1);
    F0Rd(i,n) {
        while (S.count(A[i])) {
            S.erase(A[ri]); SUB(cur,get(i+1,ri));
            ri --;
        }
        S.insert(A[i]);
        LL2.pb({i,0}), RR2.pb({i,n-1});
        AD(cur,get(i+1,i));
        //cout << i << " " << cur << " " << ri << "\n";
        updi(i); 
        //cout << cur << "\n";
        updLL(i); 
        //cout << cur << "\n";
        updRR(i);
        //cout << cur << "\n";
        AD(ans,cur);
        //cout << cur << "\n";
        // (RR[j]-j)*(i-LL[j])
        // decrease i 
        // decrease RR[j]
        // increase LL[j]
        /*FOR(j,i,n) {
            ckmax(cur.f,L[j]);
            ckmin(cur.s,R[j]);
            if (cur.f <= i && j <= cur.s) AD(ans,mul(cur.s-j,i-cur.f));
        }*/
    }
    pr(ans);
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/