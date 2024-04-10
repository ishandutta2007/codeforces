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

const int MOD = 998244353;
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

using namespace modOp;


namespace vecOp {
    template<class T> T operator+=(T& l, const T& r) { return l = l+r; }
    template<class T> T operator-=(T& l, const T& r) { return l = l-r; }
    template<class T> T operator*=(T& l, const T& r) { return l = l*r; }

    vi rev(vi v) { reverse(all(v)); return v; }
    vi operator+(const vi& l, const vi& r) {
        vi res(max(sz(l),sz(r)));
        F0R(i,sz(l)) res[i] = l[i];
        F0R(i,sz(r)) AD(res[i],r[i]);
        return res;
    }
    vi operator-(const vi& l, const vi& r) {
        vi res(max(sz(l),sz(r)));
        F0R(i,sz(l)) res[i] = l[i];
        F0R(i,sz(r)) SUB(res[i],r[i]);
        return res;
    }
    vi operator*(const vi& l, const vi& r) {
        if (min(sz(l),sz(r)) == 0) return {};
        vi x(sz(l)+sz(r)-1);
        F0R(i,sz(l)) F0R(j,sz(r)) AD(x[i+j],mul(l[i],r[j]));
        return x;
    }
    vi operator*(const vi& l, const int& r) {
        int R = (r%MOD+MOD)%MOD;
        vi L = l; 
        for (int& i: L) MUL(i,R); 
        return L;
    }
    vi operator*(const int& l, const vi& r) { return r*l; }
    vi operator*=(vi& l, const int& r) { return l = l*r; }
    
    vi rem(vi a, vi b) { 
        while (sz(b) && b.back() == 0) b.pop_back();
        assert(sz(b)); b *= inv(b.back());
        while (sz(a) >= sz(b)) {
            int k = a.back();
            F0R(i,sz(b)) SUB(a[sz(a)-sz(b)+i],mul(k,b[i]));
            while (sz(a) && a.back() == 0) a.pop_back();
        }
        return a;
    }
        
    vi interpolate(vpi v) {
        vi ret;
        F0R(i,sz(v)) {
            vi prod = {1};
            int todiv = 1;
            F0R(j,sz(v)) if (i != j) {
                MUL(todiv,sub(v[i].f,v[j].f));
                vi tmp = {sub(0,v[j].f),1};
                prod *= tmp;
            }
            ret += prod*mul(inv(todiv),v[i].s);
        }
        return ret;
    }
}

using namespace vecOp;

int n,t,ans;
vpi v;
vi ti;

int solve(multiset<pi>& m) {
    int l = -MOD;
    int ans = 0;
    trav(x,m) {
        ckmax(l,x.f-1);
        ans += max(x.s-l,0);
        ckmax(l,x.s);
    }
    return ans;
}

ll f(int x) {
    multiset<pi> m;
    vector<array<int,4>> ev;
    trav(z,v) ev.pb({z.f-x,1,z.s-x,z.s+x});
    trav(z,v) ev.pb({z.f+x+1,-1,z.s-x,z.s+x});
    sort(all(ev));
    ll ret = 0;
    F0R(i,sz(ev)) {
        if (i) ret += (ll)(ev[i][0]-ev[i-1][0])*solve(m);
        if (ev[i][1] == -1) m.erase(m.find({ev[i][2],ev[i][3]}));
        else m.insert({ev[i][2],ev[i][3]});
    }
    return ret;
}

int getRange(int l, int r) {
    vpi v = {{l-1,0}};
    FOR(i,l,l+3) v.pb({i,(v.back().s+f(i))%MOD});
    // pr(v);
    // pr(interpolate(v));
    vi V = interpolate(v);
    int ret = 0, fac = 1;
    F0R(i,sz(v)) {
        AD(ret,mul(V[i],fac));
        MUL(fac,r);
    }
    /*FOR(i,l,r+1) {
        ll t = f(i);
        if (i % 100 == 0) pr(i,t);
        AD(ret,t%MOD);
    }*/
    return ret;
}

int main() {
    // you should actually read the stuff at the bottom
    setIO(); re(n,t); v.resz(n); re(v);
    ti.pb(0), ti.pb(t);
    F0R(i,n) FOR(j,i+1,n) {
        int dif = max(abs(v[i].f-v[j].f),abs(v[i].s-v[j].s));
        dif = (dif+1)/2;
        if (dif <= t) ti.pb(dif);
    }
    sort(all(ti)); ti.erase(unique(all(ti)),ti.end());
    ans = mul(t,f(t)%MOD);
    F0R(i,sz(ti)-1) SUB(ans,getRange(ti[i],ti[i+1]-1));
    pr(ans);
    // t*f(t)-f(0)-f(1)-...-f(t-1)
    
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/