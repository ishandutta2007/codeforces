#include <bits/stdc++.h>

using namespace std;

int N, D;
int p[1010];
int sz[1010];

int par(int x) {
	if(x == p[x]) return x;
	return p[x] = par(p[x]);
}

bool unite(int a, int b) {
	a = par(a); b = par(b);
	if(a == b) return false;
	p[a] = b;
	sz[b] += sz[a];
	return true;
}

int main() {
	scanf("%d%d", &N, &D);
	for(int i = 1; i <= N; i++) { p[i] = i; sz[i] = 1; }

	int cnt = 0;
	for(int i = 1; i <= D; i++) {
		int a, b; scanf("%d%d", &a, &b);
		cnt += !unite(a, b);
		vector<int> v;

		for(int j = 1; j <= N; j++) {
			if(p[j] != j) continue;
			v.push_back(sz[j]);
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());

		int ans = 0;
		for(int j = 0; j < v.size(); j++) {
			if(j >= cnt + 1) break;
			ans += v[j];
		}
		printf("%d\n", ans - 1);
	}

	return 0;
}