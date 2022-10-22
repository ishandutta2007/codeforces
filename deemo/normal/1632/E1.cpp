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

const int MAXN = 3e5 + 10;

int n, depth[MAXN];
vector<int> adj[MAXN];
int max_depth[MAXN];
int par[MAXN];

void dfs(int v, int p = -1, int de = 0) {
    depth[v] = de;
    max_depth[v] = de;
    par[v] = p;
    for (int u: adj[v])
        if (u^p) {
            dfs(u, v, de + 1);
            max_depth[v] = max(max_depth[v], max_depth[u]);
        }
}

bool mark[MAXN];
int nxt[MAXN];
void mark_pars(int v) {
    while (~v) {
        mark[v] = true;
        if (~par[v])
            nxt[par[v]] = v;
        v = par[v];
    }
}

int de[2][MAXN];
void dfs2(int v) {
    int mx = depth[v];
    for (int u: adj[v])
        if (u^par[v]) {
            if (mark[u])
                dfs2(u);
            else
                mx = max(mx, max_depth[u]);
        }
    de[0][depth[v]] = mx;
    de[1][depth[v]] = (1e6 - depth[v]) + max(0, mx - depth[v]);
}

int seg[2][MAXN<<2];
void plant(int v, int b, int e) {
    if (e - b == 1) {
        seg[0][v] = de[0][b];
        seg[1][v] = de[1][b];
        return;
    }

    int mid = b + e >> 1;
    plant(v<<1, b, mid);
    plant(v<<1^1, mid, e);
    seg[0][v] = max(seg[0][v<<1], seg[0][v<<1^1]);
    seg[1][v] = max(seg[1][v<<1], seg[1][v<<1^1]);
}

int get(int v, int b, int e, int l, int r, int w) {
    if (l <= b && e <= r) return seg[w][v];
    if (r <= b || e <= l) return -1e8;

    int mid = b + e >> 1;
    return max(get(v<<1, b, mid, l, r, w), get(v<<1^1, mid, e, l, r, w));
}

int xx;
int get_ans(int v, int x) {
    x = min(x, depth[v]);
    int l = (depth[v] + x + 1) / 2;  // XXX;
    int y = max(get(1, 0, xx, 0, l, 0), get(1, 0, xx, l, xx, 1) - ((int)1e6 - depth[v]) + x);
    //cout << y << endl;
    y = max(y, max_depth[v] + x - depth[v]);
    return y;
}

int ans[MAXN];
void solve() {
    cin >> n;
    fill(mark, mark + n, 0);
    fill(nxt, nxt + n, -1);
    for (int i = 0; i < n; i++) adj[i].clear();
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0);
    pii deep {-1, -1};
    for (int v = 0; v < n; v++)
        if (deep < make_pair(depth[v], v))
            deep = {depth[v], v};
    
    int v = deep.S;
    xx = deep.F + 1;
    mark_pars(v);
    dfs2(0);
    plant(1, 0, xx);
    v = nxt[0];/*
    for (int i = 0; i < xx; i++)
        cout << de[0][i] << "     " << de[1][i] << endl;
    cout << deep.S << "   " << get_ans(0, 1) << " " << get_ans(1, 1) << "\n";*/
    for (int x = 1; x <= n; x++) {
        while (~nxt[v] && get_ans(nxt[v], x) < get_ans(v, x))
            v = nxt[v];
        ans[x] = get_ans(v, x);
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << "\n";
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