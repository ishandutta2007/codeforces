#include <bits/stdc++.h>

using namespace std;

int N;
int A[2525];
int pos[2525];
vector<int> ans;

void sw(int a, int b) {
	int va = A[a], vb = A[b];
	pos[va] = b; pos[vb] = a;
	A[a] = vb; A[b] = va;
}

void f(int x) {
	assert(x & 1);
	if(x == 1) return;
	ans.push_back(x);
	for(int i = 1; ; i++) {
		int j = x - i + 1;
		if(i >= j) break;
		sw(i, j);
	}
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		bool ok = true;
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			pos[A[i]] = i;
			if(i % 2 != A[i] % 2) ok = false;
		}
		if(!ok) { puts("-1"); continue; }

		ans.clear();
		for(int i = N; i > 1; i -= 2) {
			if(pos[i] == i && pos[i - 1] == i - 1) continue;
			f(pos[i]);
			f(pos[i - 1] - 1);
			f(pos[i - 1] + 1);
			f(3);
			f(i);
		}

		printf("%d\n", ans.size());
		for(int i : ans) printf("%d ", i); puts("");
	}
	return 0;
}