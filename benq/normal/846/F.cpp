#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
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
const ll INF = 1e18;

ll n, ans = 0;
vector<ll> pos[1000001];

void test(int ind) {
    ll tot = n*n;  
    F0R(i,pos[ind].size()-1) tot -= (pos[ind][i+1]-pos[ind][i]-1)*(pos[ind][i+1]-pos[ind][i]-1);
    ans += tot;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	FOR(i,1,1000001) pos[i].pb(0);
	FOR(i,1,n+1) {
	    int x; cin >> x;
	    pos[x].pb(i);
	}
	FOR(i,1,1000001) pos[i].pb(n+1);
	FOR(i,1,1000001) test(i);
	cout << fixed << setprecision(9) << (double)ans/n/n;
}

// read!
// ll vs. int!