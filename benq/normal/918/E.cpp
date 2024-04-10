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
const ll INF = 4e18;
const int MX = 100001;

int x,k,n,q,c[9];
vi ok;

template<int SZ> struct mat {
    array<array<ll,SZ>,SZ> d;
    
    mat() {
        F0R(i,SZ) F0R(j,SZ) d[i][j] = INF;
    }
    
    mat operator+(const mat& m) {
        mat<SZ> a;
        F0R(i,SZ) F0R(j,SZ) a.d[i][j] = (d[i][j]+m.d[i][j]) % MOD;
        return a;
    }
    
    mat operator*(const mat& m) {
        mat<SZ> a;
        for (int i: ok)
            for (int j: ok)
                for (int k: ok)
                    a.d[i][k] = min(a.d[i][k],d[i][j]+m.d[j][k]);
        return a;
    }
    
    mat operator^(ll p) {
        mat<SZ> a, b(*this); 
        F0R(i,SZ) a.d[i][i] = 0;
        
        while (p) {
            if (p&1) a = a*b;
            b = b*b;
            p /= 2;
        }
        
        return a;
    }
    
    void print() {
        F0R(i,SZ) {
            F0R(j,SZ) cout << d[i][j] << " ";
            cout << "\n";
        }
        cout << "------------\n";
    }
};

vl mult(vl a, mat<256> b) {
    vl A(256); F0R(i,256) A[i] = INF;
    for (int i: ok)
        for (int j: ok)
            A[j] = min(A[j],a[i]+b.d[i][j]);
            
    return A;
}

mat<256> trans;
vl a(256);
set<int> man;
map<int,int> wei;
int lst = 1;

void solve(int ind) {
    a = mult(a,trans^(ind-lst));
    
    mat<256> TRANS = trans;
    F0R(i,1<<k) if (__builtin_popcount(i) == x) {
        if (i&1) {
            F0R(j,k) if (!((i/2)&(1<<j))) {
                if (wei.count(ind+j+1)) {
                    TRANS.d[i][(1<<j)+i/2] = c[j+1]+wei[ind+j+1];
                } else TRANS.d[i][(1<<j)+i/2] = c[j+1];
            }
        } else {
            TRANS.d[i][i/2] = 0;
        }
    }
    
    a = mult(a,TRANS);
    lst = ind+1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> x >> k >> n >> q;
    FOR(i,1,k+1) cin >> c[i];
    F0R(i,1<<k) if (__builtin_popcount(i) == x) ok.pb(i);
    for (int i: ok) {
        if (i&1) {
            F0R(j,k) if (!((i/2)&(1<<j))) trans.d[i][(1<<j)+i/2] = c[j+1];
        } else {
            trans.d[i][i/2] = 0;
        }
    }
    if (n > x) man.insert(n-x);
    
    F0R(i,q) {
        int p,wp; cin >> p >> wp;
        wei[p] = wp;
        FOR(j,1,k+1) if (p-j >= 1 && p-j <= n-x) man.insert(p-j);
    }
    
    F0R(i,256) a[i] = INF;
    a[(1<<x)-1] = 0;
    for (int i: man) solve(i);
    cout << a[(1<<x)-1];
    
}

// read the question correctly (is y a vowel?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)