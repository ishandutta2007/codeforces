#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

long long N, A[200009], cnt[200009];
vector<long long> v1, v2;

int main() {
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
		cnt[A[i]]++;
	}
	for (int i = 0; i <= 200000; i++) {
		if (cnt[i] >= 3) {
			cout << "NO" << endl;
			return 0;
		}
	}
	for (int i = 0; i <= 200000; i++) { if (cnt[i] >= 1) v1.push_back(i); }
	for (int i = 200000; i >= 0; i--) { if (cnt[i] >= 2) v2.push_back(i); }

	printf("YES\n");
	printf("%d\n", (int)v1.size());
	for (int i = 0; i < v1.size(); i++) { if (i) printf(" "); printf("%lld", v1[i]); } printf("\n");
	printf("%d\n", (int)v2.size());
	for (int i = 0; i < v2.size(); i++) { if (i) printf(" "); printf("%lld", v2[i]); } printf("\n");
	return 0;
}