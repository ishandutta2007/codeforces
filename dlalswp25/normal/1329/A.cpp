#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M;
int L[101010];
ll S[101010];
int ans[101010];
ll s;

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= M; i++) {
		scanf("%d", &L[i]);
		s += L[i];
		S[i] = S[i - 1] + L[i];
	}
	if(s < N) { puts("-1"); return 0; }

	ans[M] = N - L[M] + 1;
	int x = ans[M];

	for(int i = M - 1; i >= 1; i--) {
		int y = min(x - 1, N - L[i] + 1);
		y = min((ll)y, S[i - 1] + 1);
		ans[i] = y;
		x = y;
	}

	if(ans[1] < 1) { puts("-1"); return 0; }
	for(int i = 1; i <= M; i++) printf("%d ", ans[i]); puts("");

	return 0;
}