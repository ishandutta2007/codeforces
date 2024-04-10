#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<double,double> pd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef array<array<int,100>,100> mat;

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
const double PI = 4*atan(1);
const ll INF = 1e18;
const int MX = 100001;

ll po (ll b, ll p) {
    return !p?1:po(b*b%MOD,p/2)*(p&1?b:1)%MOD;
}

ll inv (ll b) { return po(b,MOD-2); }
    
namespace Poly {
    ll norm(ll x) { return (x%MOD+MOD)%MOD; }

    vl operator+(vl a, vl b) {
        a.resize(max(sz(a),sz(b)));
        F0R(i,sz(a)) a[i] = norm(a[i]+b[i]);
        return a;
    }
    
    vl operator*(vl a, vl b) {
        vl x(sz(a)+sz(b)-1);
        F0R(i,sz(a)) F0R(j,sz(b)) x[i+j] = norm(x[i+j]+a[i]*b[j]);
        return x;
    }
    
    vl operator*(vl a, ll b) {
        for (ll& i: a) i = norm(i*b);
        return a;
    }
    
    vl interpolate(vector<pl> v) {
        vl ret;
        F0R(i,sz(v)) {
            vl prod = {1};
            ll todiv = 1;
            F0R(j,sz(v)) if (i != j) {
                todiv = norm(todiv*(v[i].f-v[j].f));
                vl tmp = {norm(-v[j].f),1};
                prod = prod*tmp;
            }
            prod = prod*inv(todiv);
            prod = prod*v[i].s;
            ret = ret+prod;
        }
        return ret;
    }
    
    void prin(vl x) {
        for (ll i: x) cout << i << " ";
        cout << "\n";
    }
}

int SZ;

mat m, cur;
vector<pl> res;
int n;

void elim(mat& m, int a, int c) { // column, done row, todo row
    ll x = m[c][a];
    FOR(i,a,SZ) {
        m[c][i] = (m[c][i]-x*m[a][i])%MOD;
        if (m[c][i] < 0) m[c][i] += MOD;
    }
}

ll det(mat m) {
    ll prod = 1;
    F0R(i,SZ) {
        bool done = 0;
        FOR(j,i,SZ) if (m[j][i] != 0) {
            done = 1; if (j != i) swap(m[j],m[i]);
            if ((j-i)&1) prod *= -1;
            prod = prod*m[i][i]%MOD;
            ll x = inv(m[i][i]);
            FOR(k,i,SZ) m[i][k] = m[i][k]*x%MOD;
            FOR(k,i+1,SZ) elim(m,i,k);
            break;
        }
        if (!done) return 0;
    }
    return (prod%MOD+MOD)%MOD;
}


ll get() { return det(cur); }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n; 
    F0R(i,n) F0R(j,n) {
        if (i != j) cur[i][j] = MOD-1;
        else cur[i][j] = n-1;
    }
    F0R(i,n-1) {
        int a,b; cin >> a >> b; a--, b --;
        m[a][b] --, m[b][a] --;
        m[a][a] ++, m[b][b] ++;
    }
    SZ = n-1;
    FOR(i,1,n+1) {
        res.pb({i,get()});
        F0R(j,n) F0R(k,n) cur[j][k] += m[j][k];
    }
    vl RES = Poly::interpolate(res);
    for (ll x: RES) cout << x << " ";
}

// read the question correctly (is y a vowel?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)