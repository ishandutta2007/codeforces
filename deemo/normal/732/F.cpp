#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 1e9 + 7;//XXX
const int C = 26;//XXX

void add(int &x, int y){
	x += y;
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
}

int fix(int x){
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
	return x;
}

int pw(int a, int b){
	int ret = 1;
	while (b){
		if (b & 1)
			ret = 1ll*ret*a%MOD;
		b >>= 1;
		a = 1ll*a*a%MOD;
	}
	return ret;
}

const int MAXN = 5e5 + 10;

int n, m;
int uu[MAXN], vv[MAXN];
vector<int> adj[MAXN];
bool mark[MAXN], vis[MAXN];
int depth[MAXN];

void direct_edge(int e, int u) {
    if (uu[e] != u)
        swap(uu[e], vv[e]);
}

int dfs(int v, int pe = -1, int de = 0) {
    vis[v] = true;
    int mn = depth[v] = de;
    for (int e: adj[v])
        if (e^pe) {
            int u = uu[e] ^ vv[e] ^ v;
            if (vis[u]) {
                if (depth[u] < depth[v])
                    direct_edge(e, v);
                mn = min(mn, depth[u]);
            }
            else {
                direct_edge(e, v);
                mn = min(mn, dfs(u, e, de + 1));
            }
        }
    if (mn >= depth[v]) {
        mark[pe] = true;
    }
    return mn;
}

int comp[MAXN], gg;
vector<int> adj2[MAXN];

int cc;
void dfs_comp(int v) {
    cc++;
    comp[v] = gg;
    for (int e: adj[v])
        if (!mark[e]) {
            int u = uu[e] ^ vv[e] ^ v;
            if (comp[u] == -1)
                dfs_comp(u);
        }
}

set<pii> st;
void dfs2(int v, int p = -1) {
    for (int u: adj2[v])
        if (u^p)
            dfs2(u, v), st.insert({v, u});
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> uu[i] >> vv[i], uu[i]--, vv[i]--;
        adj[uu[i]].push_back(i);
        adj[vv[i]].push_back(i);
    }
    dfs(0);
    memset(comp, -1, sizeof(comp));
    pii big {-1, -1};
    for (int v = 0; v < n; v++)
        if (comp[v] == -1) {
            cc = 0;
            dfs_comp(v);
            big = max(big, make_pair(cc, gg));
            gg++;
        }
    for (int e = 0; e < m; e++)
        if (comp[uu[e]] != comp[vv[e]]) {
            adj2[comp[uu[e]]].push_back(comp[vv[e]]);
            adj2[comp[vv[e]]].push_back(comp[uu[e]]);
        }
    dfs2(big.second);
    for (int e = 0; e < m; e++)
        if (comp[uu[e]] != comp[vv[e]]) {
            if (st.count({comp[uu[e]], comp[vv[e]]}))
                swap(uu[e], vv[e]);
        }

    cout << big.first << "\n";
    for (int e = 0; e < m; e++)
        cout << uu[e]+1 << " " << vv[e] + 1 << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	//cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}