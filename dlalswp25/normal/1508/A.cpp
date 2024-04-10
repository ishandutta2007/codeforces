#include <bits/stdc++.h>

using namespace std;

int N;
char A[3][202020];
int P[3];
char ans[303030];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 0; i < 3; i++) {
			scanf("%s", A[i] + 1);
		}

		P[0] = P[1] = P[2] = 1;
		int pos = 1;
		while(1) {
			int tmp[3] = {0, 1, 2};
			sort(tmp, tmp + 3, [&](const int a, const int b) {
				return P[a] < P[b];
			});
			if(P[tmp[2]] > 2 * N) {
				int t = tmp[1];
				while(pos <= 3 * N) {
					char x = (P[t] > 2 * N ? '0' : A[t][P[t]]);
					ans[pos++] = x;
					P[t]++;
				}
				break;
			}
			int c0 = 0, c1 = 0;
			for(int i = 0; i < 3; i++) {
				if(A[i][P[i]] == '0') c0++;
				else c1++;
			}
			char c;
			if(c0 > c1) c = '0';
			else c = '1';
			ans[pos++] = c;
			for(int i = 0; i < 3; i++) {
				if(A[i][P[i]] == c) P[i]++;
			}
		}
		for(int i = 1; i <= 3 * N; i++) printf("%c", ans[i]); puts("");
	}
	return 0;
}