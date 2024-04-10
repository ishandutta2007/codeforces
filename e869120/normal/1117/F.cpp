#include <bits/stdc++.h>
using namespace std;

string S;
int N, K, A[1 << 17], P[19][19], c[19][1 << 17], pp[1 << 17], dp[1 << 17];
bool r[19][19][1 << 17], rem[1 << 17];

int main() {
	cin >> N >> K >> S;
	for (int i = 1; i <= N; i++) { A[i] = (S[i - 1] - 'a'); c[A[i]][i]++; }
	for (int i = 0; i < K; i++) {
		for (int j = 1; j <= N; j++) c[i][j] += c[i][j - 1];
	}
	for (int i = 0; i < K; i++) { for (int j = 0; j < K; j++) cin >> P[i][j]; }
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < K; j++) {
			if (P[i][j] == 1) continue;
			int pres = -1;
			for (int k = 1; k <= N; k++) {
				if (A[k] == j && pres != -1) {
					int sums = 0;
					for (int l = 0; l < K; l++) {
						int G = c[l][k - 1] - c[l][pres];
						if (G >= 1) sums += (1 << l);
					}
					//cout << i << " " << j << " " << pres << " " << k << " " << sums << endl;
					r[i][j][sums] = true;
				}
				if (A[k] == i) pres = k;
			}
			int cnt1 = 0;
			for (int k = 0; k < (1 << K); k++) {
				if ((k & (1 << i)) == 0 && (k & (1 << j)) == 0) { pp[cnt1] = k; cnt1++; }
			}
			for (int k = 0; k < K; k++) {
				if (k == i || k == j) continue;
				int s = (1 << k);
				for (int l = 0; l < cnt1; l++) {
					if (r[i][j][pp[l]] == true) r[i][j][pp[l] | s] = true;
				}
			}
			for (int k = 0; k < cnt1; k++) {
				if (r[i][j][pp[k]] == true) rem[pp[k]] = true;
			}
		}
	}
	
	dp[0] = 1; int minx = (1 << 30);
	for (int i = 0; i < (1 << K); i++) {
		if (dp[i] == 0) continue;
		int res = 0;
		for (int j = 0; j < K; j++) {
			if ((i / (1 << j)) % 2 == 0) res += c[j][N];
		}
		minx = min(minx, res);
		for (int j = 0; j < K; j++) {
			if ((i / (1 << j)) % 2 == 1) continue;
			if (rem[i + (1 << j)] == false) dp[i + (1 << j)] = 1;
		}
	}
	cout << minx << endl;
	return 0;
}