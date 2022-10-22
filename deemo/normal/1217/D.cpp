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

const int MAXN = 5e3 + 10;

int n, m;
vector<int> adj[MAXN];
int from[MAXN], to[MAXN], vis[MAXN];
bool foundC = false;

void dfs(int v){
	if (vis[v]){
		if (vis[v] == 1)
			foundC = true;
		return;
	}
	vis[v] = 1;
	for (int e: adj[v])
		dfs(to[e]);
	vis[v] = 2;
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> from[i] >> to[i], from[i]--, to[i]--, adj[from[i]].push_back(i);
	for (int v = 0; v < n; v++)
		if (!vis[v])
			dfs(v);
	if (!foundC){
		cout << "1\n";
		for (int i = 0; i < m; i++)
			cout << "1 ";
		cout << "\n";
	}
	else{
		cout << "2\n";
		for (int i = 0; i < m; i++)
			if (from[i] < to[i])
				cout << "1 ";
			else
				cout << "2 ";
		cout << "\n";
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