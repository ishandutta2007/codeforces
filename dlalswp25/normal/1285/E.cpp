#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;

int cnt[202020];
int B[202020];

pii A[202020];
vector<pii> evt;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N; scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d%d", &A[i].first, &A[i].second);
		for(int i = 1; i <= N; i++) { B[i] = -1; cnt[i] = 0; }
		sort(A + 1, A + N + 1);

		set<int> S;
		for(int i = 1; i <= N; i++) {
			evt.push_back({A[i].first, -i});
			evt.push_back({A[i].second, i});
		}
		sort(evt.begin(), evt.end());

		int ans = 0, mx = 0;
		int tmp = 0;

		for(pii i : evt) {
			int id = abs(i.second);
			if(i.second < 0) {
				// printf("%d %d\n", id, S.size());
				if(S.size() == 1 && tmp > 1) {
					B[id] = *(S.begin());
				}
				else if(S.size() == 0) { ans++; tmp = 0; }
				S.insert(id); tmp++;
			}
			else {
				S.erase(id);
			}
		}
		// for(int i = 1; i <= N; i++) printf("%d ", B[i]); puts("");

		for(int i = 1; i <= N; i++) if(B[i] != -1) cnt[B[i]]++;
		for(int i = 1; i <= N; i++) {
			mx = max(mx, cnt[i]);
		}
		if(ans == N) printf("%d\n", N - 1);
		else printf("%d\n", mx + ans);

		evt.clear();
	}
	return 0;
}