#include <bits/stdc++.h>

using namespace std;

string S;
int C[26];
int n;

void filln() {
	int i, j;
	for (i = j = 0; i < 26; i++) {
		for (; C[i]; C[i]--) {
			for (; j < n && S[j] != '-'; j++);
			S[j] = i + 'a';
		}
	}
}

void tc() {
	int i, j, a, b, m;
	cin >> S;
	n = S.size();
	fill(C, C + 26, 0);
	for (char &c: S) C[c - 'a']++;
	for (i = 0, m = -1; i < 26; i++) {
		if (C[i] > 0) {
			if (m == -1 || C[i] < C[m]) m = i;
		}
	}
	for (i = 0; i < n; i++) S[i] = '-';

	if (C[m] != 1) {
		for (m = 0; m < 26; m++) if (C[m] > 0) break;
		if (C[m] + C[m] - 2 > n && C[m] != n) {
			for (a = m + 1; a < 26; a++) if (C[a] > 0) break;
			for (b = a + 1; b < 26; b++) if (C[b] > 0) break;
			S[0] = m + 'a'; S[1] = a + 'a'; C[m]--; C[a]--;
			if (b < 26) {
				for (j = 2; C[m]; C[m]--, j++) S[j] = m + 'a';
				S[j] = b + 'a'; C[b]--; j++;
			}
			else {
				for (j = 2; C[a]; C[a]--, j++) S[j] = a + 'a';
			}
			filln();
			cout << S << "\n";
			return;
		}
	}

	S[0] = m + 'a'; C[m]--;
	for (i = 1; C[m] && i < n; i += 2) {
		S[i] = m + 'a'; C[m]--;
	}
	filln();
	cout << S << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	cin >> t;

	for (; t--; ) {
		tc();
	}

	return 0;
}