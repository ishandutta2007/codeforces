#include <bits/stdc++.h>

using namespace std;

int N, M;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		int s = 0;
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			s += a;
		}
		printf("%d\n", max(0, s - M));
	}
	return 0;
}