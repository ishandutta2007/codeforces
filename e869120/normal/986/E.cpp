#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

const int MAX_D = 10000009;

int N, A[1 << 17], B[1 << 17], C[1 << 17], dist[1 << 17], dp[1 << 17][22];
vector<int>G[1 << 17], primes, KAERIGAKE;
vector<pair<int, int>>I[1 << 17], J[MAX_D];

bool used[1 << 18]; int cl[1 << 18], cr[1 << 18], cnts;
int imps[509][100009], L[MAX_D], cntv;

void init() {
	for (int i = 2; i <= 4000; i++) {
		bool flag = true;
		for (int j = 2; j < i; j++) {
			if (i%j == 0) { flag = false; break; }
		}
		if (flag == true) primes.push_back(i);
	}
}

vector<pair<int, int>> brute_force(int pos) {
	vector<pair<int, int>>D;
	for (int i : primes) {
		if (i*i > pos) break;
		int cnts = 0;
		while (pos%i == 0) { cnts++; pos /= i; }
		if (cnts != 0) D.push_back(make_pair(i, cnts));
	}
	if (pos >= 2) D.push_back(make_pair(pos, 1));
	return D;
}

void dfs(int pos, int dep) {
	used[pos] = true; cnts++; cl[pos] = cnts; dist[pos] = dep; KAERIGAKE.push_back(pos);
	for (int i = 0; i < G[pos].size(); i++) {
		if (used[G[pos][i]] == true) continue;
		dp[G[pos][i]][0] = pos;
		dfs(G[pos][i], dep + 1);
	}
	cr[pos] = cnts;
}

int prevs(int u, int x) {
	for (int i = 21; i >= 0; i--) {
		if (x >= (1 << i)) { u = dp[u][i]; x -= (1 << i); }
	}
	return u;
}

int lca(int u, int v) {
	if (dist[u] > dist[v]) swap(u, v);
	v = prevs(v, dist[v] - dist[u]);

	if (u == v) return u;

	for (int i = 21; i >= 0; i--) {
		if (dp[u][i] != dp[v][i]) { u = dp[u][i]; v = dp[v][i]; }
	}
	return dp[u][0];
}

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 31; i++) {
		if ((b&(1 << i)) != 0) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}

long long query(int u, int v, int x) {
	vector<pair<int, int>> T = brute_force(x);

	long long ans = 1, mod = 1000000007;
	for (int i = 0; i < T.size(); i++) {
		if (L[T[i].first] == 0) {
			int pos = T[i].first, lcas = lca(u, v), rem = 0;
			for (pair<int, int>r : J[pos]) {
				bool flag1 = false;
				if (cl[lcas] <= cl[r.first] && cl[r.first] <= cl[u] && cr[u] <= cr[r.first] && cr[r.first] <= cr[lcas]) flag1 = true;
				if (cl[lcas] <= cl[r.first] && cl[r.first] <= cl[v] && cr[v] <= cr[r.first] && cr[r.first] <= cr[lcas]) flag1 = true;
				if (flag1 == true) rem += min(T[i].second, r.second);
			}
			ans *= modpow(pos, rem, mod);
			ans %= mod;
		}
		else {
			int pos = T[i].first, lcas = lca(u, v), num = L[pos] + T[i].second - 1;
			int rem = imps[num][u] + imps[num][v] - imps[num][lcas] - imps[num][dp[lcas][0]];
			ans *= modpow(pos, rem, mod);
			ans %= mod;
		}
	}
	return ans;
}

int main() {
	scanf("%d", &N); init();
	for (int i = 1; i <= N - 1; i++) {
		scanf("%d%d", &A[i], &B[i]);
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}
	for (int i = 1; i <= N; i++) {
		scanf("%d", &C[i]);
		I[i] = brute_force(C[i]);
		for (int j = 0; j < I[i].size(); j++) {
			J[I[i][j].first].push_back(make_pair(i, I[i][j].second));
		}
	}

	dfs(1, 0);

	for (int i = 0; i < 21; i++) {
		for (int j = 1; j <= N; j++) dp[j][i + 1] = dp[dp[j][i]][i];
	}

	cntv = 1;
	for (int i = 2; i <= MAX_D; i++) {
		if (J[i].size() >= 600) {
			L[i] = cntv; long long s = i; int p = 0;
			while (s <= 10000000LL) {
				p++;
				for (int j = 0; j < J[i].size(); j++) imps[cntv][J[i][j].first] = min(p, J[i][j].second);
				for (int j : KAERIGAKE) {
					if (j != 1) imps[cntv][j] += imps[cntv][dp[j][0]];
				}
				s *= 1LL * i; cntv++;
			}
		}
	}

	int Q;
	scanf("%d", &Q);

	for (int i = 1; i <= Q; i++) {
		int u, v, x; scanf("%d%d%d", &u, &v, &x);
		printf("%d\n", query(u, v, x));
	}
	return 0;
}