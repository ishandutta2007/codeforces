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

int n, pre[101], aft[101];
vi cur;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	FOR(i,1,n+1) cin >> pre[i] >> aft[i];
	FOR(i,1,n+1) if (pre[i] == 0) {
	    int i1 = i;
	    while (i1) {
	        cur.pb(i1);
	        i1 = aft[i1];
	    } 
	}
	F0R(i,cur.size()) {
	    if (i) pre[cur[i]] = cur[i-1];
	    if (i < cur.size()-1) aft[cur[i]] = cur[i+1];
	}
	FOR(i,1,n+1) cout << pre[i] << " " << aft[i] << "\n";
}

// read!
// ll vs. int!