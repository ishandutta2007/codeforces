#include <bits/stdc++.h>

using namespace std;

int N, P;
int A[101010];
vector<int> v;
int L[101010];
int X[101010];

bool tmp[101010];

void print() {
	printf("%d\n", v.size());
	for(int i : v) printf("%d ", i); puts("");
}

int main() {
	scanf("%d%d", &N, &P);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	sort(A + 1, A + N + 1);

	int mn = 0;
	for(int i = 1; i <= N; i++) {
		mn = max(mn, A[i] - i + 1);
	}

	for(int i = 1; i <= N; i++) L[i] = max(1, A[i] + 1 - mn);
	for(int i = 1; i <= N; i++) X[i] = (N - L[i] + 1) - (N - i);
	// for(int i = 1; i <= N; i++) printf("%d ", L[i]); puts("");

	// for(int i = 1; i <= N; i++) printf("%d ", X[i]); puts("");

	if(P <= 300) {
		for(int i = mn; i <= mn + P; i++) {
			bool ok = false;
			for(int j = 1; j <= N; j++) {
				if(X[j] % P == 0) ok = true;
			}
			if(!ok) v.push_back(i);
			for(int j = 1; j <= N; j++) if(X[j] != j) X[j]++;
		}
		print();
		return 0;
	}

	int end = N + 1;
	for(int i = 1; i * P <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(j >= i * P && i * P >= X[j]) {
				tmp[i * P - X[j]] = true;
			}
			if(j == i * P) end = min(end, j - X[j]);
		}
	}

	for(int i = 0; i < end; i++) {
		if(!tmp[i]) v.push_back(mn + i);
	}

	print();
	return 0;
}