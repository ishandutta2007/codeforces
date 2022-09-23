#include <bits/stdc++.h>

using namespace std;

int N;
int A[202020];
int B[202020];
int P[202020];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for(int i = 1; i <= N; i++) scanf("%d", &B[i]);
	for(int i = 1; i <= N; i++) P[B[i]] = i;
	int x = P[1];
	bool ok = true;
	for(int i = x + 1; i <= N; i++) if(B[i] - B[i - 1] != 1) ok = false;

	int ans = 987654321;

	if(ok) {
		int st = N - x + 2;
		ok = true;
		for(int i = st; i <= N; i++) {
			if(P[i] == 0) continue;
			if(P[i] + st > i) { ok = false; break; }
		}

		if(ok) ans = x - 1;
	}

	int mx = 0;
	for(int i = 1; i <= N; i++) {
		if(P[i] < x) continue;
		mx = max(mx, P[i] - i + 1);
	}
	printf("%d\n", min(ans, mx + N));

	return 0;
}