#include <bits/stdc++.h>

using namespace std;

int L, R;
int cnt[20][2];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		for(int i = 0; i < 17; i++) cnt[i][0] = cnt[i][1] = 0;
		scanf("%d%d", &L, &R);
		for(int i = 1; i <= R - L + 1; i++) {
			int a; scanf("%d", &a);
			for(int j = 0; j < 17; j++) {
				cnt[j][a >> j & 1]++;
			}
		}
		int ans = 0;
		for(int i = 0; i < 17; i++) {
			if(cnt[i][0] < cnt[i][1]) ans |= 1 << i;
		}
		printf("%d\n", ans);
	}
	return 0;
}