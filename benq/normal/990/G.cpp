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

int n, A[MX];
ll oc[MX];
vi adj[MX];

map<int,int> dfs(int cur, int par) {
    map<int,int> res; res[A[cur]] ++, oc[A[cur]] ++;
    for (int i: adj[cur]) if (i != par) {
        auto a = dfs(i,cur);
        for (auto x: a) for (auto y: res) oc[__gcd(x.f,y.f)] += (ll)x.s*y.s;
        for (auto x: a) res[__gcd(x.f,A[cur])] += x.s;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n; FOR(i,1,n+1) cin >> A[i];
    F0R(i,n-1) {
        int a,b; cin >> a >> b;
        adj[a].pb(b), adj[b].pb(a);
    }
    dfs(1,0);
    FOR(i,1,MX) if (oc[i]) cout << i << " " << oc[i] << "\n";
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS