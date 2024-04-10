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

int n, vert = 0, ed = 0, visit[200000];
ll ans = 1, po2[200005];
pii p[100000];
vi adj[200000];
map<int,int> m;

void init() {
    po2[0] = 1;
    FOR(i,1,200005) po2[i] = 2*po2[i-1] % MOD;
    
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	F0R(i,n) cin >> p[i].f >> p[i].s;
	
	F0R(i,n) m[p[i].f] = 0;
	int co = 0;
	for (auto& a: m) a.s = co++;
	F0R(i,n) p[i].f = m[p[i].f];
	
	m.clear();
	F0R(i,n) m[p[i].s] = 0;
	co = 0;
	for (auto& a: m) a.s = co++;
	F0R(i,n) {
	    p[i].s = m[p[i].s]+100000;
	    adj[p[i].f].pb(p[i].s);
	    adj[p[i].s].pb(p[i].f);
	}
}

void dfs(int x) {
    if (visit[x]) return;
    visit[x] = 1; vert ++; ed += adj[x].size();
    for (int i: adj[x]) dfs(i);
}

int main() {
    init();
    F0R(i,200000) if (!visit[i]) {
        vert = 0, ed = 0;
        dfs(i); ed /= 2;
        if (vert <= ed) ans = ans*po2[vert] % MOD;
        else ans = ans*(po2[vert]-1) % MOD;
    }
    cout << ans;
}

// read!
// ll vs. int!