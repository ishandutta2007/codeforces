#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const int BSZ = 200;
const ld NEGINF = -2e18;

ll A[202020];
ll B[202020];
ll tmp[202020];
int N, Q;

vector<int> adj[202020];
int dfn[202020];
int ed[202020];

int id;

vector<int> ord[2020];
pii P[202020];

ld leftx[202020][2];
vector<pii> stk[2020];
int X[2020];
int ptr[2020];

void dfs(int now, int par) {
	dfn[now] = ++id;
	for(int i : adj[now]) {
		if(i == par) continue;
		dfs(i, now);
	}
	ed[now] = id;
}

void calc_a(int now, int par, ll a) {
	A[now] = a + A[now];
	for(int i : adj[now]) {
		if(i == par) continue;
		calc_a(i, now, A[now]);
	}
}

void calc_b(int now, int par, ll b) {
	for(int i : adj[now]) {
		if(i == par) continue;
		calc_b(i, now, b + B[now]);
	}
	B[now] = abs(b + B[now]);
}

ld cross_x(int i, int ti, int j, int tj) {
	ll a1 = (ti ? B[i] : -B[i]);
	ll a2 = (tj ? B[j] : -B[j]);
	ll b1 = (ti ? A[i] * B[i] : -A[i] * B[i]);
	ll b2 = (tj ? A[j] * B[j] : -A[j] * B[j]);

	if(a1 == a2) {
		if(b1 <= b2) return NEGINF;
		return -NEGINF;
	}

	return (ld)(b2 - b1) / (a1 - a2);
}

void add_line(int block, int idx, int t) {
	while(stk[block].size()) {
		pii bk = stk[block].back();
		if(leftx[bk.first][bk.second] <= cross_x(bk.first, bk.second, idx, t)) break;
		stk[block].pop_back();
	}

	if(stk[block].size() && cross_x(stk[block].back().first, stk[block].back().second, idx, t) == -NEGINF) return;

	if(!stk[block].size()) leftx[idx][t] = NEGINF;
	else leftx[idx][t] = cross_x(stk[block].back().first, stk[block].back().second, idx, t);
	stk[block].push_back({idx, t});
}

void buildCHT(int b) {
	stk[b].clear();
	X[b] = 0;
	for(int i = (int)ord[b].size() - 1; i >= 0; i--) add_line(b, ord[b][i], 0);
	for(int i = 0; i < ord[b].size(); i++) add_line(b, ord[b][i], 1);
}

ll query(int b) {
	int sz = stk[b].size();
	// int l = 0, r = sz - 1;
	// while(l <= r) {
	// 	int m = l + r >> 1;
	// 	pii p = stk[b][m];
	// 	if(leftx[p.first][p.second] > X[b]) r = m - 1;
	// 	else l = m + 1;
	// }
	while(ptr[b] < sz) {
		pii p = stk[b][ptr[b]];
		if(leftx[p.first][p.second] > X[b]) break;
		ptr[b]++;
	}
	ptr[b]--;
	int ans = stk[b][ptr[b]].first;
	// printf("%d %d\n", ans, b);
	// printf("%lld %d %lld\n", A[ans], X[b], B[ans]);
	return abs((A[ans] + X[b]) * B[ans]);
}

void updb(int b) {
	for(int i = b * BSZ; i < (b + 1) * BSZ; i++) A[i] += X[b];
	X[b] = ptr[b] = 0;
}

int main() {
	scanf("%d%d", &N, &Q);
	for(int i = 2; i <= N; i++) {
		int x; scanf("%d", &x);
		adj[x].push_back(i);
		adj[i].push_back(x);
	}
	for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	for(int i = 1; i <= N; i++) scanf("%lld", &B[i]);

	dfs(1, 0);
	calc_a(1, 0, 0LL);
	calc_b(1, 0, 0LL);

	for(int i = 1; i <= N; i++) tmp[dfn[i]] = A[i];
	for(int i = 1; i <= N; i++) A[i] = tmp[i];
	for(int i = 1; i <= N; i++) tmp[dfn[i]] = B[i];
	for(int i = 1; i <= N; i++) B[i] = tmp[i];

	for(int i = 1; i <= N; i++) P[i] = {B[i], i};
	sort(P + 1, P + N + 1);

	for(int i = 1; i <= N; i++) ord[P[i].second / BSZ].push_back(P[i].second);

	for(int i = 0; i <= N / BSZ; i++) buildCHT(i);

	while(Q--) {
		int t; scanf("%d", &t);
		int v, l, r; scanf("%d", &v);
		l = dfn[v]; r = ed[v];

		if(t == 1) {
			int x; scanf("%d", &x);

			int lb = l / BSZ;
			updb(lb);
			for(int i = l; i < min((lb + 1) * BSZ, r + 1); i++) A[i] += x;
			buildCHT(lb);

			int rb = r / BSZ;
			updb(rb);
			if(lb != rb) for(int i = max(rb * BSZ, l); i <= r; i++) A[i] += x;
			buildCHT(rb);

			for(int i = lb + 1; i < rb; i++) X[i] += x;
		}
		else {
			ll ans = 0;
			int lb = l / BSZ, rb = r / BSZ;
			// updb(lb); updb(rb);
			// buildCHT(lb); buildCHT(rb);

			// for(int i = 0; i <= N; i++) printf("%d ", X[i]); puts("");

			// for(int i = 1; i <= N; i++) printf("%lld ", A[i]); puts("");
			// for(int i = 1; i <= N; i++) printf("%lld ", B[i]); puts("");

			for(int i = l; i < min(r + 1, (lb + 1) * BSZ); i++) ans = max(ans, abs((A[i] + X[lb]) * B[i]));
			for(int i = max(l, rb * BSZ); i <= r; i++) ans = max(ans, abs((A[i] + X[rb]) * B[i]));

			for(int i = lb + 1; i < rb; i++) ans = max(ans, query(i));
			printf("%lld\n", ans);
		}
		//for(int i = 0; i <= N; i++) printf("%d ", X[i]); puts("");
	}

	return 0;
}

/*
7 5
1 2 3 1 5 2
-8 2 1 1 -3 7 6
3 -2 9 3 1 3 -4
1 1 8
1 5 8
1 4 5
1 1 10
2 1
*/