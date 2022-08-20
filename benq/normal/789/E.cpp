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

int n,k, dist[2001], ok[1001];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k;
	F0R(i,k) {
	    int x; cin >> x;
	    ok[x] = 1;
	}
	F0R(i,2001) dist[i] = MOD;
	queue<int> todo;
	F0R(i,1001) if (ok[i]) {
	    dist[1000+i-n] = 1;
	    todo.push(1000+i-n);
	    // cout << "HI " << 1000+i-n << "\n";
	}
	while (todo.size()) {
	    int x = todo.front(); todo.pop();
	    F0R(i,1001) if (ok[i] && 0 <= x+i-n && x+i-n <= 2000 && dist[x+i-n] == MOD) {
	        dist[x+i-n] = dist[x]+1;
	        todo.push(x+i-n);
	    }
	}
	if (dist[1000] != MOD) cout << dist[1000];
	else cout << -1;
}

// read!
// ll vs. int!