#include <bits/stdc++.h>

using namespace std;

int N;
int chk[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= 2 * N + 1; i++) chk[i] = false;
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			chk[a]++;
		}

		int ans = 0;
		int l = -1;
		bool fg = false;
		for(int i = 1; i <= 2 * N + 1; i++) {
			if(chk[i]) {
				if(!chk[i - 1]) {
					l = i;
					fg = false;
				}
				if(chk[i] > 1) fg = true;
			}
			else if(chk[i - 1]) {
				ans += i - l;
				if(fg) ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}