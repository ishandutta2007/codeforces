#include <bits/stdc++.h>

using namespace std;

int N;

int X[101010];
int Y[101010];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d%d", &X[i], &Y[i]);

	if(N & 1) { puts("NO"); return 0; }
	X[N + 1] = X[1]; Y[N + 1] = Y[1];

	bool ok = true;
	for(int i = 1; i < N / 2; i++) {
		if(X[i + 1] - X[i] != X[i + N / 2] - X[i + N / 2 + 1]) ok = false;
		if(Y[i + 1] - Y[i] != Y[i + N / 2] - Y[i + N / 2 + 1]) ok = false;
	}
	puts(ok ? "YES" : "NO");

	return 0;
}