#include <iostream>
#include <string>
using namespace std;
#pragma warning (disable: 4996)

string S, A, B, T, D; int K; char c1[1000009], c2[1000009], c3[1000009];

void dfs(int pos, int ty) {
	if (T.size() >= 1) return;

	bool v[26]; for (int i = 0; i < 26; i++) v[i] = false;
	for (int i = 0; i < K; i++) { if (D[i] != '?') v[D[i] - 'a'] = true; }

	if (ty == 0 || pos == S.size()) {
		// 
		int cnt = 0; T = D;
		for (int i = 0; i < K; i++) {
			if (v[i] == true) continue;
			while (T[cnt] != '?') cnt++;
			T[cnt] = ('a' + i);
		}
		return;
	}

	if (D[S[pos] - 'a'] != '?') {
		char L1 = 'a', R1 = ('a' + K - 1);
		if (ty == 1 || ty == 3) L1 = A[pos];
		if (ty == 2 || ty == 3) R1 = B[pos];

		if (L1 <= D[S[pos] - 'a'] && D[S[pos] - 'a'] <= R1) {
			int rem = 0;
			if (A[pos] == D[S[pos] - 'a'] && (ty == 1 || ty == 3)) rem += 1;
			if (B[pos] == D[S[pos] - 'a'] && (ty == 2 || ty == 3)) rem += 2;
			dfs(pos + 1, rem);
		}
	}
	else {
		char L1 = 'a', R1 = ('a' + K - 1);
		if (ty == 1 || ty == 3) L1 = A[pos];
		if (ty == 2 || ty == 3) R1 = B[pos];

		for (char i = L1; i <= R1; i++) {
			if (v[i - 'a'] == true) continue;

			D[S[pos] - 'a'] = i;

			int rem = 0;
			if (A[pos] == D[S[pos] - 'a'] && (ty == 1 || ty == 3)) rem += 1;
			if (B[pos] == D[S[pos] - 'a'] && (ty == 2 || ty == 3)) rem += 2;
			dfs(pos + 1, rem);

			D[S[pos] - 'a'] = '?';
		}
	}
}

int main() {
	int TT; scanf("%d", &TT);

	for (int i = 1; i <= TT; i++) {
		scanf("%d", &K); S = ""; A = ""; B = ""; T = "";
		scanf("%s", &c1); for (int j = 0; j < 1000009; j++) { if (c1[j] == 0) break; S += c1[j]; }
		scanf("%s", &c2); for (int j = 0; j < 1000009; j++) { if (c2[j] == 0) break; A += c2[j]; }
		scanf("%s", &c3); for (int j = 0; j < 1000009; j++) { if (c3[j] == 0) break; B += c3[j]; }

		D = "??????????????????????????";

		// Solve this problem
		dfs(0, 3);

		if (T.size() >= 1) {
			printf("YES\n");
			for (int j = 0; j < K; j++) printf("%c", T[j]); printf("\n");
		}
		else {
			printf("NO\n");
		}

		for (int j = 0; j <= S.size(); j++) { c1[j] = 0; c2[j] = 0; c3[j] = 0; }
	}
	return 0;
}