#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

int N, M, A[1 << 18], cnt[1 << 18], ret;

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; i++) scanf("%d", &A[i]);

	for (int i = 1; i <= M; i++) {
		cnt[A[i]]++; if (cnt[A[i]] == 1) ret++;
		if (ret == N) {
			printf("1");
			for (int j = 1; j <= N; j++) {
				cnt[j]--; if (cnt[j] == 0) ret--;
			}
		}
		else {
			printf("0");
		}
	}
	printf("\n");
	return 0;
}