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

const int MAXN = 1e6 + 100;

int n, edges;
pii p[MAXN];
vector<int> adj[MAXN];
int match[MAXN];
int mx[MAXN<<2];

void go(int v, int b, int e, int l, int r, int u){
	if (r <= b || e <= l) return;
	if (l <= b && e <= r && mx[v] < r) return;
	if (edges > n-1) return;

	if (e - b == 1){
		edges++;
		adj[match[b]].push_back(u);
		adj[u].push_back(match[b]);
		return;
	}

	int mid = b + e >> 1;
	go(v<<1, b, mid, l, r, u);
	go(v<<1^1, mid, e, l, r, u);
}

void upd(int v, int b, int e, int pos, int val){
	if (e - b == 1){
		mx[v] = val;
		return;
	}

	int mid = b + e >> 1;
	if (pos < mid)
		upd(v<<1, b, mid, pos, val);
	else
		upd(v<<1^1, mid, e, pos, val);
	mx[v] = max(mx[v<<1], mx[v<<1^1]);
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
	for (int i = 0; i < n; i++) cin >> p[i].F >> p[i].S;
	sort(p, p+n, [](pii a, pii b) {
		return a.S < b.S;		
	});

	memset(match, -1, sizeof(match));
	memset(mx, -1, sizeof(mx));
	for (int i = n-1; ~i; i--){
		go(1, 1, 2*n+1, p[i].F+1, p[i].S, i);
		match[p[i].F] = i;
		upd(1, 1, 2*n+1, p[i].F, p[i].S);
	}

	if (edges != n-1)
		cout << "NO\n";
	else{
		dfs(0);
		for (int v = 0; v < n; v++)
			if (!vis[v]){
				cout << "NO\n";
				return;
			}
		cout << "YES\n";
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