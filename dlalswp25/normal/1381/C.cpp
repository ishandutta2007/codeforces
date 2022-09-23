#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, x, y;
int Z;
int B[101010];
bool chk[101010];
int ans[101010];
int cnt[101010];

vector<int> v[101010];
set<pii> S;
multiset<int> tmp;

void ins(int t) {
	if(cnt[t]) S.insert({cnt[t], t});
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d%d", &N, &x, &y);
		for(int i = 1; i <= N + 1; i++) {
			chk[i] = false;
			v[i].clear();
			cnt[i] = 0;
			ans[i] = -1;
		}
		tmp.clear();

		S.clear();

		for(int i = 1; i <= N; i++) {
			scanf("%d", &B[i]);
			chk[B[i]] = true;
			v[B[i]].push_back(i);
			cnt[B[i]]++;
			tmp.insert(B[i]);
		}
		for(int i = 1; i <= N + 1; i++) {
			if(!chk[i]) {
				Z = i; break;
			}
		}

		if(x > y) { puts("NO"); continue; }

		for(int i = 1; i <= N + 1; i++) {
			ins(i);
		}

		// printf("%d\n", Z);

		while(x) {
			y--; x--;
			auto it = S.end(); it--;
			int t = it -> second;

			ans[v[t].back()] = t;
			v[t].pop_back();

			tmp.erase(tmp.find(t));

			cnt[t]--;
			S.erase(it);
			ins(t);
		}

		while(y >= 2) {
			if(S.size() < 2) break;

			auto it = S.end(); it--;

			if(y == 3 && it -> first == 1) {
				vector<int> w;
				for(pii i : S) w.push_back(i.second);
				ans[v[w[0]].back()] = w[1];
				ans[v[w[1]].back()] = w[2];
				ans[v[w[2]].back()] = w[0];

				y = 0; break;
			}

			int t = it -> second;
			auto it2 = it; it2--;
			int s = it2 -> second;

			ans[v[t].back()] = s;
			ans[v[s].back()] = t;
			v[t].pop_back();
			v[s].pop_back();

			tmp.erase(tmp.find(s));
			tmp.erase(tmp.find(t));

			S.erase({cnt[t], t});
			S.erase({cnt[s], s});

			cnt[t]--; cnt[s]--;
			ins(s);
			ins(t);
			y -= 2;
		}

		// for(int i = 1; i <= N; i++) printf("%d ", ans[i]); puts("");

		if(y && S.size()) {
			int c = S.begin() -> second;
			for(int i : tmp) {
				if(!y) break;
				if(i == c) continue;
				ans[v[c].back()] = i;
				v[c].pop_back();
				y--;
			}
		}

		if(y) { puts("NO"); continue; }
		puts("YES");
		for(int i = 1; i <= N; i++) {
			if(ans[i] == -1) ans[i] = Z;
			printf("%d ", ans[i]);
		}
		puts("");
	}
	return 0;
}