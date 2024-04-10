#include <bits/stdc++.h>

using namespace std;

int N;
int D[101010][2];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) D[i][0] = D[i][1] = 0;
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			D[a][i + 1 & 1] = max(D[a][i + 1 & 1], D[a][i & 1] + 1);
		}
		for(int i = 1; i <= N; i++) printf("%d ", max(D[i][0], D[i][1])); puts("");
	}
	return 0;
}