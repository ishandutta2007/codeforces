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

int n, m;
int dist[1000001], par[1000001];
vi nums[1000001];
vector<ll> sums[1000001];

void dfs(int x) {
    dist[x] += dist[x/2];
    nums[x].pb(dist[x]);
    if (2*x > n) {
        
    } else if (2*x+1 > n) {
        dfs(2*x);
        for (int i: nums[2*x]) nums[x].pb(i);
    } else {
        dfs(2*x);
        dfs(2*x+1);
        int i1 = 0, i2 = 0;
        while (i1 < nums[2*x].size() && i2 < nums[2*x+1].size()) {
            if (nums[2*x][i1] < nums[2*x+1][i2]) nums[x].pb(nums[2*x][i1++]);
            else nums[x].pb(nums[2*x+1][i2++]);
        }
        while (i1 < nums[2*x].size()) nums[x].pb(nums[2*x][i1++]);
        while (i2 < nums[2*x+1].size()) nums[x].pb(nums[2*x+1][i2++]);
    }
    F0R(i,nums[x].size()) {
        sums[x].pb(nums[x][i]);
        if (i) sums[x][i] += sums[x][i-1];
    }
}

ll query(int x, int dis) {
    int d = dist[x]+dis; 
    int lo = 0, hi = nums[x].size(); // first one which is greater
    while (lo < hi) {
        int mid = (lo+hi)/2;
        if (nums[x][mid] <= d) lo = mid+1;
        else hi = mid;
    }
    
    // sum of all which are less than dis
    // dis*(# less than dis)
    if (lo == 0) return 0;
    return (ll)d*lo-sums[x][lo-1];
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	FOR(i,2,n+1) {
	    cin >> dist[i];
	    par[i] = dist[i];
	}
	dfs(1);
	F0R(i,m) {
	    int A,H; cin >> A >> H;
	    ll ans = 0;
	    ans += query(A,H);
	    while (A > 1) {
	        H -= par[A];
	        if (H >= 0) ans += H;
	        if ((A^1) <= n) ans += query(A^1,H-par[A^1]);
	        A /= 2;
	    }
	    cout << ans << "\n";
	}
}

// read!
// ll vs. int!