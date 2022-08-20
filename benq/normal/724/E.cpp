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
const ll INF = 1e18;

ll n, p[10000], s[10000];
ll c, cut[10001], pre[10001];
ll ans = 0;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> c;
	F0R(i,n) cin >> p[i];
	F0R(i,n) cin >> s[i];
	FOR(i,1,n+1) {
	    F0R(j,i+1) {
    	    cut[j] = INF;
    	    if (j != i) cut[j] = pre[j]+p[i-1]+j*c;
    	    if (j) cut[j] = min(cut[j], pre[j-1]+s[i-1]);
	    }
	    F0R(j,i+1) pre[j] = cut[j];
	}
	ll ans = INF;
	F0R(i,n+1) ans = min(ans,cut[i]);
	cout << ans;
}

// read!
// ll vs. int!