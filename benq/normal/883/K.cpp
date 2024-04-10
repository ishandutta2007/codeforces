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

int n, s[200000], g[200000];
pii posi[200000];
ll sum = 0;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	F0R(i,n) {
	    cin >> s[i] >> g[i];
	    posi[i] = {s[i],s[i]+g[i]};
	    
	    sum -= s[i];
	    if (i) {
	        posi[i].f = max(posi[i].f,posi[i-1].f-1);
	        posi[i].s = min(posi[i].s,posi[i-1].s+1);
	        if (posi[i].f > posi[i].s) {
	            cout << -1;
	            return 0;
	        }
	    }
	}
	vi ans;
	int cur = posi[n-1].s;
	F0Rd(i,n) {
	    ans.pb(cur); sum += cur;
	    if (i) cur = min(cur+1,posi[i-1].s);
	}
	cout << sum << "\n";
	F0Rd(i,ans.size()) cout << ans[i] << " ";
}

// read!
// ll vs. int!