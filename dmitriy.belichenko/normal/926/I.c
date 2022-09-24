#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int arr[1000];
int main() {

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int h, m;
		scanf("%d:%d\n", &h, &m);
		arr[i] = 60 * h + m;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				int c = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = c;
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < n - 1; ++i) {
		int tm = arr[i + 1] - arr[i] - 1;
		if (answer < tm) {
			answer = tm;
		}
	}
	int tm = arr[0] + 24 * 60 - arr[n - 1] - 1;
	if (answer < tm) {
		answer = tm;
	}
	printf("%02d:%02d\n", answer / 60, answer % 60);
	return 0;
}