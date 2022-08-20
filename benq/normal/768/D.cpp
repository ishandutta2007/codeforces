#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long double ld;
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

int k,q,ans[1001];
ld prob[10001][1001];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> k >> q;
	prob[0][0] = 1;
	F0R(i,10000) F0R(j,k+1) {
	    prob[i+1][j] += prob[i][j]*j/k;
	    if (j != k) prob[i+1][j+1] += prob[i][j]*(k-j)/k;
	}
	FOR(i,1,1001) {
	    ans[i] = ans[i-1];
	    while (prob[ans[i]][k] < (ld)i/2000-numeric_limits<double>::epsilon()) ans[i] ++;
	}
	F0R(i,q) {
	    int p; cin >> p;
	    cout << ans[p] << "\n";
	}
}

// read!
// ll vs. int!