#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

const long long mod = 2147483647;

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 31; i++) {
		if ((b / (1LL << i)) % 2 == 1) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}

long long Div(long long a, long long b, long long m) {
	return (a * modpow(b, m - 2, m)) % m;
}

int H, W, N, cc[256]; char c[255][255];
pair<int, int> hash_val[255][255][255]; int hush[255][255];

long long cl[255], cr[255], power[255], inv[255], inv2[255];
bool EE[1 << 26];

void init() {
	cc[1] = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = (1 << i); j < (2 << i); j++) cc[j] = i;
	}
	power[0] = 1LL; for (int i = 1; i <= 254; i++) power[i] = power[i - 1] * 1000000009LL % mod;
	for (int i = 0; i <= 254; i++) inv[i] = Div(1, power[i], mod);
	inv2[0] = 1LL; for (int i = 1; i <= 254; i++) inv2[i] = 3767363990679839801LL * inv2[i - 1];

	EE[0] = true;
	for (int i = 0; i < 26; i++) EE[(1 << i)] = true;
}

long long hash_val1(long long pl, long long pr) {
	if (pl <= 0 || pr > N) return (1LL << 60);
	return (cl[pr] - cl[pl - 1]) * inv2[pl - 1];
}

long long hash_val2(long long pl, long long pr) {
	if (pl <= 0 || pr > N) return (1LL << 61);
	return (cr[pl] - cr[pr + 1]) * inv2[N - pr];
}

long long solve(vector<long long> D) {
	N = D.size();
	cl[0] = 0; long long S1 = 1;
	for (int i = 0; i < D.size(); i++) {
		cl[i + 1] = cl[i];
		cl[i + 1] += S1 * D[i];
		S1 *= 1000000009LL;
	}
	cr[N + 1] = 0; long long S2 = 1;
	for (int i = D.size() - 1; i >= 0; i--) {
		cr[i + 1] = cr[i + 2];
		cr[i + 1] += S2 * D[i];
		S2 *= 1000000009LL;
	}

	// 
	long long sum = 0;
	for (int i = 1; i <= N - 1; i++) {
		long long cx = 0, maxn = 0, E = min(i, N + 1 - i);
		for (int j = cc[E]; j >= 0; j--) {
			long long M = cx + (1 << j);
			long long v1 = hash_val1(i - M + 1, i);
			long long v2 = hash_val2(i + 1, i + M);
			if (v1 == v2) { maxn = max(maxn, M); cx = M; }
		}
		sum += maxn;
	}

	// 
	for (int i = 1; i <= N; i++) {
		long long cx = 0, maxn = 0, E = min(i, N + 1 - i);
		for (int j = cc[E]; j >= 0; j--) {
			long long M = cx + (1 << j);
			long long v1 = hash_val1(i - M, i - 1);
			long long v2 = hash_val2(i + 1, i + M);
			if (v1 == v2) { maxn = max(maxn, M); cx = M; }
		}
		sum += maxn + 1;
	}
	return sum;
}

int main() {
	cin >> H >> W; init();
	for (int i = 0; i < H; i++) {
		scanf("%s", &c[i]);

		for (int j = 0; j < W; j++) {
			long long V = 0; int cu = 0;
			for (int k = j; k < W; k++) {
				V += power[c[i][k] - 'a']; V %= mod; cu ^= (1 << (int)(c[i][k] - 'a'));
				if (EE[cu] == true) {
					hash_val[j][k][hush[j][k]] = make_pair(V, i);
					hush[j][k]++;
				}
			}
		}
	}
	long long sum = 0;
	for (int i = 0; i < W; i++) {
		for (int j = i; j < W; j++) {
			vector<long long>D;
			for (int k = 0; k < hush[i][j]; k++) {
				D.push_back(hash_val[i][j][k].first);
				if (k == hush[i][j] - 1 || hash_val[i][j][k].second + 1 != hash_val[i][j][k + 1].second) {
					long long G = solve(D);
					sum += G;
					D.clear();
				}
			}
		}
	}
	cout << sum << endl;
	return 0;
}