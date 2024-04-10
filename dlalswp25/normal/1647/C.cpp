#include <bits/stdc++.h>

using namespace std;

int N, M;
char A[105][105];
int ans[10101][4];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		int id = 0;
		for(int i = 1; i <= N; i++) scanf("%s", A[i] + 1);
		if(A[1][1] == '1') { puts("-1"); continue; }

		for(int i = N; i >= 1; i--) {
			for(int j = M; j >= 1; j--) {
				id++;
				if(A[i][j] == '0') {
					ans[id][0] = ans[id][2] = i;
					ans[id][1] = ans[id][3] = j;
				}
				else if(j == 1) {
					ans[id][0] = i - 1; ans[id][1] = j;
					ans[id][2] = i; ans[id][3] = j;
				}
				else {
					ans[id][0] = i; ans[id][1] = j - 1;
					ans[id][2] = i; ans[id][3] = j;
				}
			}
		}
		printf("%d\n", id);
		for(int i = 1; i <= id; i++) printf("%d %d %d %d\n", ans[i][0], ans[i][1], ans[i][2], ans[i][3]);
	}
	return 0;
}