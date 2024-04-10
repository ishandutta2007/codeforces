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

const int MAXN = 1e6 + 10;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m;
vector<int> adj[MAXN];
int from[MAXN], to[MAXN];
bool failed;
int dl;

int c[MAXN];
bool on_path[MAXN], is_cand[MAXN];
bool vis[MAXN];
void dfs(int v, int cur = 0, int pe = -1) {
    vis[v] = true;
    c[v] = cur;
    cur ^= 1;
    for (int e: adj[v]) {
        if (e == dl || e == pe) continue;

        on_path[e] = true;
        int u = from[e]^to[e]^v;
        if (!vis[u])
            dfs(u, cur, e);
        else if (c[u] != cur) {
            failed = true;
            for (int e = 0; e < m; e++)
                is_cand[e] &= on_path[e];
        }
        if (failed)
            return;
        on_path[e] = false;
    }
}

int ans;
int sec[MAXN];
void col(int e = -1) {
    dl = e;
    fill(vis, vis + n, 0);
    fill(on_path, on_path + m, 0);
    iota(sec, sec + n, 0);
    shuffle(sec, sec + n, rng);
    for (int v = 0; v < n; v++)
        shuffle(adj[v].begin(), adj[v].end(), rng);
    for (int i = 0; i < n && !failed; i++) {
        int v = sec[i];
        if (!vis[v])
            dfs(v);
    }

    if (!failed) {
        if (e == -1)
            ans = 0;
        else
            ans = c[from[e]];
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) adj[i].clear();
    for (int i = 0; i < m; i++)
        cin >> from[i] >> to[i], from[i]--, to[i]--, adj[from[i]].push_back(i), adj[to[i]].push_back(i);

    failed = false;
    fill(is_cand, is_cand + m, true);
    ans = -1;
    col();
    if (!failed) {
        cout << "YES\n";
        for (int v = 0; v < n; v++)
            cout << (c[v] == ans);
        cout << "\n";
        return;
    }

    while (true) {
        int num_cands = 0;
        for (int e = 0; e < m; e++)
            num_cands += is_cand[e];
        if (!num_cands) {
            cout << "NO\n";
            return;
        }
        int id = uniform_int_distribution<int>(0, num_cands)(rng);
        int who = -1;
        for (int e = 0; e < m; e++)
            if (is_cand[e] && id-- == 0) {
                who = e;
                break;
            }
        failed = false;
        col(who);
        if (!failed) {
            cout << "YES\n";
            for (int v = 0; v < n; v++)
                cout << (c[v] == ans);
            cout << "\n";
            return;
        }
    }
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}