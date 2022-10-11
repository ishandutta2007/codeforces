#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 32; i++) {
		if ((b / (1LL << i)) % 2 == 1) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}
long long Div(long long a, long long b, long long m) {
	return (a*modpow(b, m - 2, m)) % m;
}

long long dp[1000009], L, ret[1000009], mod = 998244353;
int H, W, a[1009][1009], sx, sy; vector<pair<int, int>>G;

int main() {
	cin >> H >> W;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) scanf("%d", &a[i][j]);
	}
	cin >> sx >> sy;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) G.push_back(make_pair(-a[i][j], -1LL * ((sx - i) * (sx - i) + (sy - j) * (sy - j))));
	}
	sort(G.begin(), G.end());
	int F = lower_bound(G.begin(), G.end(), make_pair(-a[sx][sy], 0)) - G.begin();

	for (int i = F; i < G.size(); i++) {
		L += dp[i]; L %= mod;
		int pos1 = lower_bound(G.begin(), G.end(), make_pair(G[i].first, 2000000000)) - G.begin();

		if (i == F) ret[i] = 1; else ret[i] = L;
		if (G.size() - pos1 >= 1) {
			dp[pos1] += Div(ret[i], (G.size() - pos1), mod);
			dp[pos1] %= mod;
		}
		if (G.size() - pos1 >= 1) ret[i] = Div(ret[i], G.size() - pos1, mod);
	}

	// -------------------  ----------------
	vector<tuple<int, int, int>>V;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (i == sx && j == sy) V.push_back(make_tuple(-a[i][j], 200000, 200000));
			else V.push_back(make_tuple(-a[i][j], i, j));
		}
	}
	sort(V.begin(), V.end());
	for (int i = 0; i < V.size(); i++) {
		if (get<1>(V[i]) == 200000) { get<1>(V[i]) = sx; get<2>(V[i]) = sy; }
	}

	long long BX0 = 0, BX1 = 0, BX2 = 0, BY0 = 0, BY1 = 0, BY2 = 0, cx = F, ans = 0;
	for (int i = F; i < V.size(); i++) {
		while (cx < V.size() && get<0>(V[i]) > get<0>(V[cx])) {
			BX0 += ret[cx]; BX1 += ret[cx] * get<1>(V[cx]); BX2 += ret[cx] * get<1>(V[cx]) * get<1>(V[cx]);
			BY0 += ret[cx]; BY1 += ret[cx] * get<2>(V[cx]); BY2 += ret[cx] * get<2>(V[cx]) * get<2>(V[cx]);
			BX0 %= mod; BX1 %= mod; BX2 %= mod;
			BY0 %= mod; BY1 %= mod; BY2 %= mod;
			cx++;
		}
		long long vx1 = BX2 - ((BX1 + (BX1 - 1LL * get<1>(V[i]) * BX0) + mod * mod) % mod) * get<1>(V[i]); vx1 += mod * mod; vx1 %= mod;
		long long vy1 = BY2 - ((BY1 + (BY1 - 1LL * get<2>(V[i]) * BY0) + mod * mod) % mod) * get<2>(V[i]); vy1 += mod * mod; vy1 %= mod;
		ans += vx1 + vy1; ans %= mod;
	}
	cout << ans << endl;
	return 0;
}