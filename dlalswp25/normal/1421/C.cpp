#include <bits/stdc++.h>

using namespace std;

int N;
char S[101010];

int main() {
	scanf("%s", S + 1);
	N = strlen(S + 1);
	puts("3");
	printf("R %d\n", N - 1);
	printf("L %d\n", N);
	printf("L %d\n", 2);
	return 0;
}