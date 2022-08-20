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

const ll INF = 1e18;
const int MX = 100001;
int MOD;

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
    
    // double input seems slow on CF
    void re(double& x) { string t; cin >> t; x = stod(t); } 
    void re(ld& x) { string t; cin >> t; x = stold(t); }
    template<class T> void re(T& x) { cin >> x; }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { re(first); re(rest...); }
    
	// pair
	template<class T1, class T2> istream& operator>>(istream& is, pair<T1,T2>& p) {
	    is >> p.f >> p.s;
	    return is;
	}
	template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) {
	    os << '{' << a.f << ", " << a.s << '}';
	    return os;
	}
	
    // vector
	template<class T> istream& operator>>(istream& is, vector<T>& a) {
	    int sz; is >> sz; a.resize(sz);
	    F0R(i,sz) is >> a[i];
	    return is;
	}
	template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
	    os << "{";
	    F0R(i,sz(a)) {
	        if (i) os << ", ";
	        os << a[i];
	    }
	    os << "}";
	    return os;
	}
}

using namespace io;

struct mat {
    int** d;
    int a, b;
    
    mat() { a = b = 0; }

    mat(int _a, int _b) {
        a = _a, b = _b;
        d = new int*[a];
        F0R(i,a) {
            d[i] = new int[b];
            F0R(j,b) d[i][j] = 0;
        }
    }
    
    mat (vector<vi> v) : mat(sz(v),sz(v[0])) {
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
        F0R(i,a) F0R(j,b) r.d[i][j] = (d[i][j]+m.d[i][j]) % MOD;
        return r;
    }
    
    mat operator*(const mat& m) {
        mat r(a,m.b);
        F0R(i,a) F0R(j,b) F0R(k,m.b) 
            r.d[i][k] = (r.d[i][k]+(ll)d[i][j]*m.d[j][k]) % MOD;
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

namespace modOp {
    ll po (ll b, ll p) { return !p?1:po(b*b%MOD,p/2)*(p&1?b:1)%MOD; }
    ll inv (ll b) { return po(b,MOD-2); }
    
    ll inv(ll a, ll b) { // 0 < a < b, gcd(a,b) = 1
        a %= b;
        if (a <= 1) return a;
        ll i = inv(b%a,a);
        ll tmp = -((b/a)*i+((b%a)*i)/a) % b;
        if (tmp < 0) tmp += b;
        return tmp;
    }
    
    int ad(int a, int b) { return (a+b)%MOD; }
    int sub(int a, int b) { return (a-b+MOD)%MOD; }
    int mul(int a, int b) { return (ll)a*b%MOD; }
    
    int AD(int& a, int b) { return a = ad(a,b); }
    int SUB(int& a, int b) { return a = sub(a,b); }
    int MUL(int& a, int b) { return a = mul(a,b); }
}

using namespace modOp;

namespace matInv {
    void elim(mat& m, int col, int a, int b) { // column, todo row
        int x = m.d[b][col];
        FOR(i,col,m.b) SUB(m.d[b][i],mul(x,m.d[a][i]));
    }
    
    ll gauss(mat& m) { // determinant of 1000x1000 matrix in ~1s
        int prod = 1, nex = 0;
        
        F0R(i,m.a) {
            int row = -1;
            FOR(j,nex,m.a) if (m.d[j][i] != 0) { row = j; break; }
            if (row == -1) { prod = 0; continue; }
            if (row != nex) MUL(prod,MOD-1), swap(m.d[row],m.d[nex]);
            
            MUL(prod,m.d[nex][i]);
            int x = inv(m.d[nex][i]);
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
        
        mat r(m.a,m.a);
        F0R(i,m.a) F0R(j,m.a) r.d[i][j] = x.d[i][j+m.a];
        return r;
    }
}

using namespace matInv;

map<int,int> m;
int d,cur=2;

int adIndex(int a, int b) {
    m[++cur] = ad(m[a],m[b]);
    cout << "+ " << a << " " << b << " " << cur << "\n";
    return cur;
}

int poIndex(int a) {
    int res = 1;
    F0R(i,d) res = mul(res,m[a]);
    m[++cur] = res;
    cout << "^ " << a << " " << cur << "\n";
    return cur;
}

// derived 

int mulFixed(int a, int fac) {
    while (fac <= 1) fac += MOD;
    vi v = {a};
    for (int i = 1; (1<<i) <= fac; ++i) v.pb(adIndex(v[i-1],v[i-1]));
    int tmp = v[sz(v)-1];
    F0Rd(i,sz(v)-1) if (fac&(1<<i)) tmp = adIndex(tmp,v[i]);
    return tmp;
}

int subIndex(int a, int b) {
    return adIndex(a,mulFixed(b,-1));
}

int com[11][11];

int sq(int x) {
    mat M(d+1,d+1);
    F0R(i,d+1) F0R(j,d+1) M.d[i][j] = mul(po(i,d-j),com[d][j]);
    M = inv(M);
    int cx = x, ans;
    F0R(i,d+1) {
        //cout << "OH " << cx << " " << m[cx] << "\n";
        int tmp = mulFixed(poIndex(cx),M.d[2][i]);
        if (i == 0) ans = tmp;
        else ans = adIndex(ans,tmp);
        //cout << "AA " << cx << " " << m[cx] << "\n";
        cx = adIndex(cx,++cur);
        //cout << "BB " << cx << " " << m[cx] << "\n";
    }
    return ans;
}

int solve() {
    int xy = adIndex(1,2);
    int sx = sq(1), sy = sq(2), sxy = sq(xy);
    int d = subIndex(subIndex(sxy,sx),sy);
    return mulFixed(d,(MOD+1)/2);
}

int main() {
    setIO(); re(d,MOD);
    com[0][0] = 1;
    FOR(i,1,d+1) F0R(j,i+1) {
        com[i][j] = com[i-1][j];
        if (j) AD(com[i][j],com[i-1][j-1]);
    }
    FOR(i,1,5001) m[i] = 1;
    m[1] = rand() % MOD;
    m[2] = rand() % MOD;
    //int f = sq(1);
    //cout << f << " " << m[f] << "\n";
    // cout << mul(m[1],m[1]) << " " << x << " " << m[x] << "\n";
    // cout << m[1] << " " << m[2] << "\n";
    // cout << (m[1]-m[2]+p)%p << " " << m[sub(1,2)] << "\n";
    int f = solve();
    cout << "f " << f << "\n";
    // cout << mul(m[1],m[2]) << " " << m[f];
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/