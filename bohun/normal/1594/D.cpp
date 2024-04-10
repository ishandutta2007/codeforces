#include<bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (b); i >= (a); i--)
#define FOR(i, n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

const int N = 500500;
int n, m, p[N], siz[N], vis[N], par[N], cnt[2];
vector<int> e[N];

int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
	siz[b] += siz[a];
	p[a] = b;
    }
}

void dfs(int u) {
    vis[u] = 1;
    cnt[par[u]] += siz[u];
    for (auto v : e[u])
	if (!vis[v]) {
	    par[v] = par[u] ^ 1;
	    dfs(v);
	}
}

void solve() {
    cin >> n >> m;
    rep(i, 1, n) {
	e[i].clear();
	p[i] = i;
	siz[i] = 1;
	vis[i] = 0;
    }
    vector<pair<int, int>> ed;
    while (m--) {
	int a, b; string s;
	cin >> a >> b >> s;
	if (s[0] == 'c') 
	    merge(a, b);
	else
	    ed.emplace_back(a, b);
    }
    for (auto &[a, b] : ed) {
	a = find(a);
	b = find(b);
	e[a].push_back(b);
	e[b].push_back(a);
    }
    int res = 0;
    rep(i, 1, n)
	if (p[i] == i && !vis[i]) {
	    cnt[0] = cnt[1] = 0;
	    dfs(i);
	    res += max(cnt[0], cnt[1]);
	}
    rep(i, 1, n)
	for (auto j : e[i])
	    if (par[i] == par[j]) {
		cout << "-1\n";
		return;
	    }
    cout << res << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
	solve();

    return 0;
}