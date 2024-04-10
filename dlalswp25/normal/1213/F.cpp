#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int P[202020];
int Q[202020];
int pi[202020];
int qi[202020];

int N, K;

int ans[202020];
int ret[202020];

int main() {
	scanf("%d%d", &N, &K);
	for(int i = 1; i <= N; i++) scanf("%d", &P[i]);
	for(int i = 1; i <= N; i++) scanf("%d", &Q[i]);

	for(int i = 1; i <= N; i++) { pi[P[i]] = i; qi[Q[i]] = i; }

	ll s = 0;
	ll mx = 0;
	int t = 0;
	for(int i = 1; i <= N; i++) {
		ans[i] = t;
		mx = max(mx, (ll)qi[P[i]]);
		s += qi[P[i]];
		if(mx * (mx + 1) / 2 == s) t++;
	}

	if(ans[N] < K - 1) { puts("NO"); return 0; }
	puts("YES");
	for(int i = 1; i <= N; i++) ret[P[i]] = ans[i];
	for(int i = 1; i <= N; i++) printf("%c", min(ret[i], 25) + 'a'); puts("");
	return 0;
}