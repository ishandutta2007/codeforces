#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

long long A, B, T, maxn; bool used[100009];

int main() {
	cin >> A >> B; T = A + B;
	for (long long i = 1; i <= 100000; i++) {
		long long E = 1LL * i * (i + 1LL) / 2LL;
		if (E <= T) maxn = i;
	}
	for (int i = maxn; i >= 1; i--) {
		if (A >= i) { used[i] = true; A -= i; }
	}
	vector<int>B1, B2;
	for (int i = 1; i <= maxn; i++) { if (used[i] == false) B1.push_back(i); }
	for (int i = 1; i <= maxn; i++) { if (used[i] == true) B2.push_back(i); }

	printf("%d\n", (int)B2.size()); for (int i = 0; i < B2.size(); i++) { if (i) printf(" "); printf("%d", B2[i]); } printf("\n");
	printf("%d\n", (int)B1.size()); for (int i = 0; i < B1.size(); i++) { if (i) printf(" "); printf("%d", B1[i]); } printf("\n");
	return 0;
}