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

int n, m;
int p[MAXN];
pii b[MAXN];

bool vis[MAXN];
int ec, ord[MAXN];
int huh[MAXN];
void dfs(int v) {
    if (vis[v]) return;
    vis[v] = true;
    ord[v] = ec++;
    dfs(p[v]);
    huh[v] = ec;
}
vector<int> adj[2][MAXN];

void dfs2(int v) {
    if (vis[v]) return;
    vis[v] = true;
    for (int u: adj[1][v])
        dfs2(u);
    ord[v] = ec++;
}

int sec[MAXN];
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> p[i], p[i]--;
    for (int i = 0; i < m; i++) {
        cin >> b[i].F >> b[i].S, b[i].F--, b[i].S--;
        adj[0][b[i].F].push_back(i);
        adj[0][b[i].S].push_back(i);
    }
    for (int v = 0; v < n; v++)
        if (!vis[v]) {
            ec = 0;
            dfs(v);
        }
    for (int v = 0; v < n; v++) {
        sort(adj[0][v].begin(), adj[0][v].end(), [v](int e1, int e2) {
                int u1 = ord[b[e1].F^b[e1].S^v];
                int u2 = ord[b[e2].F^b[e2].S^v];
                int vv = ord[v];
                return (vv < u1? u1-vv: huh[v] - (vv-u1)) < (vv < u2? u2-vv: huh[v] - (vv-u2));
            });
        for (int i = 0; i + 1 < adj[0][v].size(); i++) {
            int e1 = adj[0][v][i];
            int e2 = adj[0][v][i+1];
            adj[1][e1].push_back(e2);
        }
    }
    memset(vis, 0, sizeof(vis));
    ec = 0;
    for (int e = 0; e < m; e++)
        if (!vis[e])
            dfs2(e);

    iota(sec, sec + m, 0);
    sort(sec, sec + m, [](int e1, int e2) {
            return ord[e1] > ord[e2];
            });
    for (int i = 0; i < m; i++)
        cout << sec[i]+1 << " ";
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