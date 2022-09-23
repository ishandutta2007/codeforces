#include <bits/stdc++.h>

using namespace std;

int a, b;

int main() {
	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		int x; scanf("%d", &x);
		if(x == 1) a++;
		else b++;
		if(N == 1) {
			printf("%d\n", x);
			return 0;
		}
	}

	if(b == 0 || a == 0) {
		for(int i = 1; i <= N; i++) printf("%d ", b == 0 ? 1 : 2); puts("");
		return 0;
	}
	printf("2 1 ");
	a--; b--;
	while(b--) {
		printf("2 ");
	}
	while(a--) {
		printf("1 ");
	}
	puts("");

	return 0;
}