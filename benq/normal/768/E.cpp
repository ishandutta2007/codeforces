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

int n, g[61];
map<ll,int> val[61];

int solve(int x, ll z) {
    if (val[x].count(z)) return val[x][z];
    ll tmp = 0;
    FOR(i,1,x+1) if (!(z&(1LL<<i))) {
        ll z1 = z^(1LL<<i);
        z1 &= ((1LL<<(x+1-i))-2);
        tmp |= (1LL<<solve(x-i,z1));
    }
    for (int i = 0;;++i) if (!(tmp&(1LL<<i))) return val[x][z] = i;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	val[0][0] = 0;
	FOR(i,1,61) {
	    g[i] = solve(i,0);
	    //cout << i << " " << g[i] << "\n";
	}
	cin >> n;
	int ans = 0;
	F0R(i,n) {
	    int x; cin >> x;
	    ans ^= g[x];
	}
	if (ans == 0) cout << "YES";
	else cout << "NO";
}

// read!
// ll vs. int!