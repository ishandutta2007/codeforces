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

const int MAXN = 5e5 + 10;

int n;
vector<int> adj[MAXN];
int from[MAXN], to[MAXN];

int par[MAXN], sv[MAXN];
void dfs(int v, int pe = -1, bool fl = false) {
    if (v) {
        if (fl)
            sv[v] = v, sv[pe+n] = n|v;
        else
            sv[v] = n|v, sv[pe+n] = v;
    }
    for (int e: adj[v])
        if (e ^ pe) {
            int u = from[e]^to[e]^v;
            dfs(u, e, !fl);
        }
}

void solve() {
    cin >> n;
    n = 1<<n;
    for (int i = 0; i < n; i++) adj[i].clear();

    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, a--, b--;
        from[i] = a, to[i] = b;
        adj[a].push_back(i);
        adj[b].push_back(i);
    }
    dfs(0);

    cout << "1\n";
    sv[0] = n;
    for (int i = 0; i < n+n-1; i++) {
        cout << sv[i] << " ";
        if (i == n-1)
            cout << "\n";
    }
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