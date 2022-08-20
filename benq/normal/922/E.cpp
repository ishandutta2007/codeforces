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
const ll INF = 1e18;

ll n,W,B,X;
ll dp[10001], c[1000], cost[1000];

void tmp(ll num, ll co) {
    F0Rd(i,10001-num) {
        ll res = dp[i]-co*num;
        if (res >= 0) dp[i+num] = max(dp[i+num],res);
    }    
} 

void ad(int ind) {
    int num = 1;
    while (num <= c[ind]) {
        c[ind] -= num;
        tmp(num,cost[ind]);
        num *= 2;
    }
    if (c[ind]) tmp(c[ind],cost[ind]);
    F0R(i,10001) if (dp[i] >= 0) dp[i] = min(dp[0]+B*i,dp[i]+X);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> dp[0] >> B >> X;
	FOR(i,1,10001) dp[i] = -INF;
	F0R(i,n) cin >> c[i];
	F0R(i,n) cin >> cost[i];
	F0R(i,n) ad(i);
	F0Rd(i,10001) if (dp[i] >= 0) {
	    cout << i;
	    return 0;
	}
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!