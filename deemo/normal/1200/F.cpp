#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 2520;
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

const int MAXN = 1e3 + 10;
const int LCM = 2520;

int n;
vector<int> adj[MAXN];
int k[MAXN];
int d[MAXN*LCM];
int vis[MAXN*LCM];

int sec[MAXN * LCM], sz;
int mark[MAXN], gg;
void dfs(int v){
	if (vis[v]){
		if (vis[v] == 1) {
			gg++;
			for (int i = 0; i < sz; i++)
				if (sec[i] == v){
					int count = 0;
					for (int j = i; j < sz; j++) {
						int temp = sec[j]/ LCM;
						if (mark[temp] != gg)
							mark[temp] = gg, count++;
					}
					for (int j = i; j < sz; j++)
						d[sec[j]] = count;
					break;
				}
		}
		return;
	}
	vis[v] = 1;
	sec[sz++] = v;
	int r = v%LCM;
	int vv = v / LCM;

	int u = adj[vv][r % (int)adj[vv].size()];
	r = fix(r + k[u]);
	u = u*LCM + r;
	dfs(u);
	if (d[v] == -1)
		d[v] = d[u];

	vis[v] = 2;
	sz--;
}

void solve() {
	for (int i = 1; i <= 10; i++)
		assert(LCM % i == 0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> k[i], k[i] %= LCM;
	for (int i = 0; i < n; i++){
		int t; cin >> t;
		adj[i].resize(t);
		for (int j = 0; j < t; j++)
			cin >> adj[i][j], adj[i][j]--;
	}
	memset(d, -1, sizeof(d));
	for (int i = 0; i < n; i++)
		for (int r = 0; r < LCM; r++) {
			int id = i*LCM + r;
			if (!vis[id])
				dfs(id);
		}

	int q; cin >> q;
	while (q--){
		int v, r; cin >> v >> r, v--;
		r %= LCM;
		r = fix(r + k[v]);
		v = v*LCM + r;
		cout << d[v] << "\n";
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