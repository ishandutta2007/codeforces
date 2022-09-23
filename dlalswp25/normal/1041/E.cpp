#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

pii E[1005];
int X[1005];
int dep[1005];
int par[1005];
vector<int> V;
int ans[1005];

int main() {
	int N; scanf("%d", &N);
	for(int i = 1; i < N; i++) scanf("%d%d", &E[i].first, &E[i].second);
	for(int i = 1; i < N; i++) {
		if(E[i].first != N && E[i].second != N) { puts("NO"); return 0; }
		if(E[i].first == N) swap(E[i].first, E[i].second);
		X[i] = E[i].first;
	}
	sort(X + 1, X + N);

	int p = N - 1;
	int lft = 0;
	int bef = 1;
	dep[N] = 1;
	for(int i = N - 1; i >= 1; i--) {
		int t = 0;
		while(X[p] == i) { t++; p--; }
		if(t == 0) {
			if(lft == 0) { puts("NO"); return 0; }
			lft--;
		}
		else { dep[i] = bef + t; lft += t - 1; bef = dep[i]; }
	}
	if(lft) { puts("NO"); return 0; }

	for(int i = 1; i <= N; i++) {
		if(!dep[i]) V.push_back(i);
		ans[dep[i]] = i;
	}
	for(int i = 1; i <= N; i++) {
		if(ans[i]) continue;
		ans[i] = V.back(); V.pop_back();
	}
	puts("YES");
	for(int i = 1; i < N; i++) {
		printf("%d %d\n", ans[i], ans[i + 1]);
	}
	return 0;
}