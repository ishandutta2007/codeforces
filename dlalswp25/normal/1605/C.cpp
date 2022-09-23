#include <bits/stdc++.h>

using namespace std;

int N;
char A[1010101];
int cnt[1010101][3];

bool chk(int i, int j) {
	return i - j > 1 && (cnt[i][0] - cnt[j][0] > cnt[i][1] - cnt[j][1]) && (cnt[i][0] - cnt[j][0] > cnt[i][2] - cnt[j][2]);
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", A + 1);
		for(int i = 1; i <= N; i++) {
			for(int j = 0; j < 3; j++) cnt[i][j] = cnt[i - 1][j];
			cnt[i][A[i] - 'a']++;
		}
		int bef = 0, bef2 = 0;
		int ans = N + 1;
		for(int i = 1; i <= N; i++) {
			if(A[i] == 'a') {
				if(chk(i, bef)) ans = min(ans, i - bef);
				else if(chk(i, bef2)) ans = min(ans, i - bef2);
				bef2 = bef; bef = i - 1;
			}
		}
		printf("%d\n", ans > N ? -1 : ans);
	}
	return 0;
}