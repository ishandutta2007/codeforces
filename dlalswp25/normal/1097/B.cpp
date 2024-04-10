#include <bits/stdc++.h>

using namespace std;

int A[20];

int main() {
	int N; scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%d", &A[i]);
	for(int i = 0; i < (1 << N); i++) {
		int s = 0;
		for(int j = 0; j < N; j++) {
			if(i & (1 << j)) s += A[j];
			else s -= A[j];
		}
		if(s % 360 == 0) {
			puts("YES"); return 0;
		}
	}
	puts("NO"); return 0;
}