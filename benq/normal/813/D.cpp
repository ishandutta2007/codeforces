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

int dp[5001][5001], lst[100002];
int n, a[5001], tmp[7], ans;

void fill(int ind) {
    memset(tmp,0,sizeof tmp);
    F0R(i,ind) {
        dp[i][ind] = dp[ind][i];
        if (i) {
            lst[a[i]] = max(lst[a[i]], dp[i][ind]);
            tmp[a[i]%7] = max(tmp[a[i]%7], dp[i][ind]);
        }
    }
    FOR(i,ind+1,n+1) {
        dp[i][ind] = 1+dp[ind][0];
        dp[i][ind] = max(dp[i][ind],lst[a[i]-1]+1);
        dp[i][ind] = max(dp[i][ind],lst[a[i]+1]+1);
        dp[i][ind] = max(dp[i][ind],tmp[a[i]%7]+1);
        
        lst[a[i]] = tmp[a[i]%7] = dp[i][ind];
        ans = max(ans,dp[i][ind]);
    }
    FOR(i,1,n+1) lst[a[i]] = 0;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	FOR(i,1,n+1) cin >> a[i];
	F0R(i,n+1) fill(i);
	cout << ans;
}

// read!
// ll vs. int!