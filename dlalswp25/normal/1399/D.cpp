#include <bits/stdc++.h>

using namespace std;

char S[202020];
int ans[202020];

int id;
set<int> T[2];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		scanf("%s", S + 1);
		for(int i = 1; i <= N; i++) S[i] -= '0';

		id = 0;
		T[0].clear(); T[1].clear();

		for(int i = 1; i <= N; i++) {
			if(T[S[i] ^ 1].empty()) {
				id++;
				T[S[i]].insert(id);
				ans[i] = id;
			}
			else {
				int t = *(T[S[i] ^ 1].begin());
				ans[i] = t;
				T[S[i] ^ 1].erase(t);
				T[S[i]].insert(t);
			}
		}

		printf("%d\n", id);
		for(int i = 1; i <= N; i++) printf("%d ", ans[i]); puts("");
	}
	return 0;
}