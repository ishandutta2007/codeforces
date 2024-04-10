#include <bits/stdc++.h>

using namespace std;

int N, A, B;
int ans[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d%d", &N, &A, &B);
		if(A > (N - 1) / 2 || B > (N - 1) / 2) { puts("-1"); continue; }
		if(abs(A - B) >= 2) { puts("-1"); continue; }
		if(A + B > N - 2) { puts("-1"); continue; }
		int t = N - (A + B) - 1;
		for(int i = 1; i <= t; i++) ans[i] = i;
		int l = t + 1, r = N;
		bool fg = false;
		for(int i = t + 1; i <= N; i++) {
			if(fg) ans[i] = l++;
			else ans[i] = r--;
			fg = !fg;
		}
		if(A < B) {
			for(int i = 1; i <= N; i++) ans[i] = N - ans[i] + 1;
		}
		for(int i = 1; i <= N; i++) printf("%d ", ans[i]); puts("");
	}
	return 0;
}