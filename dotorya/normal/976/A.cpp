#include <stdio.h>
#include <algorithm>
#include <time.h>
#include <string>
#include <set>
using namespace std;

#pragma warning(disable:4996)

char in[100050];
int main() {
	int N, i;
	scanf("%d %s", &N, in);
	if (N == 1) return !printf("%s\n", in);

	int c0 = 0, c1 = 0;
	for (i = 0; i < N; i++) {
		if (in[i] == '0') c0++;
		else c1++;
	}
	printf("1");
	for (i = 1; i <= c0; i++) printf("0");
	return !printf("\n");
}