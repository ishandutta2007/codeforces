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

int n, m;
int from[MAXN], to[MAXN], w[MAXN];
vector<int> adj[MAXN];
int par[MAXN];
int comp[30][MAXN];
bool marked[MAXN];
bool m2[MAXN];

int get_par(int v) {return par[v]==v? v: par[v]=get_par(par[v]);}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> from[i] >> to[i] >> w[i], from[i]--, to[i]--, adj[from[i]].push_back(i), adj[to[i]].push_back(i);
    
    for (int bit = 0; bit < 30; bit++) {
        iota(par, par + n, 0);
        for (int e = 0; e < m; e++)
            if (w[e]>>bit&1) {
                int u = from[e], v = to[e];
                u = get_par(u), v = get_par(v);
                par[u] = v;
            }
        for (int v = 0; v < n; v++)
            comp[bit][v] = get_par(v);
    }

    set<int> st;
    for (int bit = 1; bit < 30; bit++) {
        memset(marked, 0, sizeof(marked));
        for (int e = 0; e < m; e++)
            if (!(w[e]&1))
                marked[comp[bit][from[e]]] = marked[comp[bit][to[e]]] = 1;
        for (int v = 0; v < n; v++)
            if (marked[comp[bit][v]])
                m2[v] = 1;
    }
    
    int q; cin >> q;
    while (q--) {
        int u, v; cin >> u >> v, u--, v--;
        bool eh = false;
        for (int bit = 0; !eh && bit < 30; bit++)
            if (comp[bit][u] == comp[bit][v])
                eh = true;
        if (eh)
            cout << "0\n";
        else if (m2[u])
            cout << "1\n";
        else
            cout << "2\n";
    }
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