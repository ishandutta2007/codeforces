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
const int SQ = 1000;

int n, q;
vector<int> adj[2][MAXN];
int type[MAXN], uu[MAXN], vv[MAXN];
set<pii> exists;
bool mark[MAXN];

int inc(int x){return x+1==n? 0: x+1;}

int comp[MAXN], gg;
void dfsComp(int v){
	if (comp[v]) return;
	comp[v] = gg;
	for (int u: adj[0][v])
		dfsComp(u);
}

pii getInOrder(pii p){return p.F<p.S? p: make_pair(p.S, p.F);}

void build(int l, int r){
	for (int v = 0; v <= n; v++) adj[0][v].clear(), adj[1][v].clear();
	memset(mark, 0, sizeof(mark));
	set<pii> temp;
	for (int i = l; i < r; i++)
		mark[uu[i]] = mark[vv[i]] = mark[inc(uu[i])] = mark[inc(vv[i])] = true, temp.insert(getInOrder({uu[i], vv[i]})), temp.insert(getInOrder({inc(uu[i]), inc(vv[i])}));
	for (auto x: exists)
		if (!temp.count(x))
			adj[0][x.F].push_back(x.S), adj[0][x.S].push_back(x.F);
	gg = 0;
	memset(comp, 0, sizeof(comp));
	for (int v = 0; v < n; v++)
		if (mark[v] && !comp[v]){
			gg++;
			dfsComp(v);
		}
	for (int v = 0; v < n; v++) comp[v]--;
	for (auto x: exists)
		if (temp.count(x) && comp[x.F] != comp[x.S])
			adj[1][comp[x.F]].push_back(comp[x.S]), adj[1][comp[x.S]].push_back(comp[x.F]);
}

bool vis[MAXN];
bool dfs(int v, int dest){
	if (vis[v]) return false;
	vis[v] = true;
	if (v == dest) return true;
	for (int u: adj[1][v])
		if (!vis[u] && dfs(u, dest))
			return true;
	return false;
}

void removeEdge(int v, int u){
	adj[1][v].erase(find(adj[1][v].begin(), adj[1][v].end(), u));
}

void solve() {
	cin >> n >> q;
	for (int i = 0; i < q; i++) cin >> type[i] >> uu[i] >> vv[i], uu[i]--, vv[i]--;
	int last = 0;
	for (int i = 0; i < q; i++){
		if (i%SQ == 0)
			build(i, min(i+SQ, q));
		if (last)
			uu[i] = inc(uu[i]), vv[i] = inc(vv[i]);
		if (uu[i] > vv[i])
			swap(uu[i], vv[i]);

		if (type[i] == 1){
			if (exists.count({uu[i], vv[i]})){
				exists.erase({uu[i], vv[i]});
				if (comp[uu[i]] != comp[vv[i]])  {
					removeEdge(comp[uu[i]], comp[vv[i]]);
					removeEdge(comp[vv[i]], comp[uu[i]]);
				}
			}
			else{
				exists.insert({uu[i], vv[i]});
				if (comp[uu[i]] != comp[vv[i]]) {
					adj[1][comp[uu[i]]].push_back(comp[vv[i]]);
					adj[1][comp[vv[i]]].push_back(comp[uu[i]]);
				}
			}
		}
		else{
			fill(vis, vis + gg, 0);
			if (dfs(comp[uu[i]], comp[vv[i]])) {
				cout << "1";
				last = 1;
			}
			else {
				cout << "0";
				last = 0;
			}
		}
	}
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