#include <bits/stdc++.h>

using namespace std;

int main() {
	int N; scanf("%d", &N);
	for(int i = 2; i <= N; i++) {
		if(N % i == 0) {
			printf("%d%d\n", i, N / i);
			return 0;
		}
	}
	return 0;
}