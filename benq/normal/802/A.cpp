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

int n,k,a[80],ans=0;
set<int> cur;

int calc(int x, int ind) {
    FOR(i,ind,n) if (a[i] == x) return i;
    return MOD;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k;
	F0R(i,n) cin >> a[i];
	F0R(i,n) if (cur.find(a[i]) == cur.end()) {
	    if (cur.size() == k) {
    	    pii bes = {-1,-1};
    	    for (int x: cur) bes = max(bes,{calc(x,i),x});
    	    cur.erase(bes.s);
	    }
	    ans++;
	    cur.insert(a[i]);
	}
	cout << ans;
}

// read!
// ll vs. int!