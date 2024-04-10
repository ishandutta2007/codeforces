#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

const int MAXN = 500001, MAXK = 20;

int parK[MAXK][MAXN],depth[MAXN],p[MAXN];
int n,ceo;
ll ans[MAXN], csum=0;
vi child[MAXN];
vector<pii> z;

void dfs(int u, int prev){
    parK[0][u] = prev;
    depth[u] = depth[prev]+1;
    for (int v: child[u]) dfs(v, u);
}

int lca(int u, int v, int t = 0){
    if (u == 0 || v == 0) return 0;
    if (depth[u] < depth[v]) swap(u,v);
    
    F0Rd(k,MAXK) if (depth[u] >= depth[v]+(1<<k)) u = parK[k][u];
    F0Rd(k,MAXK) if(parK[k][u] != parK[k][v]) u = parK[k][u], v = parK[k][v];
    
    if(u != v) u = parK[0][u], v = parK[0][v];
    return u;
}

void ad(int d, int x) {
    ll c = 1;
    while (z.size() && z[z.size()-1].f >= d) {
        c += z[z.size()-1].s;
        csum -= (ll)z[z.size()-1].f*z[z.size()-1].s;
        z.erase(z.end()-1);
    }
    z.pb({d,c});
    csum += c*d;
    ans[x] += csum;
}

void solve(vi cur) {
    if (cur.size() == 0) return;
    for (int i: cur) ans[i] = ans[p[i]]+depth[p[i]]; 
    
    csum = 0; z.clear();
    vi tmp;
    F0R(i,cur.size()-1) tmp.pb(depth[lca(cur[i],cur[i+1])]);
    FOR(i,1,cur.size()) ad(tmp[i-1],cur[i]);
    
    csum = 0, z.clear();
    F0Rd(i,cur.size()-1) ad(tmp[i],cur[i]);
    
    vi cur1;
    for (int i: cur) for (int j: child[i]) cur1.pb(j);
    solve(cur1);
}

void init() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n; 
	FOR(i,1,n+1) {
	    cin >> p[i];
	    if (p[i]) child[p[i]].pb(i);
	    if (!p[i]) ceo = i;
	}
}

int main() {
    init();
    dfs(ceo,0);
    F0R(i,MAXK-1) FOR(j,1,n+1) parK[i+1][j] = parK[i][parK[i][j]];
	solve({ceo});
	FOR(i,1,n+1) cout << ans[i] << " ";
}