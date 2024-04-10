/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

int n;
ll fac[501], ifac[501];
ll dp[301][301];
map<int,int> oc;
vi z;

int red(int a) {
    for (int i = 2; i*i <= a; ++i) {
        while (a % (i*i) == 0) a /= (i*i);
    }
    return a;
}

ll inv(ll b) {
    ll po = MOD-2, ans = 1;
    while (po) {
        if (po&1) ans = (ans*b) % MOD;
        b = b*b % MOD;
        po /= 2;
    }
    return ans;
}

ll combo(int a, int b) {
    if (a<b) return 0;
    ll ans = fac[a];
    ans = (ans*ifac[b]) % MOD;
    ans = (ans*ifac[a-b]) % MOD;
    return ans;
}

void gen(int ind, int r) {
    if (ind == (int)z.size()-1) {
        dp[ind][r] = combo(r+1,z[ind])*fac[r] % MOD;
        return;
    }
    FOR(j,1,z[ind]+1) {
        ll tmp = ifac[j]*combo(z[ind]-1,j-1) % MOD;
        if (r+j <= 300) tmp = tmp*dp[ind+1][r+j] % MOD;
        if ((z[ind]-j) % 2 == 0) dp[ind][r] = (dp[ind][r]+tmp) % MOD;
        else dp[ind][r] = (dp[ind][r]+MOD-tmp) % MOD;
    }
}

void init() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	fac[0] = ifac[0] = 1;
	FOR(i,1,501) {
	    fac[i] = i*fac[i-1] % MOD;
	    ifac[i] = inv(fac[i]);
	}
	F0R(i,n) {
	    int a; cin >> a;
	    oc[red(a)] ++; 
	}
	for (auto a: oc) z.pb(a.s);
}

int main() {
    init();
	F0Rd(i,z.size()) F0R(j,301) gen(i,j);
	for (int i: z) dp[0][0] = (dp[0][0]*fac[i]) % MOD;
	while (dp[0][0] < 0) dp[0][0] += MOD;
	cout << dp[0][0];
}

// read!
// ll vs. int!