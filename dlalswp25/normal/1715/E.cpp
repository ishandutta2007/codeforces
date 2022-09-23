#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const ll INF = 1LL << 60;

int N, M, K;
ll D[25][101010];
vector<pii> adj[101010];

struct Line {
	ll a, b;
	Line(ll _a = 0, ll _b = INF) : a(_a), b(_b) {}

	ll f(ll x) { return a * x + b; }
};

struct Node {
	Line line;
	int l, r;
};

struct LiChao {
	Node T[101010];
	int id;

	LiChao() : id(1) {}

	void init() {
		for(int i = 1; i <= id; i++) T[i] = Node();
		id = 1;
	}

	void upd(int idx, int s, int e, Line l) {
		Line lo = l, hi = T[idx].line;
		if(lo.f(s) > hi.f(s)) swap(lo, hi);
		if(lo.f(e) <= hi.f(e)) { T[idx].line = lo; return; }
		int m = s + e >> 1;
		if(lo.f(m) < hi.f(m)) {
			T[idx].line = lo;
			if(!T[idx].r) T[idx].r = ++id;
			upd(T[idx].r, m + 1, e, hi);
		}
		else {
			T[idx].line = hi;
			if(!T[idx].l) T[idx].l = ++id;
			upd(T[idx].l, s, m, lo);
		}
	}

	void add(Line line) { upd(1, 1, N, line); }

	ll get(int idx, int s, int e, int p) {
		if(!idx || p < s || e < p) return INF;
		if(s == e) return T[idx].line.f(p);
		int m = s + e >> 1;
		return min({T[idx].line.f(p), get(T[idx].l, s, m, p), get(T[idx].r, m + 1, e, p)});
	}

	ll query(ll x) { return get(1, 1, N, x); }
}cht;

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for(int i = 1; i <= M; i++) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
	}
	for(int i = 2; i <= N; i++) D[0][i] = INF;
	for(int k = 0; k <= K; k++) {
		if(k) {
			cht.init();
			for(int i = 1; i <= N; i++) {
				cht.add(Line(-2 * i, D[k - 1][i] + (ll)i * i));
			}
			for(int i = 1; i <= N; i++) {
				D[k][i] = min(D[k - 1][i], cht.query(i) + (ll)i * i);
			}
		}
		priority_queue<pli, vector<pli>, greater<pli>> pq;
		for(int i = 1; i <= N; i++) pq.emplace(D[k][i], i);
		while(pq.size()) {
			ll d; int x; tie(d, x) = pq.top();
			pq.pop();
			if(D[k][x] < d) continue;
			for(pii i : adj[x]) {
				if(D[k][i.first] > d + i.second) {
					D[k][i.first] = d + i.second;
					pq.emplace(D[k][i.first], i.first);
				}
			}
		}
	}
	for(int i = 1; i <= N; i++) printf("%lld ", D[K][i]); puts("");
	return 0;
}