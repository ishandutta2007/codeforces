#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<double,double> pd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;

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

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;


int R,a[4];
map<pi,int> m;
vpi M;
int xd[4] = {-1,0,1,0}, yd[4] = {0,-1,0,1};

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

ll po (ll b, ll p) { return !p?1:po(b*b%MOD,p/2)*(p&1?b:1)%MOD; }
ll inv (ll b) { return po(b,MOD-2); }

int mul(ll a, ll b) { return a*b%MOD; }
int sub(int a, int b) { return (a-b<0)?a-b+MOD:a-b; }

void elim(mat& m, int a, int c) { // column, todo row
    ll x = m.d[c][a];
    if (!x) return;
    
    FOR(i,a,min(m.b-1,a+2*R+1)) {
        m.d[c][i] = sub(m.d[c][i],mul(x,m.d[a][i]));
    }
    FOR(i,m.b-1,m.b) {
        m.d[c][i] = sub(m.d[c][i],mul(x,m.d[a][i]));
        
    }
}

vl ans;

void det(mat& x, bool b = 0) { // determinant of 1000x1000 matrix in ~1s
    mat m = x;
    ll prod = 1;
    F0R(i,m.a) {
        FOR(j,i,m.a) if (m.d[j][i] != 0) {
            swap(m.d[j],m.d[i]);
            
            if ((j-i)&1) prod = mul(prod,MOD-1);
            prod = mul(prod,m.d[i][i]);
            
            ll x = inv(m.d[i][i]);
            FOR(k,i,m.b) m.d[i][k] = mul(m.d[i][k],x);
            FOR(k,i+1,min(m.a,i+2*R+1)) elim(m,i,k);
            break;
        }
    }
    ans.resize(m.a);
    F0Rd(i,sz(ans)) {
        ans[i] = m.d[i][m.a];
        FOR(j,i+1,m.a) ans[i] = sub(ans[i],mul(m.d[i][j],ans[j]));
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R; F0R(i,4) cin >> a[i];
    int sum = 0; F0R(i,4) sum += a[i];
    F0R(i,4) a[i] = mul(a[i],inv(sum));
    FOR(i,-R,R+1) FOR(j,-R,R+1) if (i*i+j*j <= R*R) {
        int x = sz(m);
        m[{i,j}] = x;
        M.pb({i,j});
    }
    
    mat ma(sz(M),sz(M)+1);
    F0R(i,sz(M)) {
        ma.d[i][i] = 1;
        F0R(j,4) {
            pi z = {M[i].f+xd[j],M[i].s+yd[j]};
            if (m.count(z)) ma.d[i][m[z]] = MOD-a[j];
            // if (m.count(z) && i == m[z]) cout << i << " " << M[i].f << " " << M[i].s << " " << z.f << " " << z.s << " " << m[z] << "\n";
        }
        ma.d[i][sz(M)] = 1;
    }
    
    det(ma,1);
    F0R(i,sz(M)) if (M[i] == mp(0,0)) cout << ans[i];
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)