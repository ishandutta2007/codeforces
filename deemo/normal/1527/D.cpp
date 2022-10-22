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

int n;
vector<int> adj[MAXN];
int par[MAXN], sub[MAXN];

void dfs(int v, int p = -1) {
    par[v] = p;
    sub[v] = 1;
    for (int u: adj[v])
        if (u^p)
            dfs(u, v), sub[v] += sub[u];
}

ll ans[MAXN];
int mark[MAXN], gg;

void solve() {
    gg++;
    cin >> n;
    fill(ans, ans + n+2, 0ll);
    for (int i = 0; i < n; i++) adj[i].clear();

    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0);
    int x = 0, y = 0;
    ans[0] = 1ll*n*(n-1)/2;
    {
        int cnt = 1;
        for (int u: adj[0]) {
            ans[1] += 1ll*cnt*sub[u];
            cnt += sub[u];
        }
    }
    mark[0] = gg;
    for (int i = 1; i < n; i++) {
        if (mark[i] == gg) {
            ans[i+1] = 1ll*sub[x]*sub[y];
        } else {
            int v = i;
            while (mark[v] != gg) {
                mark[v] = gg;
                if (par[v] == 0)
                    sub[par[v]] -= sub[v];
                v = par[v];
            }
            if (v != x && v != y) {
                goto there;
            }
            if (v == x)
                x = i;
            else
                y = i;
            ans[i+1] = 1ll*sub[x]*sub[y];
        }
    }
there:
    
    for (int i = 0; i <= n; i++)
        cout << ans[i] - ans[i+1] << " ";
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