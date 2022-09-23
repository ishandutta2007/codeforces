#include <bits/stdc++.h>

using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N; scanf("%d", &N);
		int ans = 1 << N;
		for(int i = N / 2; i < N; i++) ans -= 1 << i;
		for(int i = 1; i < N / 2; i++) ans += 1 << i;
		printf("%d\n", ans);
	}
	return 0;
}