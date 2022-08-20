#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef pair<ll,ll> pl;
typedef pair<double,double> pd;

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
const int MX = 5001;

int n,m;
bool done[100][100][26][2], win[100][100][26][2];
vector<pi> adj[100];

bool get(int a, int b, int c, int d) {
    if (done[a][b][c][d]) return win[a][b][c][d];
    done[a][b][c][d] = 1;
    if (d == 0) {
        for (auto x: adj[a]) if (x.s >= c && !get(x.f,b,x.s,d^1)) win[a][b][c][d] = 1;
    } else {
        for (auto x: adj[b]) if (x.s >= c && !get(a,x.f,x.s,d^1)) win[a][b][c][d] = 1;
    }
    return win[a][b][c][d];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    F0R(i,m) {
        int v,u; char c; cin >> v >> u >> c;
        v --, u --;
        adj[v].pb({u,c-'a'});
    }
    F0R(i,n) {
        F0R(j,n) {
            if (get(i,j,0,0)) cout << 'A';
            else cout << 'B';
        }
        cout << "\n";
    }
}

// read the question correctly (is y a vowel?)
// look out for special cases (n=1?) and overflow (ll vs int?)