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

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;

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
    
    void print() {
        F0R(i,a) {
            F0R(j,b) cout << d[i][j] << " ";
            cout << "\n";
        }
        cout << "------------\n";
    }
    
    mat operator+(const mat& m) {
        mat r(a,b);
        F0R(i,a) F0R(j,b) r.d[i][j] = (d[i][j]+m.d[i][j]);
        return r;
    }
    
    vd operator*(const vd& v) {
        vd r(a);
        F0R(i,a) F0R(j,b) r[i] += d[i][j]*v[j];
        return r;
    }
    
    mat operator*(const mat& m) {
        mat r(a,m.b);
        F0R(i,a) F0R(j,b) F0R(k,m.b) 
            r.d[i][k] = (r.d[i][k]+d[i][j]*m.d[j][k]);
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

int n;
bool done[200][200];
pi pos[200];
vi res[200];
vector<vi> group;
mat prob[14];

pi operator-(const pi& a, const pi& b) {
    return {a.f-b.f,a.s-b.s};
}

bool col(pi a, pi b, pi c) {
    b = b-a;
    c = c-a;
    return b.s*c.f-b.f*c.s == 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    F0R(i,n) cin >> pos[i].f >> pos[i].s;
    F0R(i,n) FOR(j,i+1,n) if (!done[i][j]) {
        vi v = {i,j};
        FOR(k,j+1,n) if (col(pos[i],pos[j],pos[k])) v.pb(k);
        for (int a: v) for (int b: v) done[a][b] = 1;
        for (int a: v) res[a].pb(sz(group));
        group.pb(v);
    }
    
    prob[0] = mat(n,n);
    F0R(i,n) {
        // cout << "HI " << i << " " << sz(res[i]) << "\n";
        for (int j: res[i]) for (int k: group[j]) {
            prob[0].d[i][k] += 1.0/sz(res[i])/sz(group[j]);
            // cout << i << " " << k << 
        }
    }
    //prob[0].print();
    FOR(i,1,14) prob[i] = prob[i-1]*prob[i-1];
    //prob[1].print();
    int q; cin >> q;
    F0R(i,q) {
        int t,m; cin >> t >> m; t--, m--;
        vd tmp(n); tmp[t] = 1;
        F0Rd(j,14) if (m&(1<<j)) tmp = prob[j]*tmp;
        ld res = 0;
        for (auto a: group) {
            // cout << "HUH\n";
            ld sum = 0;
            for (int b: a) sum += tmp[b];
            res = max(res,sum/sz(a));
        }
        cout << fixed << setprecision(10) << res << "\n";
    }
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS