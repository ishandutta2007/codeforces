#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
int ans[10101];
vector<pii> v;
int piv;

int query(int t, int i, int j, int x) {
	printf("? %d %d %d %d\n", t, i, j, x); fflush(stdout);
	int ret; scanf("%d", &ret);
	return ret;
}

void type1(int i, int j) {
	int t = query(1, i, j, N - 1);
	if(t == N) piv = j;
	else if(t == N - 1) v.emplace_back(j, i);
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		v.clear();
		scanf("%d", &N);
		piv = -1;
		for(int i = 1; i < N; i += 2) type1(i, i + 1);
		if(N & 1) type1(N - 1, N);

		if(piv == -1) {
			for(pii i : v) {
				type1(i.first, i.second);
			}
		}

		assert(piv != -1);
		ans[piv] = N;
		for(int i = 1; i <= N; i++) {
			if(i == piv) continue;
			ans[i] = query(2, i, piv, 1);
		}
		printf("! ");
		for(int i = 1; i <= N; i++) printf("%d ", ans[i]); puts("");
		fflush(stdout);
	}
	return 0;
}