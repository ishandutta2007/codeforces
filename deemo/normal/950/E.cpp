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

const int MAXN = 2e5 + 10;

int n, m, h;
int t[MAXN];
vector<int> adj[MAXN];
vector<int> g[2][MAXN];

int nxt(int x) {
    return x + 1 == h? 0: x+1;
}

bool vis[MAXN];
int sec[MAXN], sz;
void dfs1(int v) {
    if (vis[v]) return;
    vis[v] = true;

    for (int u: g[0][v])
        dfs1(u);
    sec[sz++] = v;
}

int comp[MAXN], gg;
int sub[MAXN];
void dfs2(int v) {
    if (vis[v]) return;
    vis[v] = true;

    comp[v] = gg;
    sub[gg]++;
    for (int u: g[1][v])
        dfs2(u);
}

bool bad[MAXN];
void solve() {
    cin >> n >> m >> h;
    for (int i = 0; i < n; i++) cin >> t[i];
    while (m--) {
        int a, b;
        cin >> a >> b, a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int v = 0; v < n; v++)
        for (int u: adj[v])
            if (nxt(t[v]) == t[u]) {
                g[0][v].push_back(u);
                g[1][u].push_back(v);
            }
    for (int v = 0; v < n; v++)
        dfs1(v);
    reverse(sec, sec + sz);
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < sz; i++) {
        int v = sec[i];
        if (vis[v]) continue;

        dfs2(v);
        gg++;
    }

    for (int v = 0; v < n; v++)
        for (int u: g[0][v])
            if (comp[u] != comp[v])
                bad[comp[v]] = true;

    int best = -1;
    for (int i = 0; i < gg; i++)
        if (!bad[i] && (best == -1 || sub[best] > sub[i]))
            best = i;

    cout << sub[best] << "\n";
    for (int v = 0; v < n; v++)
        if (comp[v] == best)
            cout << v+1 << " ";
    cout << "\n";
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