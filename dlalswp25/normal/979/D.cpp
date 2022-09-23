#include <stdio.h>
#include <set>

using namespace std;

set<int> S[100005];
bool chk[100005];

int main() {
	int Q; scanf("%d", &Q);
	for(int q = 0; q < Q; q++) {
		int t; scanf("%d", &t);

		if(t == 1) {
			int u; scanf("%d", &u);
			if(chk[u]) continue;
			chk[u] = true;

			for(int i = 1; i * i <= u; i++) {
				if(u % i) continue;
				S[i].insert(u);
				S[u / i].insert(u);
			}
		}

		else {
			int x, k, s; scanf("%d%d%d", &x, &k, &s);
			//S[k]
			if(s <= x) { puts("-1"); continue; }
			if(x % k) { puts("-1"); continue; }
			if(S[k].empty()) { puts("-1"); continue; }

			set<int>::iterator l, r;
			r = S[k].upper_bound(s - x);

			if(r == S[k].begin()) {
				puts("-1"); continue;
			}

			r--;
			l = S[k].begin();
			int now = 0;

			for(int i = 19; i >= 0; i--) {
				if((1 << i) & x) {
					// digit should be 0
					set<int>::iterator tmp = S[k].lower_bound(now | (1 << i));
					if(tmp == S[k].begin()) { now |= (1 << i); continue; }
					tmp--;

					if((*r) < (*tmp)) { continue; }
					if((*l) > (*tmp)) { now |= (1 << i); continue; }
					r = tmp;
				}
				else {
					// digit should be 1
					set<int>::iterator tmp = S[k].lower_bound(now | (1 << i));
					if(tmp == S[k].end()) continue;

					//printf("ang %d %d %d\n", *tmp, *l, *r);

					if((*r) < (*tmp)) continue;
					if((*l) > (*tmp)) { now |= (1 << i); continue; }
					l = tmp;
					now |= (1 << i);
				}
			}
			printf("%d\n", now);
		}
	}
	return 0;
}