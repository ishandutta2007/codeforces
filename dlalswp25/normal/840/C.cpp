#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int N;
int A[303];
ll D[303][303];
int ncr[303][303];
ll F[303];

vector<int> v;

void init() {
	ncr[0][0] = 1;
	for(int i = 1; i <= 301; i++) {
		ncr[i][0] = ncr[i][i] = 1;
		for(int j = 1; j < i; j++) {
			ncr[i][j] = (ncr[i - 1][j] + ncr[i - 1][j - 1]) % MOD;
		}
	}

	F[0] = 1;
	for(int i = 1; i <= 301; i++) F[i] = F[i - 1] * i % MOD;
}

int main() {
	init();

	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

	for(int i = 1; i <= N; i++) {
		for(int j = 2; j * j <= A[i]; j++) {
			if(A[i] % (j * j) == 0) { A[i] /= (j * j); j--; }
		}
	}

	sort(A + 1, A + N + 1);
	v.push_back(1);
	for(int i = 2; i <= N; i++) {
		if(A[i] == A[i - 1]) { v.back()++; }
		else v.push_back(1);
	}

	int sz = v.size();

	D[0][v[0] - 1] = 1;
	int s = v[0];
	for(int i = 1; i < sz; i++) {
		for(int j = 1; j <= v[i]; j++) {
			for(int k = 0; k <= s - 1; k++) {
				for(int l = 0; l <= j; l++) {
					if(l > k || j - l > s - k + 1) continue;
					int idx = k - l + v[i] - j;
					//printf("%d %d %d %d %d\n", i, j, k, l, idx);
					D[i][idx] = (D[i][idx] + D[i - 1][k] * ncr[k][l] % MOD * ncr[s - k + 1][j - l] % MOD * ncr[v[i] - 1][j - 1] % MOD) % MOD;
				}
			}
		}
		s += v[i];
	}

	for(int i : v) {
		D[sz - 1][0] = D[sz - 1][0] * F[i] % MOD;
	}
	printf("%lld\n", D[sz - 1][0]);

	return 0;
}