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

int n,k,a[100000],mx=-MOD, mn=MOD;
int ans = -MOD;
int mn1[100000], mn2[100000];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k; 
	F0R(i,n) {
	    cin >> a[i];
	    mx = max(mx,a[i]);
	    mn = min(mn,a[i]);
	}
	if (k >= 3) {
	    cout << mx;
	    return 0;
	}
	if (k == 1) {
	    cout << mn;
	    return 0;
	}
	F0R(i,n) {
	    mn1[i] = a[i];
	    if (i) mn1[i] = min(mn1[i],mn1[i-1]);
	}
	F0Rd(i,n) {
	    mn2[i] = a[i];
	    if (i < n-1) mn2[i] = min(mn2[i],mn2[i+1]);
	}
	F0R(i,n-1) ans = max(ans,max(mn1[i],mn2[i+1]));
	cout << ans;
}

// read!
// ll vs. int!