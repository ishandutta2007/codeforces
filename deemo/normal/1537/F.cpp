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

int n, m, x[MAXN];
vector<int> adj[MAXN];

int vis[MAXN];
bool fl;
void dfs(int v, int col=1) {
    if (vis[v]) {
        if (col != vis[v])
            fl = true;
        return;
    }
    vis[v] = col;
    for (int u: adj[v])
        dfs(u, 3-col);
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) adj[i].clear();
    for (int i = 0; i < n; i++) cin >> x[i], vis[i] = 0;
    ll sm = 0;
    for (int i = 0; i < n; i++) {
        int y; cin >> y;
        x[i] = y - x[i];
        sm += x[i];
    }
    while (m--) {
        int a, b; cin >> a >> b, a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if (sm&1){
        cout << "NO\n";
        return;
    }

    fl = 0;
    dfs(0);
    if (fl)
        cout << "YES\n";
    else {
        ll s[3] = {0};
        for (int i = 0; i < n; i++)
            s[vis[i]] += x[i];
        if (s[1] == s[2])
            cout << "YES\n";
        else
            cout << "NO\n";
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