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

int n,k,a[400000],ans=0;
int nex[400000], lst[400001];
set<int> cur;
set<pii> tmp;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k;
	F0R(i,n) nex[i] = MOD;
    FOR(i,1,n+1) lst[i] = -1;
	F0R(i,n) {
	    cin >> a[i];
	    if (lst[a[i]] != -1) nex[lst[a[i]]] = i;
	    lst[a[i]] = i;
	}
	F0R(i,n) {
	    if (cur.find(a[i]) == cur.end()) {
    	    if (cur.size() == k) {
        	    pii x = *tmp.rbegin();
        	    cur.erase(x.s); tmp.erase(x);
    	    }
    	    ans++;
    	}
    	cur.insert(a[i]), tmp.erase({i,a[i]});
    	tmp.insert({nex[i],a[i]});
	}
	cout << ans;
}

// read!
// ll vs. int!