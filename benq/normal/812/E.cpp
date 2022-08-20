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

int n, a[100001], dist[100001], leaf;
vi child[100001], mat;
map<int,int> tmp;

void dfs(int p, int x) {
    dist[x] = dist[p]+1;
    for (int i: child[x]) dfs(x,i);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	FOR(i,1,n+1) cin >> a[i];
	FOR(i,2,n+1) {
	    int p; cin >> p;
	    child[p].pb(i);
	}
	dfs(0,1);
	FOR(i,1,n+1) if (child[i].size() == 0) leaf = i;
	FOR(i,1,n+1) if ((dist[i]&1) == (dist[leaf]&1)) mat.pb(a[i]);
	else tmp[a[i]] ++;
	
	int xo = 0;
	for (int i: mat) xo ^= i;
	
	ll ans = 0;
	for (int i: mat) {
	    int t = xo^i;
	    if (tmp.count(t)) ans += tmp[t];
	}
	
	if (xo == 0) {
	    ans += (ll)mat.size()*(mat.size()-1)/2;
	    ans += (ll)(n-mat.size())*(n-mat.size()-1)/2;
	}
	cout << ans;
}

// read!
// ll vs. int!