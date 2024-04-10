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
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const int MX = 200001;

int n, dist[MX], pre[MX];
vi adj[MX], dia;
vector<vi> fin;
set<int> DIA;
ll ans = 0;

void dfs(int cur) {
    for (int i: adj[cur]) if (i != pre[cur]) {
        pre[i] = cur; 
        dist[i] = dist[cur]+1;
        dfs(i);
    }
}

void DFS(int cur) {
    memset(dist,0,sizeof dist);
    pre[cur] = 0;
    dfs(cur);
}

void treeDiameter() {
    DFS(1);
    int bes = 0; FOR(i,1,n+1) if (dist[i] > dist[bes]) bes = i;
    DFS(bes); 
    int BES = 0;
    FOR(i,1,n+1) if (dist[i] > dist[BES]) BES = i;
    while (BES != bes) {
        dia.pb(BES);
        BES = pre[BES];
    }
    dia.pb(bes);
}

void init() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n; 
	F0R(i,n-1) {
	    int a,b; cin >> a >> b;
	    adj[a].pb(b); adj[b].pb(a);
	}
}

void dfsfin(int cur, int pre, int lef, int ad) {
    if (pre) {
        fin.pb({lef,cur,cur});
        ans += ad;
    }
    for (int i: adj[cur]) if (!DIA.count(i) && i != pre) dfsfin(i,cur,lef,ad+1);
}

void solve() {
    for (int i: dia) DIA.insert(i);
    FOR(i,1,sz(dia)) {
        fin.pb({dia[0],dia[i],dia[i]});
        ans += i;
    }
    FOR(i,1,sz(dia)-1) {
        if (i >= sz(dia)-1-i) dfsfin(dia[i],0,dia.front(),i);
        else dfsfin(dia[i],0,dia.back(),sz(dia)-1-i);
    }
}

int main() {
	init();
	treeDiameter();
	solve();
	
	cout << ans << "\n";
	reverse(all(fin));
	for (auto a: fin) cout << a[0] << " " << a[1] << " " << a[2] << "\n";
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!