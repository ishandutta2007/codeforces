#include<bits/stdc++.h>
using namespace std;

int T, N, p, k;
int cnt[100005];

void Solve() {
	scanf("%d%d%d", &N, &p, &k);
	for(int i = 1; i <= N; i++) scanf("%1d", &cnt[i]), cnt[i] = !cnt[i];
	for(int i = N; i; i--) if(i + k <= N) cnt[i] += cnt[i + k];
	int ans = 1e9 + 100, x, y; scanf("%d%d", &x, &y);
	for(int i = p; i <= N; i++) ans = min(ans, cnt[i] * x + (i - p) * y);
	printf("%d\n", ans);
}

int main() {
	scanf("%d", &T);
	while(T--) Solve();
}