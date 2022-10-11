#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, P, K, A[1 << 19];
vector<long long>vec1; map<long long, int>Map, Map2;

long long product(vector<long long>E) {
	long long r = 1;
	for (int i = 0; i < E.size(); i++) { r *= E[i]; r %= P; }
	return r;
}

int main() {
	scanf("%lld%lld%lld", &N, &P, &K);
	for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	for (int i = 1; i <= N; i++) vec1.push_back(A[i] * (product({ A[i], A[i], A[i] }) - K + P) % P);
	for (int i = 1; i <= N; i++) { Map[A[i] * (product({ A[i], A[i], A[i] }) - K + P) % P]++; Map2[A[i]]++; }
	sort(A + 1, A + N + 1);

	long long r = 0;
	for (int i = 0; i < vec1.size(); i++) r += Map[vec1[i]];

	for (int i = 1; i <= N; i++) {
		if (i != N && A[i] == A[i + 1]) continue;
		long long E1 = A[i] + A[i];
		long long E2 = A[i] * A[i] + A[i] * A[i];
		E1 %= P; E2 %= P;
		if ((E1 * E2 % P) != K) r -= Map2[A[i]] * Map2[A[i]];
		else r -= Map2[A[i]];
	}
	cout << r / 2 << endl;
	return 0;
}