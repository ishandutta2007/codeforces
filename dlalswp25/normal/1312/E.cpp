#include <bits/stdc++.h>

using namespace std;

int A[505];
int C[505][505];
int D[505][505];

int N;

vector<int> v;

int f(int i, int j) {
	if(D[i][j] != 0) return D[i][j];
	D[i][j] = C[i][j];
	for(int k = i; k < j; k++) D[i][j] = min(D[i][j], f(i, k) + f(k + 1, j));
	return D[i][j];
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

	for(int i = 1; i <= N; i++) {
		for(int j = i; j <= N; j++) {
			v.clear();
			for(int k = i; k <= j; k++) {
				int t = A[k];
				while(v.size() && v.back() == t) {
					v.pop_back(); t++;
				}
				v.push_back(t);
			}
			C[i][j] = v.size();
			// printf("%d %d %d\n", i, j, C[i][j]);
		}
	}

	printf("%d\n", f(1, N));
	return 0;
}