#include <bits/stdc++.h>

using namespace std;

int ans[505];
bool used[505];
int N, L, R, S;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d%d%d", &N, &L, &R, &S);
		for(int i = 1; i <= N; i++) { ans[i] = 0; used[i] = false; }

		for(int i = L; i <= R; i++) {
			ans[i] = i - L + 1;
			S -= i - L + 1;
		}

		if(S < 0) { puts("-1"); continue; }

		int p = R;
		while(S) {
			ans[p]++; S--;
			p--;
			if(p < L) p = R;
		}

		if(ans[R] > N) { puts("-1"); continue; }
		for(int i = L; i <= R; i++) used[ans[i]] = true;

		p = 1;
		for(int i = 1; i <= N; i++) {
			if(ans[i]) continue;
			while(used[p]) p++;
			ans[i] = p; p++;
		}

		for(int i = 1; i <= N; i++) printf("%d ", ans[i]); puts("");
	}
	return 0;
}