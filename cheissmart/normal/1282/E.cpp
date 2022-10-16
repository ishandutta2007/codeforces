#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 1e5 + 7;

vi exist[N], G[N], p;
bool vis[N];

void dfs(int u) {
	p.PB(u);
	vis[u] = 1;
	for(int v:G[u]) {
		if(!vis[v]) {
			dfs(v);
			break;
		}
	}
}

map<array<int, 3>, int> mp;

int ok(int i) { // we can cut i
	int l = G[i][0], r = G[i][1];
	array<int, 3> tt = {i, l, r};
	sort(ALL(tt));
	return mp[tt];
}

void solve() {
	int n;
	cin >> n;
	for(int i = 1; i <= n - 2; i++) {
		array<int, 3> t;
		cin >> t[0] >> t[1] >> t[2];
		sort(ALL(t));
		mp[t] = i;
		exist[t[0]].PB(t[1]);
		exist[t[0]].PB(t[2]);
		exist[t[1]].PB(t[0]);
		exist[t[1]].PB(t[2]);
		exist[t[2]].PB(t[0]);
		exist[t[2]].PB(t[1]);
	}
	for(int i = 1; i <= n; i++) {
		unordered_map<int, int> cnt;
		for(int e:exist[i]) cnt[e]++;
		for(pi p:cnt) if(p.S == 1) G[i].PB(p.F);
		assert(G[i].size() == 2);
	}
	dfs(1);
	for(int i:p) cout << i << " ";
	cout << endl;
	queue<int> q;
	for(int i = 1; i <= n ; i++) if(ok(i)) q.push(i);
	int cnt = 0;
	while(q.size()) {
		int cur = q.front(); q.pop();
		cout << ok(cur) << " ";
		cnt++;
		if(cnt == n - 2) break;
		int l1 = G[cur][0], r1 = G[cur][1];
		int l2 = G[l1][0] ^ G[l1][1] ^ cur;
		int r2 = G[r1][0] ^ G[r1][1] ^ cur;
		G[l1][0] = l2, G[l1][1] = r1;
		G[r1][0] = r2, G[r1][1] = l1;
		if(ok(l1)) q.push(l1);
		if(ok(r1)) q.push(r1);
	}
	cout << endl;
	for(int i = 1; i <= n; i++) {
		exist[i].clear();
		G[i].clear();
		vis[i] = 0;
	}
	p.clear();
	mp.clear();
}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	
}