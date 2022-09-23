#include <stdio.h>
#include <set>
#include <algorithm>

using namespace std;

int D[100005];
set<pair<int, int> > S[100005];

int main() {
	int N, M; scanf("%d%d", &N, &M);
	for(int i = 0; i < M; i++) {
		int s, e, w; scanf("%d%d%d", &s, &e, &w);
		set<pair<int, int> >::iterator it = S[s].lower_bound(make_pair(w, -1));
		D[i] = 1;
		if(it != S[s].begin()) {
			it--;
			D[i] = (it -> second) + 1;
		}

		bool ignore = false;
		while(1) {
			it = S[e].lower_bound(make_pair(w, -1));
			if(it == S[e].end()) break;
			if((it -> second) <= D[i]) S[e].erase(it);
			else if((it -> first) == w) { ignore = true; break; }
			else break;
		}
		it = S[e].lower_bound(make_pair(w, -1));
		if(it != S[e].begin()) {
			it--;
			if((it -> second) > D[i]) ignore = true;
		}
		if(ignore) continue;
		S[e].insert(make_pair(w, D[i]));
	}
	int ans = 0;
	for(int i = 0; i < M; i++) {
		ans = max(ans, D[i]);
	}
	printf("%d", ans);
	return 0;
}