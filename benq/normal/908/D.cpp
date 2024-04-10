#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
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

int k,pa,pb;
ll dp[1001][1001]; // how many ab's, how many a's
ll ans = 0, z;

ll po(ll b, ll p) {
    return !p?1:po(b*b%MOD,p/2)*(p&1?b:1)%MOD;
}

ll inv(ll x) { return po(x,MOD-2); }

void finish(ll x, int ab) {
    // x*pa*z*(ab+a)
    // 
    ll z = (ab+pa*inv(pb))%MOD;
    z = z*x % MOD;
    ans = (ans+z) % MOD;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> k >> pa >> pb;
	z = inv(pa+pb);
	dp[0][1] = 1;
	if (k == 1) finish(1,1);
	
	F0R(i,k) F0R(j,k-i) {
	    ll quan = dp[i][j]*z%MOD;
	    if (i+j+1 >= k) finish(pa*quan%MOD,i+j+1); 
	    else dp[i][j+1] = (dp[i][j+1]+pa*quan)%MOD;
	   
	    if (i+j >= k) {
	        ll x = pb*quan % MOD; x = x*(i+j)%MOD;
	        ans = (ans+x) % MOD;
	    } else if (i+j+j >= k) finish(pb*quan%MOD,i+j+j);
	    else dp[i+j][j] = (dp[i+j][j]+pb*quan)%MOD;
	}
    cout << ans;
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!