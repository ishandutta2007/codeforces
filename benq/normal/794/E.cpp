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

int n, a[300000];
int lsto, lste;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n; F0R(i,n) cin >> a[i];
	F0R(i,n) {
	    if (i == n-1) {
	        int mx = 0; F0R(i,n) mx = max(mx,a[i]);
	        cout << mx << " ";
	    } else if ((n-i) % 2 == 0) { // max
	        lste = max(lste,max(max(a[(n-i)/2-1],a[(n-i)/2]),max(a[(n+i)/2-1],a[(n+i)/2])));
	        cout << lste << " ";
	    } else { // max of mins?
	        // 9,0: 3,4,5
	        // 9,2: 2,3,4 and 4,5,6
	        lsto = max(lsto,max(max(min(a[(n-i)/2-1],a[(n-i)/2]),min(a[(n-i)/2],a[(n-i)/2+1])),max(min(a[(n+i)/2-1],a[(n+i)/2]),min(a[(n+i)/2],a[(n+i)/2+1]))));
	        cout << lsto << " ";
	    }
	}
}

// read!
// ll vs. int!