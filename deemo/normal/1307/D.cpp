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

const int MAXN = 2e5 + 10;

int n, m, k, a[MAXN];
vector<int> adj[MAXN];
int lv[2][MAXN];

int q[MAXN];
void bfs(int w,  int v) {
	memset(lv[w], 63, sizeof(lv[w]));
	int h = 0, t = 0;
	lv[w][v] = 0;
	q[t++] = v;
	while (t^h) {
		v = q[h++];
		for (int u: adj[v])
			if (lv[w][v] + 1 < lv[w][u]) {
				lv[w][u] = lv[w][v] + 1;
				q[t++] = u;
			}
	}
}

bool cmp(int u, int v) { return lv[0][u] < lv[0][v]; }

int mx[MAXN];
void solve() {
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) cin >> a[i], a[i]--;
	while (m--) {
		int a, b; cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	bfs(0, 0);
	bfs(1, n-1);
	int ans = -1;
	sort(a, a + k, cmp);
	mx[k] = -1e9;
	for (int i = k-1; ~i; i--) {
		ans = max(ans, lv[0][a[i]] + 1 + mx[i+1]);
		mx[i] = max(mx[i+1], lv[1][a[i]]);
	}
	cout << min(ans, lv[0][n-1]) << "\n";
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