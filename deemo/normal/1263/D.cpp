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
string s[MAXN];
vector<int> adj[MAXN];

void addEdge(int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool vis[MAXN];
void dfs(int v){
	if (vis[v]) return;
	vis[v] = true;
	for (int u: adj[v])
		dfs(u);
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (char ch: s[i])
			addEdge(ch - 'a', 26 + i);
	}
	int ans = 0;
	for (int i = 26; i < n + 26; i++)
		if (!vis[i])
			dfs(i), ans++;
	cout << ans << "\n";
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