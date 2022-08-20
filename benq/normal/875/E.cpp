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

int n,s1,s2, x[1<<17];

set<int> L;

bool test(int mid) {
    L.clear();
    L.insert(x[0]);
    FOR(i,2,n+2) {
        if (L.size() == 0) return 0;
        L.insert(x[i-1]);
        while (L.size() && *L.begin() < x[i]-mid) L.erase(L.begin());
        while (L.size() && *L.rbegin() > x[i]+mid) L.erase(prev(L.end()));
    }
    return L.size() > 0;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> x[0] >> x[1];
	FOR(i,2,n+2) cin >> x[i];
	int lo = abs(x[0]-x[1]), hi = 1e9;
	while (lo < hi) {
	    int mid = (lo+hi)/2;
	    if (test(mid)) hi = mid;
	    else lo = mid+1;
	}
	cout << lo;
}

// read!
// ll vs. int!