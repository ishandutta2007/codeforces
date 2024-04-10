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
const int MX = 50001;

int n,e,side[1000001], cur[MX];
vi team[MX];
vpi hate;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    srand(time(0)); cin >> n >> e;
    F0R(i,e) {
        int a,b; cin >> a >> b;
        hate.pb({a,b});
    }
    int T = 0;
    FOR(i,1,n+1) {
        int l; cin >> l;
        F0R(j,l) {
            int t; cin >> t;
            team[i].pb(t);
            T = max(T,t);
        }
    }
    while (1) {
        FOR(i,1,T+1) side[i] = rand()%2+1;
        FOR(i,1,n+1) cur[i] = team[i][rand()%sz(team[i])];
        int res = 0;
        for (auto a: hate) if (side[cur[a.f]] != side[cur[a.s]]) res ++;
        if (2*res >= e) {
            FOR(i,1,n+1) cout << cur[i] << " ";
            cout << "\n";
            FOR(i,1,T+1) cout << side[i] << " ";
            exit(0);
        }
    }
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/