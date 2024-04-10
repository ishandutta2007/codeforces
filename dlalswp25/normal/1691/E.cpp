#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int C[101010];
int L[101010];
int R[101010];
bool chk[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		for(int i = 1; i <= N; i++) chk[i] = false;
		vector<pii> E;
		for(int i = 1; i <= N; i++) {
			scanf("%d%d%d", &C[i], &L[i], &R[i]);
			E.emplace_back(L[i], -i);
			E.emplace_back(R[i], i);
		}
		set<pii> S[2];
		int ans = 0;
		sort(E.begin(), E.end());
		for(pii& e : E) {
			int i = e.second;
			int x = R[i < 0 ? -i : i];
			if(i < 0) {
				i = -i;
				if(S[1 - C[i]].size()) {
					if(S[C[i]].size()) {
						pii mx = *prev(S[C[i]].end());
						while(S[C[i]].size()) {
							pii t = *S[C[i]].begin();
							chk[t.second] = true;
							S[C[i]].erase(S[C[i]].begin());
						}
						if(mx.first < x) {
							S[C[i]].insert({x, i});
						}
						else {
							chk[i] = true;
							chk[mx.second] = false;
							S[C[i]].insert(mx);
						}
					}
					else {
						while(S[1 - C[i]].size() > 1) {
							pii t = *S[1 - C[i]].begin();
							chk[t.second] = true;
							S[1 - C[i]].erase(S[1 - C[i]].begin());
						}
						S[C[i]].insert({x, i});
					}
				}
				else S[C[i]].insert({x, i});
			}
			else {
				if(chk[i]) continue;
				if(!S[1 - C[i]].size()) ans++;
				S[C[i]].erase(S[C[i]].find({x, i}));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}