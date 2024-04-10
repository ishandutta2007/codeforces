#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long mod = 1224736769;
long long N, t1[3009][3009], t2[3009][3009], sz1[3009], sz2[3009], power[3009], G1, G2, G3;
int cl[3009], cr[3009];
char c1[3009][3009], c2[3009][3009];

void init() {
	power[0] = 1;
	for (int i = 1; i <= 3000; i++) power[i] = (power[i - 1] * 311LL) % mod;
}

long long hash_value1(int m, int l, int r) {
	// [l, r]
	return (t1[m][r + 1] - t1[m][l] * power[r - l + 1] + mod * mod) % mod;
}

long long hash_value2(int m, int l, int r) {
	// [l, r]
	return (t2[m][r + 1] - t2[m][l] * power[r - l + 1] + mod * mod) % mod;
}

bool gosa_hosei(int p, int q) {
	long long V1 = -1, V2 = -1;
	for (int i = 0; i < N; i++) {
		if (hash_value1(i, 0, sz1[i] - 1) == hash_value2(i, 0, sz2[i] - 1)) continue;
		if (cl[i] - p < 0 || cr[i] + q >= sz1[i]) return false;

		long long T1 = hash_value1(i, cl[i] - p, cr[i] + q);
		long long T2 = hash_value2(i, cl[i] - p, cr[i] + q);
		if (V1 == -1LL && V2 == -1LL) { V1 = T1; V2 = T2; }
		else if (V1 != T1 || V2 != T2) return false;
		G3 = (cr[i] + q) - (cl[i] - p) + 1;
	}
	G1 = V1; G2 = V2;
	return true;
}

bool hantei(int lens, int p, int q) {
	for (int i = 0; i < N; i++) {
		bool J = false; if (hash_value1(i, 0, sz1[i] - 1) == hash_value2(i, 0, sz2[i] - 1)) J = true;
		bool J2 = false;

		for (int j = 0; j <= sz1[i] - lens; j++) {
			long long P1 = hash_value1(i, j, j + lens - 1);
			if (P1 == G1) {
				J2 = true;
				if (j < cl[i] - p) return false;
			}
		}
		if (J == J2) return false;
	}
	return true;
}

int main() {
	init();
	scanf("%lld", &N);
	for (int i = 0; i < N; i++) { scanf("%s", &c1[i]); for (int j = 0; j <= 3000; j++) { if (c1[i][j] == 0) break; sz1[i]++; t1[i][j + 1] += t1[i][j] * 311LL; t1[i][j + 1] += (long long)((c1[i][j] - 'a') + 1); t1[i][j + 1] %= mod; } }
	for (int i = 0; i < N; i++) { scanf("%s", &c2[i]); for (int j = 0; j <= 3000; j++) { if (c2[i][j] == 0) break; sz2[i]++; t2[i][j + 1] += t2[i][j] * 311LL; t2[i][j + 1] += (long long)((c2[i][j] - 'a') + 1); t2[i][j + 1] %= mod; } }

	for (int i = 0; i < N; i++) {
		cl[i] = (1 << 30); cr[i] = -(1 << 30);
		for (int j = 0; j < sz1[i]; j++) {
			if (c1[i][j] != c2[i][j]) { cl[i] = min(cl[i], j); cr[i] = max(cr[i], j); }
		}
	}

	bool I = gosa_hosei(0, 0);
	if (I == false) {
		cout << "NO" << endl;
		return 0;
	}
	int el = 0, er = 0;
	for (int i = 1; i <= N; i++) { if (gosa_hosei(i, 0) == false) break; el++; }
	for (int i = 1; i <= N; i++) { if (gosa_hosei(el, i) == false) break; er++; }
	gosa_hosei(el, er);

	bool R = hantei(G3, el, er);
	if (R == false) {
		cout << "NO" << endl;
		return 0;
	}
	else {
		cout << "YES" << endl;
		for (int i = 0; i < N; i++) {
			if (cl[i] > cr[i]) continue;
			for (int j = cl[i] - el; j <= cr[i] + er; j++) cout << c1[i][j]; cout << endl;
			for (int j = cl[i] - el; j <= cr[i] + er; j++) cout << c2[i][j]; cout << endl;
			return 0;
		}
	}
	return 0;
}