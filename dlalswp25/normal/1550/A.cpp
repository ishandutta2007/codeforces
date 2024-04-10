#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		int ans = 1;
		for(; ans * ans < N; ans++);
		printf("%d\n", ans);
	}
	return 0;
}