#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e5 + 10;
const int C = 20;

int n;
ll ans[MAXN];
string s;
vector<int> adj[MAXN];
int par[MAXN], sub[MAXN];
bool blocked[MAXN];
int cnt[1<<C];

void plant(int v, int p = -1) {
	par[v] = p;
	sub[v] = 1;
	for (int u:adj[v])
		if (u^p && !blocked[u]) {
			plant(u, v);
			sub[v] += sub[u];
		}
}

int conv(int v){return int(s[v]-'a');}

void add(int v, int p, int cur) {
	cur ^= 1<<conv(v);
	cnt[cur]++;
	for (int u:adj[v])
		if (u^p && !blocked[u])
			add(u, v, cur);
}

void del(int v, int p, int cur) {
	cur ^= 1<<conv(v);
	cnt[cur]--;
	for (int u:adj[v])
		if (u^p && !blocked[u])
			del(u, v, cur);
}

ll cc[MAXN];
void get(int v, int p, int cur) {
	cur ^= 1<<conv(v);
	cc[v] = cnt[cur];
	for (int i = 0; i < C; i++)
		cc[v] += cnt[cur^1<<i];

	for (int u:adj[v])
		if (u^p && !blocked[u]) {
			get(u, v, cur);
			cc[v] += cc[u];
		}
	ans[v] += cc[v];
}

void solve(int v) {
	plant(v);
	int p = -1, ts = sub[v];
	bool changed = true;
	while (changed) {
		changed = false;
		for (int u:adj[v])
			if (u^p && !blocked[u] && sub[u]*2 > ts) {
				p = v;
				v = u;
				changed = true;
				break;
			}
	}

	blocked[v] = true;
	for (int u:adj[v])
		if (!blocked[u])
			solve(u);
	blocked[v] = false;

	cnt[0] = 1;
	for (int u:adj[v])
		if (!blocked[u]) {
			get(u, v, 1<<conv(v));
			ans[v] += cc[u];
			add(u, v, 0);
		}
	for (int u:adj[v])
		if (!blocked[u])
			del(u, v, 0);
	cnt[0]--;

	reverse(adj[v].begin(), adj[v].end());
	for (int u:adj[v])
		if (!blocked[u]) {
			get(u, v, 1<<conv(v));
			add(u, v, 0);
		}
	for (int u:adj[v])
		if (!blocked[u])
			del(u, v, 0);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	fill(ans, ans + n, 1);
	cin >> s;
	solve(0);
	for (int v = 0; v < n; v++)
		cout << ans[v] << " ";
	cout << "\n";
	return 0;
}