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

int n;
string g;

bool test(int mid) {
    vi pos; F0R(i,n) if (g[i] == '*') pos.pb(i);
    F0Rd(i,n) if (g[i] == 'P') {
        int ri = max(i,pos[pos.size()-1]);
        if (ri-i > mid) return 0;
        int le = min(i,ri-(mid-(ri-i)));
        le = min(le,i-(mid-(ri-i))/2);
        while (pos.size() && pos[pos.size()-1] >= le) pos.erase(pos.end()-1);
        if (pos.size() == 0) return 1;
    }
    return 0;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> g;
	int lo = 0, hi = 200000;
	while (lo < hi) {
	    int mid = (lo+hi)/2;
	    if (test(mid)) hi = mid;
	    else lo = mid+1;
	}
	cout << lo;
}

// read!
// ll vs. int!