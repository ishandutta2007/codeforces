#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N;
vector<int> adj[1010];
int b[1010];
int vst[1010];

int X[1010];
int Y[1010];

bool dfs(int v, int t) {
	if(vst[v] == t) return false;
	vst[v] = t;
	for(int i : adj[v]) {
		if(!b[i] || dfs(b[i], t)) {
			b[i] = v; return true;
		}
	}
	return false;
}

bool bmatch() {
	for(int i = 1; i <= N; i++) b[i] = vst[i] = 0;
	for(int i = 1; i <= N; i++) {
		if(!dfs(i, i)) return false;
	}
	return true;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &X[i]);
		for(int i = 1; i <= N; i++) scanf("%d", &Y[i]);
		vector<pair<int, pii>> E;
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				E.emplace_back(X[i] + Y[j], pii(i, j));
				E.emplace_back(abs(X[i] - Y[j]), pii(i, j));
			}
		}
		sort(E.begin(), E.end());
		int l = 0;
		bool ok = false;
		int G = 0;
		while(l < E.size()) {
			int r;
			for(r = l; r < E.size() && E[r].first == E[l].first; r++);
			if(r - l < N) { l = r; continue; }
			for(int i = 1; i <= N; i++) adj[i].clear();
			for(int i = l; i < r; i++) {
				adj[E[i].second.first].push_back(E[i].second.second);
			}
			if(bmatch()) {
				ok = true;
				G = E[l].first;
				break;
			}
			l = r;
		}
		if(!ok) { puts("NO"); continue; }
		puts("YES");
		int p1 = 0, p2 = G;
		vector<ll> ans;
		for(int i = 1; i <= N; i++) {
			int x = b[i], y = i;
			if(X[x] + Y[y] == G) ans.push_back(p1 + X[x]);
			else if(X[x] == Y[y] + G) ans.push_back((ll)p2 + Y[y]);
			else {
				assert(Y[y] == X[x] + G);
				ans.push_back(p1 - X[x]);
			}
		}
		ll offset = min({*min_element(ans.begin(), ans.end()), (ll)p1, (ll)p2});
		for(ll i : ans) printf("%lld ", i - offset); puts("");
		printf("%lld %lld\n", p1 - offset, p2 - offset);
	}
	return 0;
}