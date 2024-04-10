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
const int MX = 200001;

ll n, v[MX], par[MX], od[MX];
pi e[MX];
ll ans = 0;
vi adj[MX];

void gen(int cur) {
    e[cur].f = 1;
    for (int i: adj[cur]) if (i != par[cur]) {
        par[i] = cur; od[i] = od[cur]^1;
        gen(i);
        e[cur].f += e[i].s, e[cur].s += e[i].f;
    }
}

void ad(ll& a, ll b) {
    a = (a+b)%MOD;
}

ll mul(ll a, ll b) {
    a = (a%MOD+MOD)%MOD;
    b = (b%MOD+MOD)%MOD;
    return a*b%MOD;
}

void solve(int ind) {
    pi E;
    if (od[ind]) E = {e[1].s,e[1].f};
    else E = {e[1].f,e[1].s};
    
    // cout << "HI " << ind << " " << E.f << " " << E.s << " " << v[ind] << "\n";
    ad(ans,mul(n,v[ind]));
    E.f --;
    
    for (int i: adj[ind]) if (i != par[ind]) {
        ad(ans,mul(e[i].s-e[i].f,mul(v[ind],n-e[i].f-e[i].s)));
        E.f -= e[i].s, E.s -= e[i].f;
    }
    
    ad(ans,mul(E.f-E.s,mul(v[ind],n-E.f-E.s)));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n; FOR(i,1,n+1) cin >> v[i];
    F0R(i,n-1) {
        int u,v; cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    }
    gen(1);
    FOR(i,1,n+1) solve(i);
    cout << ans;
}

// read the question correctly (is y a vowel?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)