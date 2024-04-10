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

namespace ModOp {
    ll po (ll b, ll p) { return !p?1:po(b*b%MOD,p/2)*(p&1?b:1)%MOD; }
    ll inv (ll b) { return po(b,MOD-2); }
    
    int ad(int a, int b) { return (a+b)%MOD; }
    int sub(int a, int b) { return (a-b+MOD)%MOD; }
    int mul(int a, int b) { return (ll)a*b%MOD; }
    
    int AD(int& a, int b) { return a = ad(a,b); }
    int SUB(int& a, int b) { return a = sub(a,b); }
    int MUL(int& a, int b) { return a = mul(a,b); }
}

using namespace ModOp;

string X;
int ans = 0;
array<array<int,2>,701> dp, DP;

void tri(int x) { // >= x
    F0R(j,701) F0R(k,2) dp[j][k] = 0;
    dp[0][0] = 1;
    F0R(i,sz(X)) {
        int v = X[i]-'0';
        swap(dp,DP); F0R(j,701) F0R(k,2) dp[j][k] = 0;
        F0R(j,701) {
            AD(dp[j+1][1],mul(10-x,DP[j][1])); 
            AD(dp[j][1],mul(x,DP[j][1]));
            F0R(k,v) AD(dp[j+(k >= x)][1],DP[j][0]);
            AD(dp[j+(v >= x)][0],DP[j][0]);
        }
    }
    int res = 0, po10 = 1;
    F0R(j,701) {
        AD(ans,mul(ad(dp[j][0],dp[j][1]),res));
        AD(res,po10); MUL(po10,10);
    }
}

int main() {
    cin >> X;
    FOR(i,1,10) tri(i);
    cout << ans;
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/