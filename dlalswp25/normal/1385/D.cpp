#include <bits/stdc++.h>

using namespace std;

char A[131313];
int cnt[131313][30];
int N;

int ans[4 * 131313];

int get(int l, int r, int x) {
	return r - l + 1 - (cnt[r][x] - cnt[l - 1][x]);
}

void f(int idx, int s, int e, int k) {
	if(e < s) return;
	if(s == e) {
		ans[idx] = get(s, e, k);
		return;
	}
	int m = s + e >> 1;
	f(idx << 1, s, m, k + 1);
	f(idx << 1 | 1, m + 1, e, k + 1);
	ans[idx] = min(ans[idx << 1] + get(m + 1, e, k), ans[idx << 1 | 1] + get(s, m, k));
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", A + 1);
		for(int i = 1; i <= N; i++) {
			for(int j = 0; j < 26; j++) cnt[i][j] = cnt[i - 1][j];
			cnt[i][A[i] - 'a']++;
		}

		f(1, 1, N, 0);
		printf("%d\n", ans[1]);
	}
	return 0;
}