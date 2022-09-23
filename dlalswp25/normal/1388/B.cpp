#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		int k = (N - 1) / 4 + 1;
		for(int i = 0; i < N - k; i++) printf("9");
		for(int i = 0; i < k; i++) printf("8"); puts("");
	}
	return 0;
}