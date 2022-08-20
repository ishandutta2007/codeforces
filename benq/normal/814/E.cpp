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

const int MOD = 1000000007;

int n, d[51];
ll fac[51], ipo2[51];
ll dp[51][51]; // begin index, #

ll get(int x, int y) {
    return fac[x+2*y]*ipo2[y] % MOD;
}

ll cur[101][51], cur1[101][51]; // # of open 1's, # of open 2's

void solve(int x, int y) {
    F0R(k,51) F0R(j,101-2*k) cur[j][k] = 0;
    cur[0][0] = dp[x][y];
    
    FOR(i,x,x+y) {
        F0R(k,51) F0R(j,101-2*k) cur1[j][k] = 0;
        if (d[i] == 2) {
            F0R(k,51) F0R(j,100-2*k) cur1[j+1][k] = (cur1[j+1][k]+cur[j][k]) % MOD; // take none, OK
            F0R(k,51) FOR(j,1,101-2*k) cur1[j-1][k] = (cur1[j-1][k]+j*cur[j][k]) % MOD; // take one from one, OK
            FOR(k,1,51) F0R(j,100-2*k) cur1[j+1][k-1] = (cur1[j+1][k-1]+k*cur[j][k]) % MOD; // take one from two, OK
        } else {
            F0R(k,50) F0R(j,101-2*k) cur1[j][k+1] = (cur1[j][k+1]+cur[j][k]) % MOD; // take none, OK
            F0R(k,51) F0R(j,101-2*k) cur1[j][k] = (cur1[j][k]+j*cur[j][k]) % MOD; // take one from one, OK
            FOR(k,1,51) F0R(j,99-2*k) cur1[j+2][k-1] = (cur1[j+2][k-1]+k*cur[j][k]) % MOD; // take one from two, OK
            FOR(k,2,51) F0R(j,99-2*k) cur1[j+2][k-2] = (cur1[j+2][k-2]+k*(k-1)/2*cur[j][k]) % MOD; // take two from two, OK
            F0R(k,51) FOR(j,2,101-2*k) cur1[j-2][k] = (cur1[j-2][k]+j*(j-1)/2*cur[j][k]) % MOD; // take two from one, OK
            FOR(k,1,51) F0R(j,101-2*k) cur1[j][k-1] = (cur1[j][k-1]+j*k*cur[j][k]) % MOD; // take one from one and one from two, OK
        }
        F0R(k,51) F0R(j,101-2*k) cur[j][k] = cur1[j][k];
    }
    F0R(j,51) F0R(i,101-2*j) if (i+2*j <= 50) {
        dp[x+y][i+2*j] = (dp[x+y][i+2*j]+get(i,j)*cur[i][j]) % MOD;
    }
}

void init() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	F0R(i,n) cin >> d[i];
	fac[0] = ipo2[0] = 1;
	FOR(i,1,51) {
	    fac[i] = (i*fac[i-1]) % MOD;
	    ipo2[i] = (MOD+1)/2*ipo2[i-1] % MOD;
	}
}

int main() {
    init();
	dp[1][d[0]] = 1;
	F0R(i,n) FOR(j,1,n+1-i) solve(i,j);
	cout << dp[n][0];
}

// read!
// ll vs. int!