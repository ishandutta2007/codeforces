#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long Q, L, A, B, M;

vector<long long>query() {
	M--;
	if (A == B) return vector<long long>{A};

	int lens = -1; long long target = -1; bool flag = true;
	for (int i = 1; i <= 49; i++) {
		long long e = B - (A << (i - 1LL)) - (1LL << (i - 1)); if (e < 0) break;
		long long cr = (M << (i - 1)); if (cr > (1LL << 60)) flag = false; if (flag == false) cr = (1LL << 60);

		if (e <= cr) { lens = i; target = e; break; }
	}
	if (lens == -1) return vector<long long>{-1LL};

	vector<long long>E; E.push_back(A); long long sum = A;
	for (int i = 0; i < lens; i++) {
		long long V = 1; if (i < lens - 1) V = (1LL << (lens - i - 2));
		long long W = target / V; W = min(W, M);
		E.push_back(sum + W + 1); sum += E[E.size() - 1];
		target -= V * W;
	}
	return E;
}

int main() {
	scanf("%lld", &Q);
	for (int i = 1; i <= Q; i++) {
		scanf("%lld%lld%lld", &A, &B, &M);

		vector<long long> D = query();
		if (D != vector<long long>{-1LL}) printf("%d ", (int)D.size());
		for (int j = 0; j < D.size(); j++) { if (j) printf(" "); printf("%lld", D[j]); } printf("\n");
	}
	return 0;
}