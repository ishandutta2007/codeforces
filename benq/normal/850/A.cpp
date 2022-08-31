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
vector<vi> x;
vi ans;

int dot(vi& a, vi& b, vi& c) {
    int z = 0;
    F0R(i,5) z += (b[i]-a[i])*(c[i]-a[i]);
    return z;
}

bool good(int ind) {
    if (x.size() > 50) return 0;
    F0R(i,x.size()) FOR(j,i+1,x.size()) 
        if (i != ind && j != ind) 
            if (dot(x[ind],x[i],x[j]) > 0) return 0;
    return 1;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	F0R(i,n) {
	    int a,b,c,d,e; cin >> a >> b >> c >> d >> e;
	    x.pb({a,b,c,d,e});
	}
	F0R(i,x.size()) if (good(i)) ans.pb(i);
	cout << ans.size() << "\n";
	for (int i: ans) cout << i+1 << "\n";
}

// read!
// ll vs. int!