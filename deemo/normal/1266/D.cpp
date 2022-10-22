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

const int MAXN = 5e6 + 10;
const int XX = 1e5 + 10;

int n, m;
vector<int> adj[2][XX];
int from[MAXN], to[MAXN], ec;
ll w[MAXN];
bool del[MAXN];
pair<pii, ll> sec[XX*3]; int sz;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c, a--, b--;
		from[i] = a, to[i] = b, w[i] = c;
		adj[0][a].push_back(i);
		adj[1][b].push_back(i);
	}
	ec = m;
	for (int v = 0; v < n; v++)
		while (min(adj[0][v].size(), adj[1][v].size())) {
			int e1 = adj[0][v].back(); adj[0][v].pop_back();
			if (del[e1] || w[e1] <= 0) {
				del[e1] = true;
				continue;
			}

			int e2 = adj[1][v].back(); adj[1][v].pop_back();
			if (del[e2] || w[e2] <= 0) {
				adj[0][v].push_back(e1);
				del[e2] = true;
				continue;
			}

			ll tw = min(w[e1], w[e2]);
			w[e1] -= tw;
			if (w[e1] == 0)
				del[e1] = true;
			w[e2] -= tw;
			if (w[e2] == 0)
				del[e2] = true;
			if (!del[e1])
				adj[0][v].push_back(e1);
			if (!del[e2])
				adj[1][v].push_back(e2);

			from[ec] = from[e2];
			to[ec] = to[e1];
			if (from[ec] == to[ec])
				continue;
			w[ec] = tw;
			adj[0][from[ec]].push_back(ec);
			adj[1][to[ec]].push_back(ec);
	
			ec++;
		}
	
	for (int i = 0; i < n; i++)
		for (int e: adj[0][i])
			if (!del[e] && w[e] > 0)
				sec[sz++] = {{from[e], to[e]}, w[e]};
	sort(sec, sec + sz);
	
	vector<pair<pii, ll>> vec;
	for (int l = 0; l < sz;){
		int r = l;
		while (r < sz && sec[l].F == sec[r].F) r++;
	
		ll sm = 0;
		for (int i = l; i < r; i++) sm += sec[i].S;
		vec.push_back({sec[l].F, sm});

		l = r;
	}

	cout << vec.size() << "\n";
	for (auto x: vec)
		cout << x.F.F+1 << " " << x.F.S+1 << " " << x.S << "\n";
	return 0;
}