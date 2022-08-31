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

int n,m,k,a[100][100],ans,need;
pii mx[100];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m >> k;
	F0R(i,n) F0R(j,m) cin >> a[i][j];
	F0R(j,m) {
	    mx[j] = {-1,0};
	    F0R(i,n) if (a[i][j] == 1) {
	        int sum = 0;
	        FOR(K,i,min(i+k,n)) sum += a[K][j];
	        mx[j] = max(mx[j],mp(sum,-i));
	    }
	    if (mx[j].f == -1) continue;
	    ans += mx[j].f;
	    F0R(i,-mx[j].s) need += a[i][j];
	}
	cout << ans << " " << need;
}

// read!
// ll vs. int!