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
const int MX = 200001;

typedef unsigned long long ul;

ul N,M,A,B,C,ans;
vi adj[MX];
vector<bitset<MX>> has;
int key[MX];
vpi ed;

void solve0() {
    F0R(i,N) {
        ans += A*(N-1-i)*(N-2-i)/2*i;
        ans += B*i*(N-1-i)*i;
        ans += C*i*(i-1)/2*i;
    }
}

void solve1() {
    F0R(i,N) for (int j: adj[i]) if (i < j) {
        ans -= A*(i-1)*i/2+B*i*i+C*j*i;
        ans -= A*(j-i-1)*i+B*(i+j)*(j-i-1)/2+C*j*(j-i-1);
        ans -= A*(N-1-j)*i+B*(N-1-j)*j+C*(N-1-j)*(N+j)/2;
        // [i+1,j-1]
        // [j+1,n-1]
    }
}

void solve2() {
    F0R(i,N) {
        vi v0, v1;
        for (int j: adj[i]) {
            if (j < i) v0.pb(j);
            else v1.pb(j);
        }
        sort(all(v0)), sort(all(v1));
        ans += C*sz(v0)*(sz(v0)-1)/2*i;
        F0R(j,sz(v0)) {
            ans += B*j*v0[j];
            ans += A*(sz(v0)-1-j)*v0[j];
        }
        // do stuff
        ans += A*sz(v1)*(sz(v1)-1)/2*i;
        F0R(j,sz(v1)) {
            ans += C*j*v1[j];
            ans += B*(sz(v1)-1-j)*v1[j];
        }
        
        for (int j: v0) ans += A*j*sz(v1);
        for (int j: v1) ans += C*j*sz(v0);
        ans += B*sz(v0)*sz(v1)*i;
    }
}

ul eval(int a, int b, int c) {
    if (a > c) swap(a,c);
    if (a > b) swap(a,b);
    if (b > c) swap(b,c);
    return A*a+B*b+C*c;
}

bitset<MX> curhas;

void solve3() {
    F0R(i,N) {
        if (sz(adj[i])*sz(adj[i]) >= N) {
            key[i] = sz(has);
            has.pb(bitset<MX>());
            
            int K = key[i];
            for (int j: adj[i]) has[K][j] = 1;
            for (auto a: ed) if (a.s < i && has[K][a.f] && has[K][a.s]) ans -= eval(a.f,a.s,i);
        } else {
            sort(adj[i].rbegin(),adj[i].rend());
            for (int j: adj[i]) if (j < i) {
                if (sz(adj[j])*sz(adj[j]) >= N) {
                    for (int k: adj[i]) if (k < j && has[key[j]][k]) ans -= eval(j,k,i);
                } else {
                    for (int k: adj[j])  curhas[k] = 1;
                    for (int k: adj[i]) if (k < j && curhas[k]) ans -= eval(j,k,i);
                    for (int k: adj[j])  curhas[k] = 0;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> A >> B >> C;
    F0R(i,M) {
        int u, v; cin >> u >> v;
        if (u > v) swap(u,v);
        adj[u].pb(v), adj[v].pb(u);
        ed.pb({u,v});
    }
    // N = 500;
    solve0();
    solve1();
    solve2();
    solve3();
    cout << ans;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)