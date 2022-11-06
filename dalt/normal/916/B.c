#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
#ifndef ONLINE_JUDGE
	freopen("D:\\DataBase\\TESTCASE\\codeforces\\916B.in", "r",
	stdin);
#endif

	unsigned __int64 n;
	int k;
	scanf("%I64d %d", &n, &k);

	int bits[128];
	int sum = 0;
	for (int i = 0; i < 64; i++) {
		bits[i + 64] = (n >> i) & 1;
		sum += bits[i + 64];

		bits[i] = 0;
	}

	if (sum > k) {
		printf("No\n");
		return 0;
	}

	printf("Yes\n");
	for (int i = 127; i >= 1 && sum < k; i--) {
		if (k - sum < bits[i]) {
			break;
		} else {
			sum += bits[i];
			bits[i - 1] += bits[i] << 1;
			bits[i] = 0;
		}
	}

	if (sum < k) {
		int i = 0;
		while (bits[i] == 0) {
			i++;
		}
		bits[i]--;
		for (i--; sum < k && i >= 0; i--) {
			sum++;
			bits[i] = 1;
		}
		bits[i + 1]++;
		if (sum < k) {
			bits[0]--;
		}
	}

	for (int i = 127; i >= 0; i--) {
		int v = i - 64;
		for (int j = 0, bound = bits[i]; j < bound; j++) {
			printf("%d ", v);
		}
	}
	if (sum < k) {
		int i; //-i can provide i
		int bound = sum - k - 64;
		for (i = -65; i >= bound; i--) {
			printf("%d ", i);
		}
		printf("%d", bound);
	}

	return 0;
}