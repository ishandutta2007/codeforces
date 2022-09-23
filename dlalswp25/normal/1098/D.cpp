#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

map<int, int> M;
ll T[500005];
int N = 1, Q;
pii q[500005];
pii A[500005];
int cv[500005];
set<pii> S;
set<int> cand;

void update(int x, int v) {
	for(int i = x; i <= N; i += i&-i) T[i] += v;
}

ll query(int x) {
	ll ret = 0;
	for(int i = x; i; i -= i&-i) ret += T[i];
	return ret;
}

int main() {
	int Q; scanf("%d", &Q);
	for(int i = 1; i <= Q; i++) {
		char c; int x; scanf(" %c%d", &c, &x);
		if(c == '+') {
			q[i] = {x, 1};
			A[N] = {x, i}; N++;
		}
		else q[i] = {x, -1};
	}
	N--;
	sort(A + 1, A + N + 1);

	for(int i = 1; i <= N; i++) {
		cv[A[i].second] = i;
	}

	int sz = 0;

	//for(int i = 1; i <= Q; i++) printf("%d ", cv[i]);

	for(int i = 1; i <= Q; i++) {
		if(q[i].second == 1) { // +
			sz++;

			S.insert({q[i].first, i});

			auto it = S.find({q[i].first, i});
			if(it == S.begin()) {
				cand.insert(it -> second);
			}
			else {
				auto tmp = it; tmp--;
				if(tmp -> first * 2 < it -> first) {
					cand.insert(it -> second);
				}
			}

			it++;

			if(it != S.end()) {
				if(it -> first <= 2 * q[i].first) {
					cand.erase(it -> second);
				}
			}

			update(cv[i], q[i].first);
		}
		else { // -
			sz--;

			//puts("*************");
			//for(int i : cand) printf("%d ", i); puts("");

			auto it = S.lower_bound({q[i].first, -1});
			if(cand.find(it -> second) != cand.end()) {
				cand.erase(it -> second);
			}
			auto tmp1 = it; tmp1++;

			update(cv[it -> second], -q[i].first);

			if(it == S.begin()) {
				if(tmp1 != S.end()) cand.insert(tmp1 -> second);
			}
			else {
				if(tmp1 != S.end()) {
					auto tmp2 = it; tmp2--;
					if(tmp2 -> first * 2 < tmp1 -> first) {
						cand.insert(tmp1 -> second);
					}
				}
			}

			S.erase(it);
		}

		// puts("************");

		// for(int i : cand) {
		// 	printf("%d ", i);
		// }
		// puts("");

		//calc ans

		//printf("%d\n", query(1));

		int ans = 0;
		for(int i : cand) {
			if(query(cv[i] - 1) * 2 < q[i].first) ans++;
		}
		//printf("%d %d\n", sz, ans);
		printf("%d\n", sz - ans);
	}

	return 0;
}