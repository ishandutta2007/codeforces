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

int n, a[100005];
ll ans = -1e18;

void genodd() {
    ll mx = -1e18;
    for (int i = n-2; i >= 0; i -= 2) {
        mx += a[i]-a[i+1];
        mx = max(mx,(ll)a[i]);
        ans = max(ans,mx);
    }
}

void geneve() {
    ll mx = -1e18;
    for (int i = n-3; i >= 0; i -= 2) {
        mx += a[i]-a[i+1];
        mx = max(mx,(ll)a[i]);
        ans = max(ans,mx);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n; F0R(i,n) cin >> a[i];
	F0R(i,n-1) a[i] = abs(a[i]-a[i+1]);
	genodd();
	geneve();
	cout << ans;
}

// read!
// ll vs. int!