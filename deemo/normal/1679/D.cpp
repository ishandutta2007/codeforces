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
ll k;
int a[MAXN], aa[MAXN], bb[MAXN];
vector<int> adj[MAXN];
bool bad[MAXN];

int vis[MAXN], cyc, sec[MAXN], sz;
void dfs(int v) {
    if (vis[v]) {
        if (vis[v] == 1)
            cyc = true;
        return;
    }
    vis[v] = 1;
    for (int u: adj[v])
        dfs(u);
    vis[v] = 2;
    sec[sz++] = v;
}

int d[MAXN];
bool check(int mid) {
    for (int v = 0; v < n; v++)
        adj[v].clear(), bad[v] = a[v] > mid;
    for (int e = 0; e < m; e++)
        if (!bad[aa[e]] && !bad[bb[e]])
            adj[aa[e]].push_back(bb[e]);

    cyc = 0;
    memset(vis, 0, sizeof(vis));
    sz = 0;
    for (int v = 0; v < n; v++)
        if (!bad[v] && !vis[v])
            dfs(v);
    if (cyc)
        return true;

    for (int i = 0; i < sz; i++) {
        int v = sec[i];
        d[v] = 1;
        for (int u: adj[v])
            d[v] = max(d[v], d[u] + 1);
        if (d[v] >= k)
            return true;
    }
    return false;
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> aa[i] >> bb[i], aa[i]--, bb[i]--;

    int lo = 0, hi = 1e9 + 6;
    while (hi-lo>1) {
        int mid = hi+lo>>1;
        if (check(mid))
            hi = mid;
        else
            lo = mid;
    }
    cout << (hi>1e9? -1: hi) << "\n";
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