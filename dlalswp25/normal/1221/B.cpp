#include <bits/stdc++.h>

using namespace std;

int main() {
	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			printf(i + j & 1 ? "B" : "W");
		}
		puts("");
	}
	return 0;
}