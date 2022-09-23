#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

int N;
ll S;
vector<pair<int, pii> > adj[101010];
int sz[101010];
ll w[101010];
int c[101010];
priority_queue<pii> pq[3];

bool lf(int v) {
	return adj[v].size() == 1 && v != 1;
}

void dfs(int v, int p) {
	if(lf(v)) sz[v] = 1;
	else sz[v] = 0;
	for(auto i : adj[v]) {
		if(i.first == p) continue;
		w[i.first] = i.second.first;
		c[i.first] = (int)i.second.second;
		dfs(i.first, v);
		sz[v] += sz[i.first];
	}
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%lld", &N, &S);
		for(int i = 1; i <= N; i++) adj[i].clear();
		for(int i = 1; i < N; i++) {
			int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
			adj[a].push_back({b, {c, d}});
			adj[b].push_back({a, {c, d}});
		}

		dfs(1, 0);

		for(int i = 1; i <= 2; i++) {
			while(pq[i].size()) pq[i].pop();
		}

		ll sum = 0;
		for(int i = 2; i <= N; i++) {
			sum += (ll)w[i] * sz[i];
			pq[c[i]].emplace((w[i] + 1) / 2 * sz[i], i);
		}

		int ans = 0;
		while(sum > S) {
			ll s1 = 0, s2 = 0, s3 = 0, s4 = 0;
			if(pq[1].size()) {
				pii tmp = pq[1].top(); pq[1].pop();
				s4 = tmp.first;

				if(pq[1].size()) {
					s3 = tmp.first + pq[1].top().first;
				}
				s1 = tmp.first + (w[tmp.second] / 2 + 1) / 2 * sz[tmp.second];
				pq[1].push(tmp);
			}

			if(pq[2].size()) {
				s2 = pq[2].top().first;
			}

			if(sum - s4 <= S) {
				ans++; break;
			}

			int c = (max(s1, s3) >= s2 ? 1 : 2);

			pii t = pq[c].top(); pq[c].pop();
			sum -= t.first;

			w[t.second] /= 2;
			pq[c].emplace((w[t.second] + 1) / 2 * sz[t.second], t.second);
			ans += c;
		}
		printf("%d\n", ans);
	}
	return 0;
}