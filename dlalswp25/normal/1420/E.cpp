#include <bits/stdc++.h>

using namespace std;

const int INF = 10101010;

int N, M;
int B[85];
int D[85][2020][165];
vector<int> v;
int A[85];
int R[85];
int ans[5050];

int f(int n, int lft, int bef) {
	if(n == M) {
		if(A[M] + bef < 0) return INF;
		return (A[M] + bef) * (A[M] + bef);
	}
	int& ret = D[n][lft][bef + 80];
	if(ret != -1) return ret;

	ret = INF;
	if(A[n] + bef >= 0) {
		for(int i = 0; i <= min(A[n] + bef, lft); i++) {
			ret = min(ret, (A[n] + bef - i) * (A[n] + bef - i) + f(n + 1, lft - i, i));
		}
	}
	for(int i = max(0, -(A[n] + bef)); i <= min(R[n], lft); i++) {
		ret = min(ret, (A[n] + bef + i) * (A[n] + bef + i) + f(n + 1, lft - i, -i));
	}
	// printf("%d %d %d %d\n", n, lft, bef, ret);
	return ret;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &B[i]);
	int c = 0;

	int no = 0;
	for(int i = 1; i <= N; i++) {
		if(B[i]) { v.push_back(c); c = 0; }
		else { c++; no++; }
	}
	v.push_back(c);
	M = v.size();
	for(int i = 1; i <= M; i++) A[i] = v[i - 1];
	for(int i = M; i >= 1; i--) R[i] = R[i + 1] + A[i + 1];

	int add = no * no;
	for(int i = 0; i < 85; i++) for(int j = 0; j < 2020; j++) for(int k = 0; k < 165; k++) D[i][j][k] = -1;

	// for(int i = 1; i <= M; i++) printf("%d ", A[i]); puts("");

	int mn = (no / M + 1) * (no / M + 1) * (no % M) + (no / M) * (no / M) * (M - no % M);
	for(int k = 0; k <= N * (N - 1) / 2; k++) {
		ans[k] = f(1, k, 0);
		if(ans[k] == mn) {
			for(int i = k + 1; i <= N * (N - 1) / 2; i++) ans[i] = ans[k];
			break;
		}
	}
	// for(int i = 0; i <= N * (N - 1) / 2; i++) printf("%d ", ans[i]); puts("");
	for(int i = 0; i <= N * (N - 1) / 2; i++) printf("%d ", (add - ans[i]) / 2); puts("");

	return 0;
}