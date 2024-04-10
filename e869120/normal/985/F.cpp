#include <iostream>
#include <string>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

long long N, Q, p[26][200009], power[200009], inv[200009], mod = 1000000007LL; string S;

vector<long long>hash_val(int L, int R) {
	// [L, R) in 0-index
	vector<long long>X;
	for (int i = 0; i < 26; i++) {
		long long G = (p[i][R] - p[i][L] * power[R - L] + mod*mod) % mod;
		X.push_back(G);
	}
	return X;
}

int main() {
	cin >> N >> Q >> S;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < N; j++) {
			p[i][j + 1] = p[i][j] * 3;
			if (S[j] == ('a' + i)) p[i][j + 1] += 2; else p[i][j + 1] += 1;
			p[i][j + 1] %= mod;
		}
	}
	power[0] = 1; for (int i = 1; i <= 200000; i++) power[i] = (power[i - 1] * 3LL) % mod;
	inv[1] = 1; for (int i = 2; i <= 200001; i++) inv[i] = (inv[i - 1] + power[i - 1]) % mod;

	for (int i = 1; i <= Q; i++) {
		long long x, y, len; scanf("%lld%lld%lld", &x, &y, &len);
		vector<long long>S = hash_val(x - 1, x + len - 1);
		vector<long long>T = hash_val(y - 1, y + len - 1);

		bool OK = true;
		for (int j = 0; j < S.size(); j++) {
			int cnt = 0; for (int k = 0; k < T.size(); k++) { if (S[j] == T[k]) cnt++; }
			if (cnt != 1 && S[j] != inv[len]) OK = false;
		}
		for (int j = 0; j < T.size(); j++) {
			int cnt = 0; for (int k = 0; k < S.size(); k++) { if (T[j] == S[k]) cnt++; }
			if (cnt != 1 && T[j] != inv[len]) OK = false;
		}
		if (OK == true) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}