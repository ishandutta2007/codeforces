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

int n,m;

vi adj[1000001], radj[1000001], todo;
vector<pii> wei[1000001], edge[1000001];
int comp[1000001];
ll res[1000001], ans[1000001];
bool visit[1000001], done[1000001];

void dfs(int v) {
	visit[v] = 1; 
	for (int w: adj[v]) if (!visit[w]) dfs(w);
	todo.pb(v);
}

void dfs2(int v, int val) {
	comp[v] = val;
	for (int w: radj[v]) if (!comp[w]) dfs2(w,val);
}

void scc() {
	FOR(i,1,n+1) if (!visit[i]) dfs(i);
	reverse(todo.begin(),todo.end());
	for (int i: todo) if (!comp[i]) dfs2(i,i);
}

set<pii> tmp;

ll get(ll ed) {
    ll k = prev(tmp.ub({ed,MOD}))->s;
    return (k+1)*ed-(k+2)*(k+1)*k/6;
}

ll solve(int x) {
    if (done[x]) return ans[x];
    for (auto a: edge[x]) ans[x] = max(ans[x],solve(a.f)+a.s);
    ans[x] += res[x];
    done[x] = 1;
    return ans[x];
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	FOR(i,1,20001) tmp.insert({i*(i+1)/2,i});
	cin >> n >> m;
	F0R(i,m) {
	    int x,y,w; cin >> x >> y >> w;
	    adj[x].pb(y);
	    wei[x].pb({y,w});
	    radj[y].pb(x);
	}
    scc();
	FOR(i,1,n+1) for (auto j: wei[i]) if (comp[i] == comp[j.f]) {
	    res[comp[i]] += get(j.s);
	} else {
	    edge[comp[i]].pb({comp[j.f],j.s});
	}
	int S; cin >> S;
	cout << solve(comp[S]);
}

// read!
// ll vs. int!