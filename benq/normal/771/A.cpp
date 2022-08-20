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

int n,m, sz[150001], par[150001]; 

int getpar(int x) {
    if (par[par[x]] != par[x]) par[x] = getpar(par[x]);
    return par[x];
}

void unite(int a, int b) {
    a = getpar(a), b = getpar(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a,b);
    par[b] = a; sz[a] += sz[b];
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	FOR(i,1,n+1) sz[i] = 1, par[i] = i;
	F0R(i,m) {
	    int a,b; cin >> a >> b;
	    unite(a,b);
	}
	ll ans = 0;
	FOR(i,1,n+1) if (getpar(i) == i) ans += (ll)sz[i]*(sz[i]-1)/2;
	if (ans == m) cout << "YES";
	else cout << "NO";
}

// read!
// ll vs. int!