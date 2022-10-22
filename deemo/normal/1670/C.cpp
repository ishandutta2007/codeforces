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

int n, p[3][MAXN];
vector<int> adj[MAXN];
bool mark[MAXN], vis[MAXN];

int gg, cc;
void dfs(int v) {
    if (vis[v]) return;
    vis[v] = true;
    gg |= mark[v];
    cc++;
    for (int u: adj[v])
        dfs(u);
}

void solve() {
    cin >> n;
    for (int w = 0; w < 3; w++)
        for (int i = 0; i < n; i++)
            cin >> p[w][i], p[w][i]--;
    for (int i = 0; i < n; i++)
        adj[i].clear(), mark[i] = 0;
    for (int i = 0; i < n; i++) {
        adj[p[0][i]].push_back(p[1][i]);
        adj[p[1][i]].push_back(p[0][i]);
        if (~p[2][i])
            mark[p[0][i]] = mark[p[1][i]] = 1;
    }
    fill(vis, vis + n, 0);
    int ans = 0;
    for (int v = 0; v < n; v++)
        if (!vis[v]) {
            gg = cc = 0;
            dfs(v);
            ans += !gg && cc > 1;
        }
    cout << pw(2, ans) << "\n";
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