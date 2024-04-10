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
const int MX = 100001;

int n,m,sk, tmp[500][501], dp[501][501];
vi v[500];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> sk;
    F0R(i,n) {
        string s; cin >> s;
        F0R(j,sz(s)) if (s[j] == '1') v[i].pb(j);
        F0R(j,501) tmp[i][j] = MOD;
        F0R(j,sz(v[i])) F0R(k,sz(v[i])-j) {
            tmp[i][sz(v[i])-k-1] = min(tmp[i][sz(v[i])-k-1],v[i][j+k]-v[i][j]+1);
        }
        tmp[i][sz(v[i])] = 0;
    }
    
    F0R(i,501) F0R(j,501) dp[i][j] = MOD;
    dp[0][0] = 0;
    F0R(i,n) F0R(j,sk+1)
        for (int k = 0; j+k <= sk; ++k) 
            dp[i+1][j+k] = min(dp[i+1][j+k],dp[i][j]+tmp[i][k]);
    
    int ans = MOD;
    F0R(i,sk+1) ans = min(ans,dp[n][i]);
    cout << ans;
}

// read the question correctly (is y a vowel?)
// look out for special cases (n=1?) and overflow (ll vs int?)