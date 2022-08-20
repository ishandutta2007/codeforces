
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

int m,n,nex;
vi hidden;
int h = 0, des = 10001;
vi p;

void finish(int x) {
    cout << x << endl;
    exit(0);
}

int gen(int x) {
    int res;
    if (des < x) res = -1;
    else if (des == x) res = 0;
    else res = 1;
    
    if (hidden[h%sz(hidden)] == 0) res *= -1;
    h ++;
    return res;
}

int query(int x) {
    cout << x << endl;
    //int t = gen(x); 
    int t; cin >> t;
    if (t == 0) finish(x);
    return t;
}

int QUERY(int x) {
    int t = query(x);
    if (p[nex%sz(p)] == 0) t *= -1;
    nex ++;
    return t;
}

int main() {
    F0R(i,30) hidden.pb(0);
    int m,n; cin >> m >> n;
    F0R(i,n) {
        int t = query(m);
        p.pb(t == -1);
    }
    /*for (int i: p) cout << i << " ";
    cout << "\n";*/
    int lo = 1, hi = m;
    while (lo < hi) {
        // cout << "OOPS " << lo << " " << hi << "\n";
        int mid = (lo+hi)/2;
        int t = QUERY(mid);
        if (t == -1) hi = mid-1;
        else lo = mid+1;
    }
    // 2^30 
    // 7: 3
    // 3: 2 
    // 1: 1 
    finish(lo);
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
*/