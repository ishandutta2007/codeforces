#include <iostream>
#include <algorithm>
using namespace std;

// 
long long INF = 2000000000000000000;
long long N, M, K;
string S;

// DP 
long long dp[2009], prev_[2009][2];
long long border[1 << 18];

// Trie 
int Vert = 0;
int nex[1000009][26];
int dpr[1000009];

void dfs(int pos) {
	dpr[pos] = 1;
	for (int i = 0; i < 26; i++) {
		if (nex[pos][i] == -1) continue;
		dfs(nex[pos][i]);
		dpr[pos] += dpr[nex[pos][i]];
	}
}

void init() {
	for (int i = 0; i < 1000000; i++) {
		for (int j = 0; j < 26; j++) nex[i][j] = -1;
	}
	Vert = 1;

	for (int i = 0; i < N; i++) {
		int cx = 0;
		for (int j = i; j < N; j++) {
			if (nex[cx][S[j] - 'a'] == -1) { nex[cx][S[j] - 'a'] = Vert; Vert++; }
			cx = nex[cx][S[j] - 'a'];
		}
	}
	
	dfs(0);
}

long long solve(string T) {
	for (int i = 0; i < S.size(); i++) {
		border[i] = i + T.size();
		if (i + T.size() > S.size()) border[i] = 100000;
		for (int j = i; j < min((int)S.size(), i + (int)T.size()); j++) {
			if (T[j - i] > S[j]) { border[i] = 100000; break; }
			if (T[j - i] < S[j]) { border[i] = j + 1; break; }
		}
	}

	for (int i = 0; i <= N; i++) { prev_[i][0] = 0; prev_[i][1] = 0; }
	prev_[N][0] = 1;
	for (int i = N - 1; i >= 0; i--) {
		prev_[i][0] += prev_[i + 1][0];
		prev_[i][1] += prev_[i + 1][1];
		if (prev_[i][0] >= INF) { prev_[i][0] -= INF; prev_[i][1] += 1; }
	}

	for (int t = 1; t <= M; t++) {
		for (int i = N - 1; i >= 0; i--) {
			if (border[i] == 100000) continue;
			long long sum1 = prev_[border[i]][1] - prev_[N + 1][1];
			long long sum0 = prev_[border[i]][0] - prev_[N + 1][0];
			if (sum0 < 0) { sum0 += INF; sum1 -= 1; }

			if (sum1 >= 1) { dp[i] = K + 1; }
			else { dp[i] = min(sum0, K + 1); }
		}
		for (int i = N; i >= 0; i--) {
			prev_[i][1] = 0;
			prev_[i][0] = dp[i];
			dp[i] = 0;
		}
		if (t != M) {
			for (int i = N - 1; i >= 0; i--) {
				prev_[i][0] += prev_[i + 1][0];
				prev_[i][1] += prev_[i + 1][1];
				if (prev_[i][0] >= INF) { prev_[i][0] -= INF; prev_[i][1] += 1; }
			}
		}
	}

	if (prev_[0][1] >= 1) return K + 1;
	return min(prev_[0][0], K + 1);
}

// 
string getval(int pos) {
	string cur = ""; int cx = 0;
	while (true) {
		if (cx >= 1) {
			if (pos == 0) return cur;
			pos--;
		}
		for (int i = 0; i < 26; i++) {
			if (nex[cx][i] == -1) continue;
			if (pos < dpr[nex[cx][i]]) {
				cur += ('a' + i);
				cx = nex[cx][i];
				break;
			}
			pos -= dpr[nex[cx][i]];
		}
	}
	return "";
}

int main() {
	cin >> N >> M >> K;
	cin >> S;

	init();

	int cl = 0, cr = Vert - 1, cm, minx = 0;
	for (int i = 0; i < 23; i++) {
		cm = (cl + cr) / 2;
		string B = getval(cm);
		long long eval = solve(B);
		if (eval < K) { cr = cm; }
		else { cl = cm; minx = max(minx, cm); }
	}

	string Answer = getval(minx);
	cout << Answer << endl;
	return 0;
}