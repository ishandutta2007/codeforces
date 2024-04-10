#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		v.clear();
		int N, K; scanf("%d%d", &N, &K);
		for(int i = 1; i <= N; i++) {
			int x; scanf("%d", &x);
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());

		if(K < v.size()) { puts("-1"); continue; }
		printf("%d\n", N * K);
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < K; j++) {
				if(j >= v.size()) printf("%d ", v[0]);
				else printf("%d ", v[j]);
			}
		}
		puts("");
	}
	return 0;
}