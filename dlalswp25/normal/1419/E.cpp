#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, P;
vector<pii> p;
vector<int> ans;

void put(int x) {
	if(p.size() && p.back().first == x) p.back().second++;
	else p.emplace_back(x, 1);
}

void f(int idx, int c, int x) {
	if(idx == P) { if(c != N && c != x) ans.push_back(c); return; }

	for(int i = 0; i < p[idx].second; i++) c *= p[idx].first;
	for(int i = p[idx].second; i >= 0; i--) {
		f(idx + 1, c, x);
		c /= p[idx].first;
	}
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		p.clear(); ans.clear();
		scanf("%d", &N);
		int tmp = N;
		for(int i = 2; i * i <= tmp; ) {
			if(tmp % i) { i++; continue; }
			put(i); tmp /= i;
		}
		if(tmp > 1) put(tmp);

		P = p.size();
		if(P == 1) {
			int t = p[0].first;
			for(int i = 1; i <= p[0].second; i++) {
				printf("%d ", t);
				t *= p[0].first;
			}
			puts("");
			puts("0");
			continue;
		}

		if(P == 2 && p[0].second == 1 && p[1].second == 1) {
			printf("%d %d %d\n", p[0].first, p[1].first, N);
			puts("1");
			continue;
		}

		ans.push_back(N);
		for(int i = P - 1; i >= 0; i--) {
			if(i != P - 1) {
				int t = p[i].first;
				for(int j = 1; j <= p[i].second; j++) {
					f(i + 1, t, t);
					t *= p[i].first;
				}
			}
			int t = p[i].first;
			for(int j = 1; j <= p[i].second; j++) {
				ans.push_back(t);
				t *= p[i].first;
			}
		}

		for(int i : ans) printf("%d ", i); puts("");
		puts("0");
	}
	return 0;
}