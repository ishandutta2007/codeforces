#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

vector<long long> DifferByOneBitDiv1(vector<long long> E) {
	vector<long long>A; long long cx = 0; A.push_back(cx);
	for (int i = 1; i <= (1 << (int)E.size()) - 1; i++) {
		int cnt = 0, cp = i; while ((cp & 1) == 0) { cp >>= 1; cnt++; }
		cx ^= E[cnt]; A.push_back(cx);
	}
	return A;
}

void Gauss(vector<long long> &A) {
	int rank = 0;
	for (int d = 19; d >= 0; d--) {
		int pivot = -1;
		for (int i = rank; i < (int)A.size(); ++i) {
			if (A[i] & (1LL << d)) {
				pivot = i;
				break;
			}
		}
		if (pivot == -1) continue;
		swap(A[rank], A[pivot]);
		for (int j = 0; j < (int)A.size(); ++j) {
			if (j == rank) continue;
			if (!(A[j] & (1LL << d))) continue;
			A[j] ^= A[rank];
		}
		++rank;
	}
}

vector<long long> solve(int bits, vector<long long>E) {
	vector<long long>A, C; vector<int>B;

	for (int i = 0; i < E.size(); i++) {
		long long cx = 0;
		for (int j = A.size() - 1; j >= 0; j--) {
			int bit1 = (E[i] & (1 << B[j]));
			int bit2 = (cx & (1 << B[j]));
			if (bit1 != bit2) cx ^= A[j];
		}
		if (cx != E[i]) {
			A.push_back(E[i]); C.push_back(E[i]); B.push_back(0);
			Gauss(A); sort(A.begin(), A.end());
			for (int j = 0; j < A.size(); j++) {
				B[j] = 0;
				for (int k = 0; k < 20; k++) {
					if (A[j] >= (1 << k)) B[j] = k;
				}
			}
		}
	}
	if ((int)C.size() != bits) return vector<long long>{-1LL};
	return DifferByOneBitDiv1(C);
}

long long N, P[1 << 19];

int main() {
	scanf("%lld", &N);
	for (int i = 0; i < N; i++) scanf("%lld", &P[i]);

	vector<long long>C; int ans = 0;
	for (int i = 0; i <= 19; i++) {
		vector<long long>E;
		for (int j = 0; j < N; j++) { if (P[j] < (1LL << i)) E.push_back(P[j]); }
		vector<long long>F = solve(i, E);
		if (F != vector<long long>{-1LL}) { ans = i; C = F; }
	}

	printf("%d\n", ans);
	for (int i = 0; i < C.size(); i++) { if (i >= 1) printf(" "); printf("%lld", C[i]); }
	printf("\n");
	return 0;
}