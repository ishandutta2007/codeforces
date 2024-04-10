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


const int MOD = (119 << 23) + 1, root = 3; // = 998244353
// For p < 2^30 there is also e.g. (5 << 25, 3), (7 << 26, 3),
// (479 << 21, 3) and (483 << 21, 5). The last two are > 10^9.

const ll INF = 1e18;
const int MX = 100001;

namespace ModOp {
    ll po (ll b, ll p) { return !p?1:po(b*b%MOD,p/2)*(p&1?b:1)%MOD; }
    ll inv (ll b) { return po(b,MOD-2); }
    
    int ad(int a, int b) { return (a+b)%MOD; }
    int sub(int a, int b) { return (a-b+MOD)%MOD; }
    int mul(int a, int b) { return (ll)a*b%MOD; }
    
    int AD(int& a, int b) { return a = ad(a,b); }
    int SUB(int& a, int b) { return a = sub(a,b); }
    int MUL(int& a, int b) { return a = mul(a,b); }
}

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

using namespace ModOp;

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

namespace NTT {
    int get(int s) {
        return s > 1 ? 32 - __builtin_clz(s - 1) : 0;
    }
    
    vi ntt(vi& a) { 
        int n = sz(a), x = get(n); 
        vi res, RES(n), roots(n);
        roots[0] = 1, roots[1] = po(root,(MOD-1)/n);
        FOR(i,2,n) roots[i] = mul(roots[i-1],roots[1]);
        
        res = a;
        FOR(i,1,x+1) {
            int inc = n>>i;
            F0R(j,inc) for (int k = 0; k < n; k += inc) {
                int t = 2*k%n+j;
                RES[k+j] = ad(res[t],mul(roots[k],res[t+inc]));
            }
            swap(res,RES);
        }
        
        return res;
    }
    
    vi ntt_rev(vi& a) {
        vi res = ntt(a);
        ll in = inv(sz(a));
        F0R(i,sz(res)) MUL(res[i],in);
        reverse(res.begin() + 1, res.end());
        return res;
    }
    
    vi conv(vi a, vi b) {
        int s = sz(a)+sz(b)-1, L = get(s), n = 1<<L;
        if (s <= 0) return {};
        
        a.resize(n); a = ntt(a);
        b.resize(n); b = ntt(b);
        
        F0R(i,n) MUL(a[i],b[i]);
        
        a = ntt_rev(a);
        a.resize(s);
        return a;
    }
}

int N, fac[MX], ifac[MX];
ll M;

vi comb2(vi P) {
    vi dif;
    F0Rd(i,N+1) dif.pb(ifac[i]);
    F0R(i,N+1) MUL(P[i],fac[i]);
    vi res = NTT::conv(dif,P);
    vi ans; 
    FOR(i,N,2*N+1) ans.pb(mul(res[i],ifac[i-N]));
    return ans;
}

vi comb(vi P) {
    vi dif;
    F0Rd(i,N+1) {
        int x = ifac[i];
        if (i&1) x = MOD-x;
        dif.pb(x);
    }
    F0R(i,N+1) MUL(P[i],fac[i]);
    vi res = NTT::conv(dif,P);
    vi ans; 
    FOR(i,N,2*N+1) ans.pb(mul(res[i],ifac[i-N]));
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    fac[0] = ifac[0] = 1;
    FOR(i,1,MX) {
        fac[i] = mul(i,fac[i-1]);
        ifac[i] = inv(fac[i]);
    }
    cin >> N >> M;
    vi P(N+1);
    F0R(i,N+1) cin >> P[i];
    P = comb2(P);
    F0R(i,N+1) MUL(P[i],po(inv(i+1),M));
    P = comb(P);
    F0R(i,N+1) cout << P[i] << " ";
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/