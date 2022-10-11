#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, A[1 << 18], P[43], Q[43], P2[43], Q2[43];

bool solve(int R) {
	for (int i = 0; i <= 41; i++) { P2[i] = P[i]; Q2[i] = Q[i]; }
	long long ret = (1LL << 60);
	for (int i = 0; i <= 41; i++) {
		if (P2[i] > ret || P2[i] > R) {
			long long E = min(ret, 1LL * R);
			Q2[i] += (P2[i] - E);
			P2[i] = E;
		}
		ret = min(ret, P2[i]);
	}
	long long sum = 0;
	for (int i = 1; i <= 41; i++) {
		if (P2[i - 1] == P2[i]) continue;

		long long E = P2[i - 1] - P2[i];
		for (int j = 0; j <= i; j++) {
			if (E > Q2[j]) { E -= Q2[j]; Q2[j] = 0; }
			else { Q2[j] -= E; E = 0; break; }
		}
	}
	for (int i = 0; i <= 41; i++) {
		if (Q2[i] >= 1) return false;
	}
	return true;
}

int main() {
	scanf("%lld", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &A[i]);
		bool flag = true;
		for (int j = 0; j <= 41; j++) { if (A[i] == (1LL << j)) { P[j]++; flag = false; } }
		if (flag == true) {
			int t = 0;
			for (int j = 0; j <= 41; j++) {
				if (A[i] >= (1LL << j)) t = j;
			}
			Q[t + 1]++;
		}
	}

	vector<int>vec;
	for (int i = 1; i <= P[0]; i++) {
		bool E = solve(i);
		if (E == true) vec.push_back(i);
	}
	if (vec.size() == 0) cout << "-1" << endl;
	else {
		for (int i = 0; i < vec.size(); i++) { if (i) printf(" "); printf("%d", vec[i]); }
		printf("\n");
	}
	return 0;
}