#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, K;
int cnt[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		for(int i = 0; i <= N + 1; i++) cnt[i] = 0;
		map<int, int> mp;
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			mp[a]++;
			if(a <= N) cnt[a]++;
		}
		set<pii> S;
		for(auto& i : mp) S.insert({i.second, i.first});

		int l = 0, r = N;
		while(l <= r) {
			int m = l + r >> 1;
			set<pii> T = S;
			if(T.size() <= m) { r = m - 1; continue; }

			bool ok = false;
			int need = 0;
			int sum = 0;
			for(pii i : T) sum += i.first;

			auto it = prev(T.end());
			for(int i = 0; i < m; i++) {
				sum -= it->first;
				it--;
			}

			for(int i = 0; i <= N; i++) {
				if(need > K) break;
				if(sum <= K) { ok = true; break; }

				if(i == N) break;

				if(!cnt[i]) need++;
				if(need > K) break;
				if(T.find({cnt[i], i}) != T.end()) {
					if(*it <= pii(cnt[i], i)) {
						if(it == T.begin()) { ok = true; break; }
						sum -= it->first;
						it--;
					}
					else {
						sum -= cnt[i];
						T.erase(T.find({cnt[i], i}));
					}
				}
			}
			if(!ok) l = m + 1;
			else r = m - 1;
		}
		printf("%d\n", l);
	}
	return 0;
}