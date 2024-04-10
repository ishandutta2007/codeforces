#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, ll> pii;

const ll INF = (1ll) << 62;

vector<pii> adj[505050];
int deg[505050];

bool chk[505050];
int up[505050];
int sz[505050];
ll W[505050];
ll Z[505050];

vector<int> lf[505050];

vector<ll> T[505050];
int bas[505050];

int st[505050];

//ll sm[20][505050];
int dep[505050];

int N, Q;
int id = 1;

vector<int> tmp;
vector<pii> ups[505050];

void update(int t, int p, ll x) {
	int now = bas[t] + p;
	T[t][now] = x; now >>= 1;
	while(now) {
		T[t][now] = min(T[t][now * 2], T[t][now * 2 + 1]);
		now >>= 1;
	}
}

ll get(int t, int p, int q) {
	int l = bas[t] + p;
	int r = bas[t] + q;
	ll ret = INF;
	while(l <= r) {
		if(l & 1) { ret = min(ret, T[t][l]); l++; }
		if(!(r & 1)) { ret = min(ret, T[t][r]); r--; }
		l >>= 1; r >>= 1;
	}
	return ret;
}

void init(int now, int par) {
	for(pii i : adj[now]) {
		if(i.first == par) continue;
		//sm[0][i.first] = i.second;
		Z[i.first] = Z[now] + i.second;
		init(i.first, now);
	}
}

void dfs(int now, int par) {
	sz[now] = 1;
	if(deg[now] == 1) tmp.push_back(now);
	for(auto i : adj[now]) {
		if(i.first == par) continue;
		if(chk[i.first]) continue;
		dfs(i.first, now);
		sz[now] += sz[i.first];
	}
}

void dfs2(int rt, int now, int par) {
	ups[now].push_back({rt, W[now]});
	for(auto i : adj[now]) {
		if(i.first == par) continue;
		if(chk[i.first]) continue;
		W[i.first] = W[now] + i.second;
		dfs2(rt, i.first, now);
	}
}

void solve(int now, int par) {
	dfs(now, 0);
	int cen = now, bef = 0;
	while(1) {
		bool fg = false;
		for(auto i : adj[cen]) {
			if(i.first == bef) continue;
			if(chk[i.first]) continue;
			if(sz[i.first] * 2 > sz[now]) {
				fg = true;
				bef = cen; cen = i.first; break;
			}
		}
		if(!fg) break;
	}
	up[cen] = par;

	while(tmp.size()) {
		lf[cen].push_back(tmp.back());
		tmp.pop_back();
	}
	sort(lf[cen].begin(), lf[cen].end());

	for(int i = 0; i <= 19; i++) {
		bas[cen] = (1 << i);
		if((1 << i) >= lf[cen].size()) break;
	}
	T[cen].resize(bas[cen] * 2);
	//for(int i = 0; i < T[cen].size(); i++) T[cen][i] = INF;

	W[cen] = 0;
	dfs2(cen, cen, 0);

	for(int i = 0; i < lf[cen].size(); i++) {
		//update(1, 1, 1000000, id, dist(cen, i));
		update(cen, i, W[lf[cen][i]]);
		id++;
	}

	chk[cen] = true;
	for(auto i : adj[cen]) {
		if(chk[i.first]) continue;
		solve(i.first, cen);
	}
}

ll query(int v, int l, int r) {
	auto itl = lower_bound(lf[v].begin(), lf[v].end(), l);
	if(itl == lf[v].end()) return INF;
	auto itr = upper_bound(lf[v].begin(), lf[v].end(), r);
	if(itr == lf[v].begin()) return INF;
	itr--;
	//printf("q %d %d\n", st[v] + (itl - lf[v].begin()), st[v] + (itr - lf[v].begin()));
	//return get(1, 1, 1000000, st[v] + (itl - lf[v].begin()), st[v] + (itr - lf[v].begin()));
	return get(v, itl - lf[v].begin(), itr - lf[v].begin());
}

int main() {
	//for(int i = 0; i < 4 * 10101010; i++) T[i] = INF;
	scanf("%d%d", &N, &Q);
	//srand((int)time(NULL));

	for(int i = 2; i <= N; i++) {
		int x, w; scanf("%d%d", &x, &w);
		adj[i].push_back({x, w}); adj[x].push_back({i, w});
		deg[i]++; deg[x]++;
	}
	init(1, 0);

	solve(1, 0);

	//for(int i = 1; i <= N; i++) printf("%d ", up[i]); puts("");

	while(Q--) {
		int v, l, r; scanf("%d%d%d", &v, &l, &r);
		int x = v;

		ll ans = INF;
		for(pii i : ups[v]) {
			ans = min(ans, i.second + query(i.first, l, r));
		}
		printf("%lld\n", ans);
	}

	return 0;
}