#include <bits/stdc++.h>

using namespace std;

int D[101010];
int N;

int main() {
	scanf("%d", &N);
	for(int i = 1; i < N; i++) {
		int a, b; scanf("%d%d", &a, &b);
		D[a]++; D[b]++;
	}
	for(int i = 1; i <= N; i++) {
		if(D[i] == 2) {
			puts("NO"); return 0;
		}
	}
	puts("YES");
	return 0;
}