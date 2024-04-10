#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, M, K;

vector<int> adj[505050];
int C[505050];
int B[505050];
int com[505050];

map<pii, int> mp;
pii E[505050];
int id, cid;

vector<pii> v[505050];
bool vst[505050];

bool ok[505050];
vector<int> cs[505050];

int chk[505050];

struct DSU {
	int p[1010101];
	vector<int> v;

	DSU() {
		for(int i = 1; i <= 1000000; i++) p[i] = i;
	}

	void init() {
		for(int i : v) p[i] = i;
		v.clear();
	}

	int par(int x) {
		if(x == p[x]) return x;
		return p[x] = par(p[x]);
	}

	void unite(int a, int b) {
		// printf("unite %d %d\n", a, b);
		a = par(a); b = par(b);
		if(a != b) {
			p[a] = b;
			v.push_back(a);
		}
	}
}uf;

void dfs(int x) {
	vst[x] = true;
	for(int i : adj[x]) {
		if(C[i] != C[x]) continue;
		if(vst[i]) {
			if(B[i] == B[x]) ok[C[x]] = false;
			continue;
		}
		B[i] = B[x] ^ 1;
		com[i] = com[x];
		dfs(i);
	}
}

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for(int i = 1; i <= N; i++) scanf("%d", &C[i]);
	for(int i = 1; i <= M; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
		int ca = C[a], cb = C[b];
		if(ca > cb) swap(ca, cb);
		if(ca != cb) {
			int t;
			auto it = mp.find(pii(ca, cb));
			if(it == mp.end()) {
				t = ++id;
				mp[pii(ca, cb)] = t;
				E[t] = {ca, cb};
			}
			else t = it -> second;

			v[t].emplace_back(a, b);
		}
	}

	for(int i = 1; i <= K; i++) ok[i] = true;

	for(int i = 1; i <= N; i++) {
		if(!vst[i]) {
			com[i] = ++cid;
			cs[C[i]].push_back(cid);
			dfs(i);
		}
	}

	int cnt = K;
	for(int i = 1; i <= K; i++) if(!ok[i]) cnt--;

	// for(int i = 1; i <= N; i++) printf("%d ", com[i]); puts("");
	// for(int i = 1; i <= K; i++) printf("%d ", ok[i]); puts("");

	ll ans = (ll)cnt * (cnt - 1) / 2;

	for(int i = 1; i <= id; i++) {
		int ca = E[i].first, cb = E[i].second;
		if(!ok[ca] || !ok[cb]) continue;

		uf.init();

		for(pii j : v[i]) {
			int c1 = com[j.first], c2 = com[j.second];
			// printf("%d %d\n", j.first, j.second);
			if(B[j.first] == B[j.second]) {
				uf.unite(2 * c1 - 1, 2 * c2);
				uf.unite(2 * c1, 2 * c2 - 1);
			}
			else {
				uf.unite(2 * c1, 2 * c2);
				uf.unite(2 * c1 - 1, 2 * c2 - 1);
			}
		}

		bool pos = true;
		for(int j : cs[ca]) {
			if(uf.par(2 * j - 1) == uf.par(2 * j)) pos = false;
		}
		for(int j : cs[cb]) {
			if(uf.par(2 * j - 1) == uf.par(2 * j)) pos = false;
		}

		if(!pos) ans--;
	}

	printf("%lld\n", ans);

	return 0;
}