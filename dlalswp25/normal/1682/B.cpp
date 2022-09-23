#include <bits/stdc++.h>

using namespace std;

int N;
int A[202020];

bool f(int x) {
	for(int i = 0; i < N; i++) {
		if((i & x) != x && A[i] != i) return false;
	}
	return true;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 0; i < N; i++) scanf("%d", &A[i]);
		int ans = 0;
		for(int i = 18; i >= 0; i--) {
			if(f(ans | 1 << i)) ans |= 1 << i;
		}
		printf("%d\n", ans);
	}
	return 0;
}