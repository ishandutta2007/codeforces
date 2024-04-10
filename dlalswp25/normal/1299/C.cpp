#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<pair<int, int>, long long> pp;

int A[1010101];
int N;

set<pp> S;
queue<pp> q;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for(int i = 1; i <= N; i++) {
		pp tmp = {{i, i}, A[i]};
		S.insert(tmp);
		if(i < N && A[i] > A[i + 1]) q.push(tmp);
	}

	while(q.size()) {
		pp now = q.front(); q.pop();
		// printf("qq%d %d %lld\n", now.first.first, now.first.second, now.second);
		auto it = S.find(now);
		if(it == S.end()) continue;
		auto it2 = it; it2++;
		if(it2 == S.end()) continue;
		int l1 = (it -> first).first;
		int r1 = (it -> first).second;
		int l2 = (it2 -> first).first;
		int r2 = (it2 -> first).second;

		if(it -> second * (r2 - l2 + 1) < it2 -> second * (r1 - l1 + 1)) continue;

		ll s = it -> second + it2 -> second;
		S.erase(it);
		S.erase(it2);

		pp tmp = {{l1, r2}, s};
		S.insert(tmp);
		it = S.find(tmp);
		it2 = it; it2++;
		if(it2 != S.end()) {
			if(it -> second * (it2 -> first.second - it2 -> first.first + 1) > it2 -> second * (r2 - l1 + 1)) {
				q.push(tmp);
			}
		}

		if(it != S.begin()) {
			it2 = it; it2--;
			if(it -> second * (it2 -> first.second - it2 -> first.first + 1) < it2 -> second * (r2 - l1 + 1)) {
				q.push(*it2);
			}
		}

		// for(auto i : S) printf("%d %d %lld\n", i.first.first, i.first.second, i.second); puts("");
	}

	for(auto i : S) {
		int d = i.first.second - i.first.first + 1;
		for(int j = 0; j < d; j++) printf("%.12Lf\n", (long double)i.second / d);
	}

	return 0;
}