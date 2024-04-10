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
const double PI = 4*atan(1);
const ll INF = 1e18;
const int MX = 100001;

int n,k,m,cost[100000],mn[100000];
ll ans = 0;
string v[100000];
map<string,int> M;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k >> m;
    F0R(i,n) cin >> v[i];
    F0R(i,n) cin >> cost[i];
    F0R(i,k) {
        int x; cin >> x;
        mn[i] = MOD;
        F0R(j,x) {
            int ind; cin >> ind; ind --;
            M[v[ind]] = i;
            mn[i] = min(mn[i],cost[ind]);
        }
    }
    F0R(i,m) {
        string z; cin >> z;
        ans += mn[M[z]];
    }
    cout << ans;
}

// read the question correctly (is y a vowel?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)