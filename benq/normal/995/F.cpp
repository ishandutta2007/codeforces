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

int N,D,p[3001],dp[3001][3001];
vi child[3001];

int mul(int a, int b) { return (ll)a*b%MOD; }
int ad(int a, int b) { return (a+b)%MOD; }
int sub(int a, int b) { return (a-b+MOD)%MOD; }

ll po(ll b, ll p) { return !p?1:mul(po(b*b%MOD,p/2),p&1?b:1); }
ll inv (ll b) { return po(b,MOD-2); }

ll in[3001];

ll interpolate(int D) {
    ll z = 0;
    F0R(i,N+1) {
        ll ans = dp[1][i];
        F0R(j,N+1) if (j != i) {
            if (i > j) ans = mul(ans,in[i-j]);
            else ans = mul(ans,mul(MOD-1,in[j-i]));
            ans = mul(ans,sub(D,j));
        }
        z = ad(z,ans);
    }
    return z;
}

void genDP() {
    FORd(i,1,N+1) {
        FOR(j,1,N+1) {
            dp[i][j] = 1;
            for (int k: child[i]) dp[i][j] = mul(dp[i][j],dp[k][j]);
            if (j) dp[i][j] = ad(dp[i][j],dp[i][j-1]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> D;
    FOR(i,2,N+1) {
        cin >> p[i];
        child[p[i]].pb(i);
    }
    FOR(i,1,3001) in[i] = inv(i);
    genDP();
    // cout << dp[1][2] << "\n";
    cout << interpolate(D);
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS