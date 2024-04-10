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

int n, m;
vector<int> adj[2][MAXN];
vector<pii> rev[MAXN];
int col[MAXN], dist[MAXN];

void solve() {
    cin >> n >> m;
    while (m--) {
        int a, b, c; cin >> a >> b >> c, a--, b--;
        adj[c][a].push_back(b);
        rev[b].push_back({a, c});
    }
    
    memset(col, -1, sizeof(col));
    memset(dist, 63, sizeof(dist));
    set<pii> st;
    dist[n-1] = 0;
    col[n-1] = 0;
    st.insert({0, n-1});

    while (st.size()) {
        int v = st.begin()->S;
        st.erase(st.begin());

        for (auto e: rev[v]) {
            if (col[e.F] == -1)
                col[e.F] = !e.S;
            else if (col[e.F] == e.S && dist[e.F] > dist[v] + 1) {
                st.erase({dist[e.F], e.F});
                dist[e.F] = dist[v] + 1;
                st.insert({dist[e.F], e.F});
            }
        }
    }

    if (dist[0] > 1e8)
        dist[0] = -1;
    cout << dist[0] << "\n";
    for (int v = 0; v < n; v++)
        if (col[v] < 0)
            cout << 0;
        else
            cout << col[v];
    cout << "\n";
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