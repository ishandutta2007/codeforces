#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, Q, p[4096], f[4096][4096], w[12]; string S[500009]; vector<pair<int, int>>Z;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	cin >> N >> M >> Q;
	for (int i = 0; i < N; i++) cin >> w[i];
	for (int i = 0; i < M; i++) {
		cin >> S[i]; int r = 0;
		for (int j = 0; j < S[i].size(); j++) { if (S[i][j] == '1') r += (1 << j); }
		p[r]++;
	}
	for (int i = 0; i < (1 << N); i++) {
		int ret = 0;
		for (int j = 0; j < N; j++) { if ((i / (1 << j)) % 2 == 1) ret += w[j]; }
		Z.push_back(make_pair(ret, i));
	}
	sort(Z.begin(), Z.end());
	for (int i = 0; i < (1 << N); i++) {
		for (int j = 0; j < (1 << N); j++) { f[i][j] = p[i^Z[j].second]; if (j >= 1) f[i][j] += f[i][j - 1]; }
	}
	for (int i = 0; i < Q; i++) {
		string V; int L; cin >> V >> L;
		int r = 0; for (int j = 0; j < N; j++) { if (V[j] == '1') r += (1 << j); }
		r ^= (1 << N) - 1;

		int pos1 = upper_bound(Z.begin(), Z.end(), make_pair(L, 10000000)) - Z.begin(); pos1--;
		if (pos1 < 0) printf("0\n");
		else printf("%d\n", f[r][pos1]);
	}
	return 0;
}