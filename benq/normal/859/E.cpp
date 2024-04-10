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

int N, par[200001], sz[200001], des[200001], visit[200001];
vi adj[200001];
ll ans = 1;

int getpar(int x) {
    if (par[par[x]] != par[x]) par[x] = getpar(par[x]);
    return par[x];
}

void unite(int x, int y) {
    if (rand()&1) swap(x,y);
    x = getpar(x), y = getpar(y);
    if (x != y) {
        par[y] = x;
        sz[x] += sz[y];
    }
    sz[x] ++;
}

vi cur;

void dfs(int x) {
    visit[x] = 1; cur.pb(x);
    for (int i: adj[x]) if (!visit[i]) dfs(i);
}

void solve(int ind) {
    cur.clear(); dfs(ind);
    int S = cur.size();
    if (S == sz[ind]) {
        for (int i: cur) if (des[i] == i) return;
        ans = (ans*2) % MOD;
    } else ans = (ans*S) % MOD;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> N;
	FOR(i,1,2*N+1) par[i] = i;
	F0R(i,N) {
	    int x,y; cin >> x >> y; des[x] = y;
	    adj[x].pb(y), adj[y].pb(x);
	    unite(x,y);
	}
	FOR(i,1,2*N+1) if (getpar(i) == i && sz[i] > 0) solve(i);
	cout << ans;
}

// read!
// ll vs. int!