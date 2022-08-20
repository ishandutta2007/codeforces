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

int n, y[1000];

bool test1() { // every other point is collinear
    FOR(i,2,n) if (y[i]-y[i-1] != y[2]-y[1]) return 0;
    return 1;
}

bool test2() { // point 0 is collinear with another
    FOR(i,1,n) {
        pair<ll,ll> x = {i,y[i]-y[0]};
        x.f *= -1; swap(x.f,x.s);
        set<ll> z;
        F0R(j,n) z.insert(x.f*j+x.s*y[j]);
        if (z.size() <= 2) return 1;
    }
    return 0;
}

bool col() {
    FOR(i,1,n) if (y[i]-y[i-1] != y[1]-y[0]) return 0;
    return 1;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	F0R(i,n) cin >> y[i];
	if (col()) {
	    cout << "No";
	    return 0;
	}
	if (test1() || test2()) cout << "Yes";
	else cout << "No";
}

// read!
// ll vs. int!