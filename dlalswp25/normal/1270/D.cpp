#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> q;
int p, v;

int A[505];

void query() {
	printf("? ");
	for(int i : q) printf("%d ", i); puts("");
	fflush(stdout);
	q.clear();
}

int main() {
	scanf("%d%d", &N, &K);
	if(K == 1) { puts("! 1"); fflush(stdout); return 0; }
	for(int i = 1; i <= K; i++) q.push_back(i);
	query();
	scanf("%d%d", &p, &v);

	int x = K;
	for(; x >= 1; x--) if(x != p) break;
	A[x] = -1;

	for(int i = K + 1; i <= N; i++) {
		for(int j = 1; j <= K; j++) if(j != x) q.push_back(j);
		q.push_back(i);
		query();
		int a, b; scanf("%d%d", &a, &b);
		if(a == p) {
			A[i] = A[x];
		}
		else if(b > v) {
			for(int j = 1; j <= N; j++) if(A[j] == -1) A[j] = 2;
			A[i] = 1;
		}
		else {
			for(int j = 1; j <= N; j++) if(A[j] == -1) A[j] = 1;
			A[i] = 2;
		}
	}
	// for(int i = 1; i <= N; i++) printf("%d ", A[i]); puts("");

	for(int i = 1; i <= K; i++) {
		if(i == p || i == x) continue;
		for(int j = 1; j <= K; j++) if(j != i) q.push_back(j);
		q.push_back(K + 1);
		query();
		int a, b; scanf("%d%d", &a, &b);
		if(a == p) {
			A[i] = A[K + 1];
		}
		else if(b > v) {
			for(int j = 1; j <= N; j++) if(A[j] == -1) A[j] = 1;
			A[i] = 2;
		}
		else {
			for(int j = 1; j <= N; j++) if(A[j] == -1) A[j] = 2;
			A[i] = 1;
		}
	}
	// for(int i = 1; i <= N; i++) printf("%d ", A[i]); puts("");
	// printf("%d\n", p);
	for(int i = 1; i <= N; i++) {
		if(i == p) continue;
		if(A[i] == -1 && q.size() < K) q.push_back(i);
	}
	if(q.size() == K) {
		query();
		int a, b; scanf("%d%d", &a, &b);
		if(b > v) {
			for(int i = 1; i <= N; i++) if(A[i] == -1) A[i] = 1;
		}
		else {
			for(int i = 1; i <= N; i++) if(A[i] == -1) A[i] = 2;
		}
	}

	int ans = 0;
	for(int i = 1; i <= K; i++) if(i != p && A[i] == 2) ans++;
	printf("! %d\n", ans + 1);

	fflush(stdout);
	return 0;
}