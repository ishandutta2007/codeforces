#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pp;

const int MXF = 20;
const ll MOD = 998244353;

int D[202020][25];
int E[202020][2];

vector<int> adj[202020];
vector<int> rev[202020];

int N, M;
int A[202020];
int B[202020];

int F[202020][2];
int cid;

priority_queue<pp, vector<pp>, greater<pp> > pq;
deque<pii> dq;
queue<pii> q;

void bfs() {
	F[1][0] = 0;
	F[1][1] = 1;
	dq.emplace_back(1, 0);
	dq.emplace_back(1, 1);
	for(int i = 2; i <= N; i++) F[i][0] = F[i][1] = MOD;

	while(dq.size()) {
		int x = dq.front().first;
		int f = dq.front().second;
		dq.pop_front();

		if(F[x][f ^ 1] > F[x][f] + 1) {
			F[x][f ^ 1] = F[x][f] + 1;
			dq.emplace_back(x, f ^ 1);
		}

		if(f & 1) {
			for(int i : rev[x]) {
				if(F[i][f] > F[x][f]) {
					F[i][f] = F[x][f];
					dq.emplace_front(i, f);
				}
			}
		}
		else {
			for(int i : adj[x]) {
				if(F[i][f] > F[x][f]) {
					F[i][f] = F[x][f];
					dq.emplace_front(i, f);
				}
			}
		}
	}
}

void dijkstra() {
	pq.emplace(0, pii(1, 0));
	for(int i = 1; i <= N; i++) for(int j = 0; j <= MXF; j++) D[i][j] = MOD;
	D[1][0] = 0;

	while(pq.size()) {
		int x = pq.top().second.first;
		int f = pq.top().second.second;
		int d = pq.top().first;
		pq.pop();

		// printf("%d %d %d\n", x, f, d);

		if(D[x][f] < d) continue;

		if(f & 1) {
			for(int i : rev[x]) {
				if(D[i][f] > D[x][f] + 1) {
					D[i][f] = D[x][f] + 1;
					pq.emplace(D[i][f], pii(i, f));
				}
			}
			if(f < MXF) {
				for(int i : adj[x]) {
					if(D[i][f + 1] > D[x][f] + 1 + (1 << f)) {
						D[i][f + 1] = D[x][f] + 1 + (1 << f);
						pq.emplace(D[i][f + 1], pii(i, f + 1));
					}
				}
			}
		}
		else {
			for(int i : adj[x]) {
				if(D[i][f] > D[x][f] + 1) {
					D[i][f] = D[x][f] + 1;
					pq.emplace(D[i][f], pii(i, f));
				}
			}
			if(f < MXF) {
				for(int i : rev[x]) {
					if(D[i][f + 1] > D[x][f] + 1 + (1 << f)) {
						D[i][f + 1] = D[x][f] + 1 + (1 << f);
						pq.emplace(D[i][f + 1], pii(i, f + 1));
					}
				}
			}
		}
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= M; i++) {
		scanf("%d%d", &A[i], &B[i]);
		adj[A[i]].push_back(B[i]);
		rev[B[i]].push_back(A[i]);
	}

	bfs();
	dijkstra();

	// for(int i = 1; i <= N; i++) printf("%d %d\n", F[i][0], F[i][1]);

	ll ans = MOD;
	for(int i = 0; i <= MXF; i++) ans = min(ans, (ll)D[N][i]);
	if(ans < MOD) {
		printf("%lld\n", ans);
		return 0;
	}

	for(int i = 1; i <= N; i++) E[i][0] = E[i][1] = MOD;
	E[1][0] = 0;

	dq.emplace_back(1, 0);
	while(dq.size()) {
		int x = dq.front().first;
		int f = dq.front().second;
		dq.pop_front();

		if(F[x][f ^ 1] == F[x][f] + 1 && E[x][f ^ 1] > E[x][f]) {
			E[x][f ^ 1] = E[x][f];
			dq.emplace_front(x, f ^ 1);
		}

		if(f & 1) {
			for(int i : rev[x]) {
				if(F[i][f] == F[x][f] && E[i][f] > E[x][f]) {
					E[i][f] = E[x][f] + 1;
					dq.emplace_back(i, f);
				}
			}
		}
		else {
			for(int i : adj[x]) {
				if(F[i][f] == F[x][f] && E[i][f] > E[x][f]) {
					E[i][f] = E[x][f] + 1;
					dq.emplace_back(i, f);
				}
			}
		}
	}

	if(F[N][0] < F[N][1]) ans = E[N][0];
	else if(F[N][0] > F[N][1]) ans = E[N][1];
	else ans = min(E[N][0], E[N][1]);

	ll t = 1;
	for(int i = 1; i <= min(F[N][0], F[N][1]); i++) t = t * 2 % MOD;
	printf("%lld\n", (ans + t + MOD - 1) % MOD);

	return 0;
}