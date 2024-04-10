#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
int A[101010];
int ans[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		set<pii> T;
		for(int i = 1; i < N; i++) {
			if(A[i] > A[i + 1]) T.insert({A[i] - A[i + 1], i + 1});
		}
		set<int> S;
		for(int i = 1; i <= N; i++) {
			ans[i] = 1;
			S.insert(i);
		}
		while(T.size()) {
			auto it = prev(T.end());
			int x = it->first;
			auto it2 = S.lower_bound(x);
			if(it2 != S.end()) {
				ans[*it2] = it->second;
				T.erase(it); S.erase(it2);
			}
			else {
				it2--;
				ans[*it2] = it->second;
				S.erase(it2);
				T.insert({x - *it2, it->second});
				T.erase(it);
			}
		}
		for(int i = 1; i <= N; i++) printf("%d ", ans[i]); puts("");
	}
	return 0;
}