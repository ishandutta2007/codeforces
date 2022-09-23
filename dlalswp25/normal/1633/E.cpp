#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, M, Q;
int U[303];
int V[303];
int W[303];
int A, B, C, P;
int qs[101010];
vector<int> edges[101010];

vector<int> xs;

struct DSU {
	int N;
	int p[55];

	void init(int _N) {
		N = _N;
		for(int i = 1; i <= N; i++) p[i] = i;
	}

	int par(int x) {
		if(x == p[x]) return x;
		return p[x] = par(p[x]);
	}

	bool unite(int a, int b) {
		a = par(a); b = par(b);
		if(a == b) return false;
		p[a] = b;
		return true;
	}
}uf;

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= M; i++) {
		scanf("%d%d%d", &U[i], &V[i], &W[i]);
		W[i] <<= 1;
	}
	scanf("%d%d%d%d%d", &P, &Q, &A, &B, &C);
	for(int i = 1; i <= P; i++) scanf("%d", &qs[i]);

	for(int i = 1; i <= M; i++) {
		for(int j = i + 1; j <= M; j++) {
			xs.push_back(W[i] + W[j] >> 1);
		}
	}

	xs.push_back(0);

	sort(xs.begin(), xs.end());
	xs.erase(unique(xs.begin(), xs.end()), xs.end());

	for(int i = 0; i < xs.size(); i++) {
		int x = xs[i];
		vector<pair<pii, int>> es;
		for(int j = 1; j <= M; j++) {
			if(W[j] >= x) es.emplace_back(pii(abs(W[j] - x), -1), j);
			else es.emplace_back(pii(abs(W[j] - x), 1), j);
		}
		sort(es.begin(), es.end());
		uf.init(N);
		for(auto& e : es) {
			int j = e.second;
			if(uf.unite(U[j], V[j])) edges[i].push_back(j);
		}
	}

	// for(int i = 0; i < xs.size(); i++) {
	// 	printf("x=%d\n", xs[i]);
	// 	for(int j : edges[i]) printf("%d ", j); puts("");
	// }

	ll ans = 0;
	int x;
	for(int i = 1; i <= Q; i++) {
		if(i <= P) x = qs[i];
		else x = ((ll)x * A + B) % C;
		int t = upper_bound(xs.begin(), xs.end(), x * 2) - xs.begin() - 1;
		ll cost = 0;
		for(int j : edges[t]) {
			cost += abs(W[j] - x * 2);
		}
		cost >>= 1;
		// printf("%d: %lld\n", x, cost);
		ans ^= cost;
	}
	printf("%lld\n", ans);

	return 0;
}