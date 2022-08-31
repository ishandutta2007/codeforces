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

int n,k,s;
array<array<int,75*75+1>,151> x, y; // current #, swaps

void ad(int ind, int q) {
	F0R(i,150) F0R(j,75*75+1-(ind-i)) {
		x[i+1][j+ind-i] = min(x[i+1][j+ind-i],y[i][j]+q);
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k >> s;
	F0R(i,x.size()) F0R(j,x[0].size()) x[i][j] = MOD;
	x[0][0] = 0;
	F0R(i,n) {
		y = x;
		int q; cin >> q;
		ad(i,q);
	}
	int ans = MOD;
	F0R(i,min(s,75*75)+1) ans = min(ans,x[k][i]);
	cout << ans;
}

// read!
// ll vs. int!