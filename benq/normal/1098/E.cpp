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

const int MOD = 1000000007; // 998244353
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


template<class T, int SZ> struct RMQ {
    T stor[SZ][32-__builtin_clz(SZ)];
    
    T comb(T a, T b) {
        return __gcd(a,b);
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

RMQ<int,MX> R;
int n;
ll t1,t2,des;
ll co[MX], cum[MX], sumco[MX];
vi a, fac[MX], oc[MX];

void dealWith(int num, int l, int r) {
    int ind = l;
    FOR(i,l,r+1) {
        ckmax(ind,i);
        while (ind < r+1 && R.query(i,ind) > num) ind ++;
        co[num] += r+1-ind;
        // if (num == 16) pr("OOPS",l,r,i,ind);
    }
    // pr("HA",num,l,r,co[num]);
}

ll c2(ll x) { return x*(x+1)/2; }

ll gre(ll x, ll y) {
    if (x % y == 0) return x/y+1;
    if (x < 0) return x/y;
    return x/y+1;
}

ll le(ll x, ll y) {
    if (x % y == 0) return x/y;
    if (x < 0) return x/y-1;
    return x/y;
}


ll getSum (ll a, ll b) { // sum of a+(a-b)+(a-2b)+...
    if (a <= 0) return 0;
    ll z = a/b;
    return (z+1)*(2*a-z*b)/2;
}

ll getTri(ll c, ll a, ll b) { // count number of lattice points (x,y) such that 0<x,y and ax+by <= c 
    if (a+b > c) return 0;
    if (a > b) swap(a,b);
    ll k = b/a; 
    // if ax+kay <= kac/b then we can divide by a and count 
    // otherwise x > kc/b-ky so we can subtract the latter expression from x and continue
    return getTri(c-a*(c*k/b),a,b-k*a)+getSum(c*k/b-k,k);
}

ll sumv2(ll a, ll i, ll j, ll mn, ll mx) {
    ll ret = mx-mn+1;
    ret += getTri(a-(mn-1)*i,i,j);
    ret -= getTri(a-mx*i,i,j);
    return ret;
}

ll tri(ll x, int i, int j) {
    ll ans = 0;
    if (i == j) {
        ll mx = x/i;
        if (mx < co[i]) ans = mx*(co[i]-mx);
        return ans;
    }
    if (j == MX) {
        // cum[MX-1]-cum[i]+i*? <= x 
        // i*? <= x+cum[i]-cum[MX-1]
        ll d = x+cum[i]-cum[MX-1];
        if (d < 0) return 0;
        d = min(d/i,co[i]);
        ans = c2(d)+(sumco[MX-1]-sumco[i])*d; 
        return ans;
    } 
    // i*v_1+cum[j-1]-cum[i]+j*v_2 > x 
    
    // we need i*v_1+cum[j-1]-cum[i] <= x 
    ll v1hi = min(le(x+cum[i]-cum[j-1],i),co[i]);
    // we need i*v_1+cum[j-1]-cum[i]+j*co[j] > x
    ll v1lo = max(gre(x-j*co[j]+cum[i]-cum[j-1],i),1LL);
    if (v1lo > v1hi) return 0;
    
    // compute v_1+sumco[j-1]-sumco[i]+v_2-1 over all values of v_1
    
    ans += (v1lo+v1hi)*(v1hi-v1lo+1)/2;
    ans += (v1hi-v1lo+1)*(sumco[j-1]-sumco[i]-1);
    // j*v_2 > x-(cum[j-1]-cum[i])-i*v_1 for v_1 in [v1lo,v1hi];
    ans += sumv2(x-(cum[j-1]-cum[i]),i,j,v1lo,v1hi);
    // sum of the values of v2 
    return ans;
}

ll getNum(ll x) {
    int i1 = 1, i2 = 1;
    ll ret = 0;
    FOR(i,1,MX) {
        while (i1 < MX && cum[i1]-cum[i-1] <= x) i1 ++;
        while (i2 < MX && cum[i2]-cum[i] <= x) i2 ++;
        FOR(j,i1,i2+1) ret += tri(x,i,j);
    }
    return ret;
}

void init() {
    // you should actually read the stuff at the bottom
    FOR(i,1,MX) for (int j = i; j < MX; j += i) fac[j].pb(i);
    setIO(); re(n); a.resz(n); re(a);
    R.build(a);
    F0R(i,n) for (int j: fac[a[i]]) oc[j].pb(i);
    FOR(i,1,MX) {
        for (int j = 0; j < sz(oc[i]); ) {
            int t = j; while (t+1 < sz(oc[i]) && oc[i][t+1] == oc[i][t]+1) t ++;
            dealWith(i,oc[i][j],oc[i][t]);
            j = t+1;
        }
    }
}

int main() {
    init();
    FOR(i,1,MX) {
        cum[i] = co[i]*i+cum[i-1];
        sumco[i] = co[i]+sumco[i-1];
    }
    t1 = c2(n), t2 = c2(t1), des = (t2+1)/2; 
    /*vl a; FOR(i,1,MX) F0R(j,co[i]) a.pb(i);
    vl b;
    F0R(i,sz(a)) {
        ll sum = 0;
        FOR(j,i,sz(a)) {
            sum += a[j];
            b.pb(sum);
        }
    }*/
    ll lo = 1, hi = 1e15;
    while (lo < hi) {
        ll mid = (lo+hi)/2;
        if (getNum(mid) >= des) hi = mid;
        else lo = mid+1;
        // first 
    }
    pr(lo);
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/