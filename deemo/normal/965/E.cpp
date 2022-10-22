#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;
const int C = 26;

int n;
int tr[MAXN][C], sz;
bool mark[MAXN];

void insert(string &s){
	int cur = 0;
	for (char c:s){
		int x = c - 'a';
		if (!tr[cur][x])
			tr[cur][x] = ++sz;
		cur = tr[cur][x];
	}

	mark[cur] = true;
}

vector<int> adj[MAXN];
set<pii> st[MAXN];
int depth[MAXN];
ll ans = 0;
void plant(int v){
	if (mark[v])
		ans += depth[v];
	for (int w = 0; w < C; w++)
		if (tr[v][w]){
			adj[v].push_back(tr[v][w]);
			depth[tr[v][w]] = depth[v] + 1;
			plant(tr[v][w]);
		}
}

void go(int v){
	int mx = 0;
	for (int u:adj[v])
		go(u), mx = max(mx, (int)st[u].size());
	if (v == 0) return;

	for (int u:adj[v])
		if (st[u].size() == mx){
			st[v].swap(st[u]);
			break;
		}
	if (mark[v])
		st[v].insert({depth[v], v});
	for (int u:adj[v]) {
		for (auto x:st[u])
			st[v].insert(x);
		st[u].clear();
	}

	if (st[v].begin()->F != depth[v]){
		auto x = *st[v].rbegin();
		st[v].erase(*st[v].rbegin());
		ans -= x.F-depth[v];
		x.F = depth[v];
		st[v].insert(x);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		string s; cin >> s;
		insert(s);
	}
	plant(0);
	go(0);
	cout << ans << endl;
	return 0;
}