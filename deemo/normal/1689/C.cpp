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

int n;
vector<int> adj[MAXN];
int sub[MAXN], d[MAXN];

void dfs(int v, int p = -1) {
    sub[v] = 1;
    if (~p)
        adj[v].erase(find(adj[v].begin(), adj[v].end(), p));

    for (int u: adj[v])
        dfs(u, v), sub[v] += sub[u];

    if (adj[v].empty())
        d[v] = 0;
    else if (adj[v].size() == 1)
        d[v] = sub[v] - 2;
    else {
        int u1 = adj[v][0];
        int u2 = adj[v][1];
        d[v] = max(sub[u1] - 1 + d[u2], sub[u2]-1 + d[u1]);
    }
}

void solve() {
    cin >> n; for (int i = 0; i < n; i++) adj[i].clear(); for (int i = 0; i + 1< n; i++) { int a, b; cin >> a >> b, a--, b--; adj[a].push_back(b), adj[b].push_back(a);}
    dfs(0);
    cout << d[0] << "\n";
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