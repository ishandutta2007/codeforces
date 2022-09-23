#include <bits/stdc++.h>

using namespace std;

int A[6] = {4, 1, 3, 2, 0, 5};

int main() {
	int N; scanf("%d", &N);
	int ans = 0;
	for(int i = 0; i < 6; i++) {
		if(N & (1 << i)) ans += 1 << A[i];
	}
	printf("%d\n", ans);
	return 0;
}