#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string S; int A, B, P, dpl[10009][109], dpr[10009][109], c[10009], N = 1; vector<int>x[10009];

void parse(int pos, string V) {
	if (V.size() == 1) {
		c[pos] = (V[0] - '0');
		return;
	}
	V = V.substr(1, V.size() - 2);
	string V1, V2; int depth = 0;
	for (int i = 0; i < V.size(); i++) {
		if (V[i] == '(') depth++;
		if (V[i] == ')') depth--;
		if (V[i] == '?' && depth == 0) {
			V1 = V.substr(0, i);
			V2 = V.substr(i + 1, V.size() - (i + 1));
		}
	}
	int F1 = N, F2 = N + 1;
	x[pos].push_back(F1);
	x[pos].push_back(F2);
	N += 2;
	parse(F1, V1);
	parse(F2, V2);
}

int main() {
	cin >> S >> A >> B; P = min(A, B);
	parse(0, S);
	for (int i = 0; i <= N - 1; i++) {
		for (int j = 0; j <= P; j++) { dpl[i][j] = (1 << 29); dpr[i][j] = -(1 << 29); }
	}
	for (int i = N - 1; i >= 0; i--) {
		if (c[i] >= 1) { dpl[i][0] = c[i]; dpr[i][0] = c[i]; continue; }
		for (int j = 0; j <= P; j++) {
			for (int k = 0; k <= P; k++) {
				int K1 = 0, K2 = 0; if (P == A) K1 = 1; else K2 = 1;

				if (j + k + K1 <= P) {
					// 
					dpl[i][j + k + K1] = min(dpl[i][j + k + K1], dpl[x[i][0]][j] + dpl[x[i][1]][k]);
					dpr[i][j + k + K1] = max(dpr[i][j + k + K1], dpr[x[i][0]][j] + dpr[x[i][1]][k]);
				}
				if (j + k + K2 <= P) {
					// 
					dpl[i][j + k + K2] = min(dpl[i][j + k + K2], dpl[x[i][0]][j] - dpr[x[i][1]][k]);
					dpr[i][j + k + K2] = max(dpr[i][j + k + K2], dpr[x[i][0]][j] - dpl[x[i][1]][k]);
				}
			}
		}
	}
	cout << dpr[0][P] << endl;
	return 0;
}