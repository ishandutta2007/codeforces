#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, M, K;

vector<int> adj[101010];
bool vst[101010];
int deg[101010];
queue<int> q;

// codeforces.com/blog/entry/62393
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

unordered_map<ll, int, custom_hash> mp;

bool isEdge(int a, int b) {
	if(a > b) swap(a, b);
	ll x = (ll)a * (N + 1) + b;
	return mp[x];
}

int main() {
	// freopen("input.txt", "r", stdin);
	int tc; scanf("%d", &tc);
	while(tc--) {
		mp.clear();
		scanf("%d%d%d", &N, &M, &K);
		for(int i = 1; i <= N; i++) {
			adj[i].clear();
			deg[i] = 0;
			vst[i] = false;
		}
		while(q.size()) q.pop();

		for(int i = 1; i <= M; i++) {
			int a, b; scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
			deg[a]++; deg[b]++;
			if(a > b) swap(a, b);
			mp[(ll)a * (N + 1) + b]++;
		}

		for(int i = 1; i <= N; i++) {
			if(deg[i] < K) {
				vst[i] = true;
				q.push(i);
			}
		}

		while(q.size()) {
			int x = q.front(); q.pop();
			// printf("%d\n", x);
			// for(int i = 1; i <= N; i++) printf("%d ", deg[i]); puts("");
			for(int i : adj[x]) {
				if(vst[i]) continue;
				deg[i]--;
				if(deg[i] < K) {
					vst[i] = true;
					q.push(i);
				}
			}
		}

		int cnt = 0;
		for(int i = 1; i <= N; i++) if(!vst[i]) cnt++;
		if(cnt) {
			printf("1 %d\n", cnt);
			for(int i = 1; i <= N; i++) if(!vst[i]) printf("%d ", i);
			puts("");
			continue;
		}

		if((long long)K * (K - 1) / 2 > M) {
			puts("-1");
			continue;
		}

		for(int i = 1; i <= N; i++) {
			deg[i] = adj[i].size();
			vst[i] = false;
		}

		for(int i = 1; i <= N; i++) {
			if(deg[i] < K - 1) {
				vst[i] = true;
				q.push(i);
			}
		}

		while(q.size()) {
			int x = q.front(); q.pop();
			for(int i : adj[x]) {
				if(vst[i]) continue;
				deg[i]--;
				if(deg[i] < K - 1) {
					vst[i] = true;
					q.push(i);
				}
			}
		}

		for(int i = 1; i <= N; i++) {
			if(deg[i] == K - 1) {
				vst[i] = true; q.push(i);
			}
		}

		vector<int> v;
		while(q.size()) {
			int x = q.front(); q.pop();
			// printf("check %d\n", x);
			// printf("%d\n", deg[x]);
			if(deg[x] < K - 1) {
				for(int i : adj[x]) {
					if(deg[i] < K - 1) continue;
					deg[i]--;

					if(!vst[i] && deg[i] <= K - 1) {
						vst[i] = true;
						q.push(i);
					}
				}
				continue;
			}

			for(int i : adj[x]) {
				if(deg[i] < K - 1) continue;
				v.push_back(i);
			}
			v.push_back(x);

			if(v.size() < K) {
				v.clear();
				deg[x] = 0;
				for(int i : adj[x]) {
					if(deg[i] < K - 1) continue;
					deg[i]--;

					if(!vst[i] && deg[i] <= K - 1) {
						vst[i] = true;
						q.push(i);
					}
				}
				continue;
			}

			bool ok = true;
			for(int i = 0; i < v.size(); i++) {
				if(!ok) break;
				for(int j = 0; j < i; j++) {
					if(!isEdge(v[i], v[j])) {
						ok = false;
						break;
					}
				}
			}

			if(ok) break;
			v.clear();

			deg[x] = 0;
			for(int i : adj[x]) {
				if(deg[i] < K - 1) continue;
				deg[i]--;

				if(!vst[i] && deg[i] <= K - 1) {
					vst[i] = true;
					q.push(i);
				}
			}
		}

		if(v.size()) {
			puts("2");
			for(int i : v) printf("%d ", i); puts("");
		}
		else puts("-1");
	}
	return 0;
}