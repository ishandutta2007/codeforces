#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

long long N, A[1 << 18], cnt[1 << 18];
vector<int>vec;

int main() {
	scanf("%lld", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &A[i]);
		cnt[A[i]]++;
	}

	int maxn = 0, maxid = 0;
	for (int i = 0; i <= 200000; i++) {
		if (maxn < cnt[i]) { maxn = cnt[i]; maxid = i; }
	}

	for (int i = 0; i < N; i++) {
		if (A[i] == maxid) vec.push_back(i);
	}

	int L = 0;
	printf("%d\n", N - maxn);
	for (int i = 0; i < vec.size(); i++) {
		for (int j = vec[i] - 1; j >= L; j--) {
			if (A[j] < maxid) printf("1 %d %d\n", j + 1, j + 2);
			else printf("2 %d %d\n", j + 1, j + 2);
		}
		L = vec[i] + 1;
	}
	for (int i = vec[vec.size() - 1]; i < N - 1; i++) {
		if (A[i + 1] < maxid) printf("1 %d %d\n", i + 2, i + 1);
		else printf("2 %d %d\n", i + 2, i + 1);
	}
	return 0;
}