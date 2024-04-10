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

ll n,p,q,r;
ll mn[100000],mx[100000], val[100000], ans[100000], fin=-5e18;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> p >> q >> r;
	F0R(i,n) {
	    cin >> val[i];
	    ans[i] = q*val[i];
	}
	F0R(i,n) {
	    mx[i] = mn[i] = val[i];
	    if (i) mx[i] = max(mx[i],mx[i-1]), mn[i] = min(mn[i],mn[i-1]);
	    ans[i] += max(p*mn[i],p*mx[i]);
	}
	F0Rd(i,n) {
	    mx[i] = mn[i] = val[i];
	    if (i != n-1) mx[i] = max(mx[i],mx[i+1]), mn[i] = min(mn[i],mn[i+1]);
	    ans[i] += max(r*mn[i],r*mx[i]);
	}
	F0R(i,n) fin = max(fin,ans[i]);
	cout << fin;
}

// read!
// ll vs. int!