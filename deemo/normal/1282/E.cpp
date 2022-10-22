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

int n, a[MAXN][3];
map<pii, int> mp;
map<pii, vector<int>> mp2;

vector<int> adj[MAXN];

bool vis[MAXN];
void dfs(int v){
	if (vis[v]) return;
	vis[v] = true;

	for (int u: adj[v])
		dfs(u);
	cout << v+1 << " ";
}

void dfs2(int v, int p = -1){
	for (int u: adj[v])
		if (u^p)
			dfs2(u, v);
	cout << v+1 << " ";
}

void solve() {
	cin >> n;
	mp.clear();
	mp2.clear();
	for (int i = 0; i < n; i++) adj[i].clear();

	for (int i = 0; i < n-2; i++) {
		for (int j = 0; j < 3; j++)
			cin >> a[i][j], a[i][j]--;
		for (int j = 0; j < 3; j++) {
			int nxt = (j+1)%3;
			mp[{a[i][j], a[i][nxt]}]++;
			mp[{a[i][nxt], a[i][j]}]++;

			if (a[i][j] < a[i][nxt])
				mp2[{a[i][j], a[i][nxt]}].push_back(i);
			else
				mp2[{a[i][nxt], a[i][j]}].push_back(i);
		}
	}

	for (int i = 0; i < n-2; i++)
		for (int j = 0; j < 3; j++){
			int nxt = (j+1)%3;
			if (mp[{a[i][j], a[i][nxt]}] == 1) {
				adj[a[i][j]].push_back(a[i][nxt]);
				adj[a[i][nxt]].push_back(a[i][j]);
			}
		}

	fill(vis, vis + n, 0);
	dfs(0);
	cout << "\n";

	for (int i = 0; i < n; i++) adj[i].clear();
	for (auto x: mp2)
		if (x.F.F < x.F.S && x.S.size() == 2){
			adj[x.S[0]].push_back(x.S[1]);
			adj[x.S[1]].push_back(x.S[0]);
		}
	dfs2(0);
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