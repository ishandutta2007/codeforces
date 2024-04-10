#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int N, M, Q;

vector<pii> qs[303][303];
vector<pii> qc[2020202];

int D[2020202];
int C;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int st[2020202];

int A[303][303];
vector<pair<int, pii> > co[2020202];

struct DSU {
	int p[90909];
	bool chk[303][303];
	int cnt;

	void init() {
		cnt = 0;
		for(int i = 1; i <= N * M; i++) {
			p[i] = i;
			chk[(i - 1) / M + 1][(i - 1) % M + 1] = false;
		}
	}

	int f(int a, int b) { return (a - 1) * M + b; }

	int par(int x) {
		if(x == p[x]) return x;
		return p[x] = par(p[x]);
	}

	void unite(int a, int b) {
		a = par(a); b = par(b);
		if(a == b) return;
		p[a] = b; cnt--;
	}

	void upd(int x, int y) {
		cnt++;
		chk[x][y] = true;

		int t = f(x, y);
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(nx < 1 || nx > N || ny < 1 || ny > M) continue;
			if(!chk[nx][ny]) continue;
			unite(t, f(nx, ny));
		}
	}
}dsu;

void add(int l, int r, int x) { /*printf("add %d %d %d\n", l, r, x);*/ D[l] += x; D[r + 1] -= x; }

int main() {
	scanf("%d%d%d", &N, &M, &Q);
	for(int i = 1; i <= Q; i++) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		qs[a][b].push_back({c, i});
		qc[c].push_back({a, b});
		if(!st[c]) st[c] = i;
		C = c;

		co[A[a][b]].push_back({i, {a, b}});
		A[a][b] = c;
	}

	// for(int i = 0; i <= C; i++) {
	// 	printf("%d\n", i);
	// 	for(auto j : co[i]) printf("%d %d %d\n", j.first, j.second.first, j.second.second);
	// }

	for(int i = 0; i <= C; i++) {
		// printf("****%d****\n", i);
		int ed = 0;

		if(i) {
			dsu.init();
			for(int j = 0; j < qc[i].size(); j++) {
				dsu.upd(qc[i][j].first, qc[i][j].second);
				add(st[i] + j, st[i] + j, dsu.cnt);
				ed = st[i] + j;
			}
		}

		reverse(co[i].begin(), co[i].end());

		dsu.init();

		for(int j = 1; j <= N; j++) for(int k = 1; k <= M; k++) if(A[j][k] == i) dsu.upd(j, k);

		int nq = Q;
		for(auto j : co[i]) {
			add(j.first, nq, dsu.cnt);
			dsu.upd(j.second.first, j.second.second);
			nq = j.first - 1;
		}

		if(i) add(ed + 1, nq, dsu.cnt);
	}

	for(int i = 1; i <= Q; i++) D[i] += D[i - 1];
	for(int i = 1; i <= Q; i++) printf("%d\n", D[i]);

	return 0;
}