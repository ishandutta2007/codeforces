#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> pii;
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
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const int MX = 200001;

int n,m;
ll a[MX];
vector<pii> adj[MX];
priority_queue<pii,vector<pii>,greater<pii>> todo;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	F0R(i,m) {
	    ll v,u,w; cin >> v >> u >> w;
	    adj[v].pb({u,w}), adj[u].pb({v,w});
	}
	FOR(i,1,n+1) {
	    cin >> a[i];
	    todo.push({a[i],i});
	}
	while (sz(todo)) {
	    auto x = todo.top(); todo.pop();
	    if (x.f != a[x.s]) continue;
	    for (auto y: adj[x.s]) if (x.f+2*y.s < a[y.f]) {
	        todo.push({a[y.f] = x.f+2*y.s,y.f});
	    }
	}
	FOR(i,1,n+1) cout << a[i] << " ";
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!