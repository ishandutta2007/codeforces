#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
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
const ll INF = 1e18;

int n, x[100001], k[100001];
ll a[100001], b[100001];
vi child[100001];

ll dfs(int pre, int no) {
    ll cur = 0;
    for (int i: child[no]) {
        ll tmp = dfs(no,i);
        if (tmp < 0) {
            if (tmp < -1e18/k[i]) {
                cout << "NO";
                exit(0);
            }
            cur += tmp*k[i];
            if (cur < -1e18) {
                cout << "NO";
                exit(0);
            }
        } else cur += tmp;
    }
    cur += b[no]-a[no];
    return cur;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	FOR(i,1,n+1) cin >> b[i];
	FOR(i,1,n+1) cin >> a[i];
	FOR(i,2,n+1) {
	    cin >> x[i] >> k[i];
	    child[x[i]].pb(i);
	}
	if (dfs(0,1) >= 0) cout << "YES";
	else cout << "NO";
}

// read!
// ll vs. int!