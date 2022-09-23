#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, ll> pii;
typedef tuple<int, int, int, int> piiii;

const ll INF = 1LL << 60;

int N, M, K;
int X[101010];
set<pii> S[101010];
vector<piiii> adj[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d%d", &N, &M, &K);
		for(int i = 1; i <= N; i++) S[i].clear();
		for(int i = 1; i <= N; i++) adj[i].clear();
		for(int i = 1; i <= N; i++) scanf("%d", &X[i]);
		for(int i = 1; i <= K; i++) {
			int a, b, c, d, h; scanf("%d%d%d%d%d", &a, &b, &c, &d, &h);
			adj[a].emplace_back(b, c, d, h);
		}

		S[1].insert({1, 0});
		for(int i = 1; i <= N; i++) {
			if(!S[i].size()) continue;
			for(auto& j : adj[i]) {
				int b, c, d, h; tie(b, c, d, h) = j;
				auto it = S[i].lower_bound({b, -INF});
				ll mn = INF;
				if(it != S[i].end()) mn = min(mn, it->second + (ll)X[i] * abs(it->first - b));
				if(it != S[i].begin()) {
					it--;
					mn = min(mn, it->second + (ll)X[i] * abs(it->first - b));
				}

				mn -= h;

				pii t = {d, mn};

				bool add = true;
				while(S[c].size()) {
					auto it = S[c].lower_bound(t);
					if(it == S[c].end()) break;
					if(it->second + (ll)X[c] * abs(d - it->first) <= mn) { add = false; break; }
					else if(mn + (ll)X[c] * abs(d - it->first) <= it->second) S[c].erase(it);
					else break;
				}
				if(!add) continue;
				while(S[c].size()) {
					auto it = S[c].lower_bound(t);
					if(it == S[c].begin()) break;
					it--;
					if(it->second + (ll)X[c] * abs(d - it->first) <= mn) { add = false; break; }
					else if(mn + (ll)X[c] * abs(d - it->first) <= it->second) S[c].erase(it);
					else break;
				}
				if(!add) continue;
				S[c].insert(t);
			}
		}
		if(!S[N].size()) { puts("NO ESCAPE"); continue; }
		auto it = --S[N].end();
		printf("%lld\n", it->second + (ll)X[N] * abs(it->first - M));
	}
	return 0;
}