#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int A[303030];
int P[303030];
int N;
vector<pii> V;

void f(int a, int b) {
	V.push_back({a, b});
	swap(P[A[a]], P[A[b]]);
	swap(A[a], A[b]);
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		P[A[i]] = i;
	}

	for(int i = 1; i <= N / 2; i++) {
		int a = i, b = N / 2 + i;
		if(P[b] <= N / 2) {
			f(P[b], N);
			f(P[b], i);
			f(P[b], b);
		}
		else if(P[N / 2 + i] != N / 2 + i) {
			f(P[b], i);
			f(P[b], b);
		}

		if(P[i] > N / 2) {
			f(P[i], i);
		}
		else if(P[i] != i) {
			f(P[i], N);
			f(P[i], i);
		}
	}
	printf("%d\n", V.size());
	for(pii i : V) printf("%d %d\n", i.first, i.second);
	return 0;
}