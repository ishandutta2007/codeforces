#include <bits/stdc++.h>

using namespace std;

int N;

void f(int i) { printf("%d %d %d\n", i, i + 1, i + 2); }

int main() {
	scanf("%d", &N);
	int x = 0;
	for(int i = 1; i <= N; i++) {
		int a; scanf("%d", &a);
		x ^= a;
	}
	if(N % 2 == 0 && x) { puts("NO"); return 0; }
	puts("YES");
	if(N % 2 == 0) {
		printf("%d\n", (N - 2) / 2 + (N - 4) / 2);
		for(int i = 1; i <= N - 3; i += 2) f(i);
		for(int i = N - 5; i >= 1; i -= 2) f(i);
	}
	else {
		printf("%d\n", (N - 1) / 2 + (N - 3) / 2);
		for(int i = 1; i <= N - 2; i += 2) f(i);
		for(int i = N - 4; i >= 1; i -= 2) f(i);
	}
	return 0;
}