#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int A[2121212];
int g, h;
int N;

bool ok[1050505];
int pos[1050505];
int mn[1050505];

vector<int> V[525252];
vector<int> com;

void f(int x, int y) {
	int ax = A[x], ay = A[y];
	pos[ax] = y; pos[ay] = x;
	swap(A[x], A[y]);
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &h, &g);
		N = (1 << h);

		for(int i = 1; i < N; i++) { mn[i] = 987654321; ok[i] = false; }

		for(int i = 1; i < N; i++) {
			scanf("%d", &A[i]);
			com.push_back(A[i]);
		}

		sort(com.begin(), com.end());
		for(int i = 1; i < N; i++) {
			A[i] = lower_bound(com.begin(), com.end(), A[i]) - com.begin() + 1;
			pos[A[i]] = i;
		}

		int M = (1 << g);
		for(int i = M; i < N; i++) {
			int t = i;
			while(t >= M) t /= 2;
			V[t].push_back(A[i]);
		}

		ll ans = 0;
		for(int i = M / 2; i < M; i++) {
			V[i].push_back(A[i]);
			sort(V[i].begin(), V[i].end());
			reverse(V[i].begin(), V[i].end());

			int x = V[i].back();
			ok[x] = true;
			mn[i] = x;
			ans += com[x - 1];
			V[i].pop_back();
		}
		// printf("%lld\n", ans);

		for(int i = M / 2 - 1; i >= 1; i--) {
			int l = 2 * i, r = 2 * i + 1;
			int p = 0;
			int pl = 0, pr = 0;
			int mx = max(mn[l], mn[r]);

			while(V[l].size() && V[l].back() <= mx) V[l].pop_back();
			while(V[r].size() && V[r].back() <= mx) V[r].pop_back();

			while(pl < V[l].size() && pr < V[r].size()) {
				if(V[l][pl] > V[r][pr]) {
					V[i].push_back(V[l][pl]); pl++;
				}
				else {
					V[i].push_back(V[r][pr]); pr++;
				}
			}

			while(pl < V[l].size()) { V[i].push_back(V[l][pl]); pl++; }
			while(pr < V[r].size()) { V[i].push_back(V[r][pr]); pr++; }

			V[i].push_back(A[i]);

			// for(int j : V[i]) printf("%d ", j); puts("");
			for(int j = (int)V[i].size() - 1; j >= 1; j--) {
				if(V[i][j] > V[i][j - 1]) swap(V[i][j], V[i][j - 1]);
			}
			// for(int j : V[i]) printf("%d ", j); puts("");

			int x = V[i].back();
			ok[x] = true;

			ans += com[x - 1];
			mn[i] = x;
			V[i].pop_back();

			V[l].clear(); V[r].clear();
		}

		V[1].clear();

		// for(int i : tmp) printf("%d ", i); puts("");
		printf("%lld\n", ans);
		for(int i = 1; i < N; i++) {
			if(ok[i]) continue;
			int t = pos[i]; printf("%d ", t);

			while(1) {
				int l = 2 * t, r = 2 * t + 1;
				if(A[l] == 0 && A[r] == 0) { A[t] = 0; break; }
				if(A[l] > A[r]) {
					f(t, l); t = l;
				}
				else {
					f(t, r); t = r;
				}
			}
		}
		puts("");

		com.clear();
		for(int i = 1; i < N; i++) A[i] = 0;
	}
	return 0;
}