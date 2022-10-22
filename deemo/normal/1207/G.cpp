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

int pos[MAXN], nxt[MAXN][C], sz, f[MAXN];
string t[MAXN];
vector<int> adjAho[MAXN];

int insert(string &s){
    int cur = 0;
    for (char c:s){
        int x = int(c - 'a');
        if (!nxt[cur][x])
            nxt[cur][x] = ++sz;
        cur = nxt[cur][x];
    }
    return cur;
}

int qq[MAXN];
void buildAho(){
    int h = 0, t = 0;
    for (int w = 0; w < C; w++)
        if (nxt[0][w])
            qq[t++] = nxt[0][w];

    while (t^h){
        int v = qq[h++];
		if (v)
			adjAho[f[v]].push_back(v);
        for (int w = 0; w < C; w++)
            if (nxt[v][w]){
                f[nxt[v][w]] = nxt[f[v]][w];
                qq[t++] = nxt[v][w];
            }
            else
                nxt[v][w] = nxt[f[v]][w];
    }
}

int n;
vector<pair<int, char>> adj[MAXN];
int par[MAXN];
int q, vv[MAXN];

#define tm akljsdf

int st[MAXN], ft[MAXN], tm, sub[MAXN];
vector<int> vec[MAXN];
void buildTree(int v) {
	st[v] = tm++;
	for (auto e: adj[v])
		buildTree(e.F);
	ft[v] = tm;

}

void dfsAdd(int v, int cur = 0){
	vec[cur].push_back(v);
	for (auto e: adj[v])
		dfsAdd(e.F, nxt[cur][e.S-'a']);
}

void buildSubs(int v){
	sub[v] = vec[v].size() + 1;
	for (auto u: adjAho[v])
		buildSubs(u), sub[v] += sub[u];
	sort(adjAho[v].begin(), adjAho[v].end(), [](int a, int b){
			return sub[a] > sub[b];
			});
}

int fen[MAXN];

void addFen(int v, int val){for (; v<MAXN; v+=v&-v) fen[v] += val;}
int getFen(int v){
	int ret = 0;
	for (; v; v -= v&-v)
		ret += fen[v];
	return ret;
}

int ans[MAXN];
vector<int> vecQ[MAXN];
void dfsAnsAdd(int v, bool ad){
	for (int x: vec[v]) {
		if (ad)
			addFen(st[x]+1, 1), addFen(ft[x]+1, -1);
		else
			addFen(st[x]+1, -1), addFen(ft[x]+1, 1);
	}
	for (int u: adjAho[v])
		dfsAnsAdd(u, ad);
}

void dfsAns(int v, bool keep = true){
	for (int i = 1; i < (int)adjAho[v].size(); i++)
		dfsAns(adjAho[v][i], false);
	if (adjAho[v].size())
		dfsAns(adjAho[v][0], true);
	for (int i = 1; i < (int)adjAho[v].size(); i++)
		dfsAnsAdd(adjAho[v][i], true);

	for (auto x: vec[v])
		addFen(st[x]+1, 1), addFen(ft[x]+1, -1);
	
	for (int u: vecQ[v]){
		ans[u] = getFen(st[vv[u]] + 1);
	}

	if (!keep)
		dfsAnsAdd(v, false);
}

void solve() {
	cin >> n; n++;
	par[0] = -1;
	for (int i = 1; i < n; i++){
		int type; cin >> type;
		char ch;
		if (type == 1){
			cin >> ch;
			par[i] = 0;
		}
		else{
			cin >> par[i] >> ch;
		}
		adj[par[i]].push_back({i, ch});
	}

	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> vv[i] >> t[i];
		pos[i] = insert(t[i]);
		vecQ[pos[i]].push_back(i);
	}
	buildAho();
	buildTree(0);
	dfsAdd(0);
	buildSubs(0);
	dfsAns(0);

	for (int i = 0; i < q; i++)
		cout << ans[i] << "\n";
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