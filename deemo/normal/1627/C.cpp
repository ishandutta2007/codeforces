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

const int MAXN = 1e5 + 10;

int n;
vector<int> adj[MAXN];
int aa[MAXN], bb[MAXN];
int ans[MAXN];

void dfs(int v, int p = -1, int col = 0) {
    if (~p) {
        if (col)
            ans[p] = 2;
        else
            ans[p] = 3;
    }

    for (int e: adj[v]) {
        if (e == p) continue;
        int u = aa[e]^bb[e]^v;
        dfs(u, e, col^1);
        col ^= 1;
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) adj[i].clear();
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, a--, b--;
        adj[a].push_back(i);
        adj[b].push_back(i);
        aa[i] = a;
        bb[i] = b;
    }
    for (int v = 0; v < n; v++)
        if (adj[v].size() > 2) {
            cout << "-1\n";
            return;
        }
    dfs(0);
    for (int i = 0; i < n-1; i++)
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