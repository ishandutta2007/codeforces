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

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;

int n;
vi v;

void f(int a, int b) {
    swap(v[a],v[b]);
    if (a > b) swap(a,b);
    cout << a+1 << " " << b+1 << "\n";
}

void solve4(int x) {
    f(x,x+1); f(x+2,x+3); // badc cdab abcd
    f(x,x+2); f(x+1,x+3);
    f(x,x+3); f(x+1,x+2);
}

void flip(int a, int b, int c, int d) {
    f(a,c), f(b,d);
    f(c,b), f(a,d);
}

void solve4(int x0, int x1) {
    F0R(i,2) F0R(j,2) flip(x0+2*i,x0+2*i+1,x1+2*j,x1+2*j+1);
}

void solve5(int x, int y) { // generate by brute force 
    FOR(i,1,4) f(x,x+i);
    f(x+1,x+2); f(x+1,y); f(x+2,y); f(x,y); 
    f(x+2,x+3); f(x+1,x+3); f(x+3,y);
}

void brute() {
    vpi v;
    F0R(i,n) FOR(j,i+1,n) v.pb({i,j});
    do {
        vi x(n); F0R(i,n) x[i] = i;
        for (auto a: v) swap(x[a.f],x[a.s]);
        bool ok = 1; F0R(i,n) if (x[i] != i) ok = 0;
        if (ok) {
            for (auto a: v) cout << a.f << " " << a.s << " | ";
            cout << "\n";
            exit(0);
        }
    } while (next_permutation(all(v)));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n; v.resize(n); F0R(i,n) v[i] = i;
    if (n % 4 == 3 || n % 4 == 2) {
        cout << "NO";
        exit(0);
    }
    cout << "YES\n";
    for (int i = 0; i+1 < n; i += 4)
        for (int j = i+4; j+1 < n; j += 4)
            solve4(i,j);
    
    if (n % 4 == 0) {
        for (int i = 0; i+1 < n; i += 4) solve4(i);
    }
    if (n % 4 == 1) {
        for (int i = 0; i+1 < n; i += 4) solve5(i,n-1);
    } 
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/