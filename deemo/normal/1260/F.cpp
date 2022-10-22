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
	if (x >= MOD) x -= MOD;
	if (x < 0) x += MOD;
}

int fix(int x){
	if (x >= MOD) x -= MOD;
	if (x < 0) x += MOD;
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
const int XX = 1e5 + 3;

int n, tl[MAXN], tr[MAXN], PI = 1, inv[MAXN], ans, sv[MAXN];
vector<int> adj[MAXN];
int sub[MAXN];
bool blocked[MAXN];
int fen[2][MAXN];

const int ZZ = 3e7;
int sec[ZZ], sz = 0;

void add(int v, int val, int t){
	for (; v < MAXN; v += v&-v)
		add(fen[t][v], val), sec[sz++] = v;
}

int get(int v, int t){
	int ret = 0;
	for (; v; v-=v&-v)
		add(ret, fen[t][v]);
	return ret;
}

int subDfs(int v, int p = -1){
	sub[v] = 1;
	for (int u: adj[v])
		if (u != p && !blocked[u])
			sub[v] += subDfs(u, v);
	return sub[v];
}

void addSeg(int l, int r, int val) {
	l--;
	add(l+1, val, 0);
	add(r+1, fix(-val), 0);

	add(l+1, 1ll*l*val%MOD, 1);
	add(r+1, fix(-1ll*r*val%MOD), 1);
}

int getSeg(int l, int r) {
	int a = fix((1ll*get(r, 0)*r - 1ll*get(r, 1))%MOD);
	int b = fix((1ll*get(l, 0)*l - 1ll*get(l, 1))%MOD);
	return fix(a-b);
}

void dfsUpd(int v, int p, int de) {
	auto x = getSeg(tl[v], tr[v]);
	add(ans, 1ll*x*inv[v]%MOD*de%MOD);

	for (int u: adj[v])
		if (!blocked[u] && u != p)
			dfsUpd(u, v, de+1);
}

void dfsAdd(int v, int p, int de) {
	addSeg(tl[v]+1, tr[v], sv[v]);

	for (int u: adj[v])
		if (!blocked[u] && u != p)
			dfsAdd(u, v, de+1);
}

void go(int v){
	int tot = subDfs(v), p = -1, changed = 1;
	while (changed){
		changed = 0;
		for (int u: adj[v])
			if (!blocked[u] && u != p && sub[u]*2 >= tot) {
				p = v;
				v = u;
				changed = 1;
				break;
			}
	}

	blocked[v] = true;
	for (int u: adj[v])
		if (!blocked[u])
			go(u);
	blocked[v] = false;

	addSeg(tl[v]+1, tr[v], sv[v]);
	for (int u: adj[v])
		if (!blocked[u]) {
			dfsUpd(u, v, 1);
			dfsAdd(u, v, 1);
		}

	while (sz > 0) {
		sz--;
		fen[0][sec[sz]] = fen[1][sec[sz]] = 0;
	}

	reverse(adj[v].begin(), adj[v].end());
	for (int u: adj[v])
		if (!blocked[u]) {
			dfsUpd(u, v, 1);
			dfsAdd(u, v, 1);
		}
	while (sz > 0) {
		sz--;
		fen[0][sec[sz]] = fen[1][sec[sz]] = 0;
	}
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)  {
		cin >> tl[i] >> tr[i];
		tl[i]--;
		PI = 1ll*PI*(tr[i] - tl[i])%MOD;
		inv[i] = pw(tr[i] - tl[i], MOD-2);
	}
	for (int i = 0; i < n; i++)
		sv[i] = 1ll*PI*inv[i]%MOD;

	for (int i = 0; i < n-1; i++){
		int a, b; cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	go(0);
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