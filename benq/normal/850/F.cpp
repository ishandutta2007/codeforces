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

/*ld ad(ld a, ld b) { return a+b; }
ld sub(ld a, ld b) { return a-b; }
ld mul(ld a, ld b) { return a*b; }
ld AD(ld& a, ld b) { return a = ad(a,b); }
ld SUB(ld& a, ld b) { return a = sub(a,b); }
ld MUL(ld& a, ld b) { return a = mul(a,b); }
ld inv(ld x) { return 1/x; }

struct mat {
    ld** d;
    int a, b;
    
    mat() { a = b = 0; }

    mat(int _a, int _b) {
        a = _a, b = _b;
        d = new ld*[a];
        F0R(i,a) {
            d[i] = new ld[b];
            F0R(j,b) d[i][j] = 0;
        }
    }
    
    mat (vector<vd> v) : mat(sz(v),sz(v[0])) {
        F0R(i,a) F0R(j,b) d[i][j] = v[i][j];
    }
    
    void print() {
        F0R(i,a) {
            F0R(j,b) cout << d[i][j] << " ";
            cout << "\n";
        }
        cout << "------------\n";
    }
    
    mat operator+(const mat& m) {
        mat r(a,b);
        F0R(i,a) F0R(j,b) r.d[i][j] = ad(d[i][j],m.d[i][j]);
        return r;
    }
    
    mat operator*(const mat& m) {
        mat r(a,m.b);
        F0R(i,a) F0R(j,b) F0R(k,m.b) 
            AD(r.d[i][k],mul(d[i][j],m.d[j][k]));
        return r;
    }

    mat operator^(ll p) {
        mat r(a,a), base(*this); 
        F0R(i,a) r.d[i][i] = 1;
        
        while (p) {
            if (p&1) r = r*base;
            base = base*base;
            p /= 2;
        }
        
        return r;
    }
};

namespace matInv {
    void elim(mat& m, int col, int a, int b) { // column, todo row
        ld x = m.d[b][col];
        FOR(i,col,m.b) SUB(m.d[b][i],mul(x,m.d[a][i]));
    }
    
    ld gauss(mat& m) { // determinant of 1000x1000 matrix in ~1s
        ld prod = 1;
        int nex = 0;
        
        F0R(i,m.a) {
            int row = -1;
            FOR(j,nex,m.a) if (abs(m.d[j][i]) > 1e-9) { row = j; break; }
            // pr(i,row,prod);
            if (row == -1) { prod = 0; continue; }
            if (row != nex) MUL(prod,-1), swap(m.d[row],m.d[nex]);
            
            MUL(prod,m.d[nex][i]);
            auto x = inv(m.d[nex][i]);
            FOR(k,i,m.b) MUL(m.d[nex][k],x);
            
            F0R(k,m.a) if (k != nex) elim(m,i,nex,k);
            nex ++;
        }
        
        return prod;
    }

    ll numSpan(mat m) { // Kirchhoff's theorem
        mat res(m.a-1,m.a-1);
        F0R(i,m.a) FOR(j,i+1,m.a) {
            if (i) {
                AD(res.d[i-1][i-1],m.d[i][j]);
                SUB(res.d[i-1][j-1],m.d[i][j]);
                SUB(res.d[j-1][i-1],m.d[i][j]);
            }
            AD(res.d[j-1][j-1],m.d[i][j]);
        }
        return gauss(res);
    }
    
    mat inv(mat m) {
        mat x(m.a,2*m.a);
        F0R(i,m.a) F0R(j,m.a) x.d[i][j] = m.d[i][j];
        F0R(i,m.a) x.d[i][i+m.a] = 1;
        
        if (gauss(x) == 0) return mat(0,0);
        // x.print();
        mat r(m.a,m.a);
        F0R(i,m.a) F0R(j,m.a) r.d[i][j] = x.d[i][j+m.a];
        return r;
    }
}

map<vi,int> m;

bool done(vi x) {
    return x[sz(x)-2] == 0;
}

void dfs(vi x) {
    sort(all(x));
    if (m.count(x)) return;
    int t = sz(m); m[x] = t;
    if (done(x)) return;
    F0R(i,sz(x)) if (x[i]) F0R(j,sz(x)) if (x[j]) {
        auto X = x; X[i] --, X[j] ++;
        dfs(X);
    }
}

ld get(vi v) {
    sort(all(v));
    m.clear();
    dfs(v);
    int sum = 0;
    for (int i: v) sum += i;
    mat tmp(sz(m),sz(m));
    vd fin(sz(m));
    trav(x,m) {
        tmp.d[x.s][x.s] = 1;
        if (!done(x.f)) {
            fin[x.s] = 1;
            F0R(i,sz(x.f)) F0R(j,sz(x.f)){
                auto X = x.f; if (!X[i] || !X[j]) continue;
                ld prob = (ld)X[i]*(X[j]-(j == i))/sum/(sum-1);
                X[i] --, X[j] ++;
                // pr(x.s,i,j,X[i],X[j]-(j == i),sum*(sum-1));
                sort(all(X));
                tmp.d[x.s][m[X]] -= prob;
                // pr(x,m[X]);
            }
        }
    }
    // tmp.print();
    auto a = matInv::inv(tmp);
    // a.print();
    a.print(); 
    pr(a.a,a.b);
    exit(0);
    ld res = 0;
    F0R(i,sz(m)) res += a.d[m[v]][i]*fin[i];
    return res;
    trav(x,m) {
        ld res = 0;
        F0R(i,sz(m)) res += a.d[x.s][i]*fin[i];
        pr(x.f,res);
    }
    // pr(res); exit(0);
    pr(m);
    tmp.print(); 
    pr(fin);
    exit(0);
}*/

int n, cum[MX];
vi a;

int main() {
    // you should actually read the stuff at the bottom
    setIO(); 
    /*FOR(sum,1,6) for (int i = 1; 2*i <= sum; ++i) {
        vi v = {i,sum-i};
        pr(v,get(v));
    }*/
    re(n); a.resz(n); re(a);
    int sum = 0, ans = 0; trav(x,a) sum += x;
    FOR(i,1,MX) cum[i] = ad(cum[i-1],inv(sum+1-i));
    trav(x,a) AD(ans,mul(sum-x,cum[x]));
    MUL(ans,sum-1); pr(ans);
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/