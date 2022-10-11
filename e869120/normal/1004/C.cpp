#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

long long N, A[100009], cl[100009], cr[100009], sum;

int main() {
	scanf("%lld", &N);
	for (int i = 0; i <= 100000; i++) { cl[i] = (1LL << 30); cr[i] = -(1LL << 30); }
	for (int i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
		cl[A[i]] = min(cl[A[i]], 1LL * i);
		cr[A[i]] = max(cr[A[i]], 1LL * i);
	}
	vector<long long>E;
	for (int i = 0; i <= 100000; i++) { if (cl[i] != (1LL << 30)) E.push_back(cl[i]); }
	sort(E.begin(), E.end());

	for (int i = 0; i <= 100000; i++) {
		if (cr[i] == -(1LL << 30)) continue;
		int pos1 = lower_bound(E.begin(), E.end(), cr[i]) - E.begin();
		sum += 1LL * pos1;
	}
	cout << sum << endl;
	return 0;
}