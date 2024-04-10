#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int A[3030];
int B[3030];
vector<int> adj[3030];
bool chk[3030];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= 2 * N; i++) {
		scanf("%d%d", &A[i], &B[i]);
		adj[A[i]].push_back(B[i]);
		adj[B[i]].push_back(A[i]);
	}

	ll ans = 0;

	for(int i = 1; i <= 2 * N; i++) chk[i] = false;

	for(int i = 1; i <= 2 * N; i++) {
		if(chk[i]) continue;
		vector<int> v;
		int now = i;
		while(1) {
			v.push_back(now);
			chk[now] = true;
			if(chk[adj[now][0]]) {
				if(chk[adj[now][1]]) break;
				else now = adj[now][1];
			}
			else now = adj[now][0];
		}

		for(int z = 0; z < 2; z++) {
			int m = v.size();
			for(int j = 0; j < m; j++) {
				if(v[j] > N) continue;
				int lmn = v[j], lmx = v[j];
				int rmn = 2 * N, rmx = N + 1;

				int u = v[(j + m - 1) % m];

				for(int k = 1; k <= m; k++) {
					int w = v[(j + k) % m];
					if(k & 1) {
						rmn = min(rmn, w); rmx = max(rmx, w);

						int x = v[(j + k + 1) % m];
						int lu = N + 1, ld = 0;
						int ru = 2 * N + 1, rd = N;

						if(k < m) {
							if(lmn <= x && x <= lmx) continue;
							else if(x < lmn) ld = max(ld, x);
							else lu = min(lu, x);

							if(rmn <= u && u <= rmx) continue;
							else if(u < rmn) rd = max(rd, u);
							else ru = min(ru, u);
						}

						if(k == m && j) continue;

						ans += (ll)(ru - rmx) * (rmn - rd) * (lu - lmx) * (lmn - ld) * ((k + 1) / 2);
					}
					else {
						lmn = min(lmn, w); lmx = max(lmx, w);

						int x = v[(j + k + 1) % m];
						int lu = N + 1, ld = 0;
						int ru = 2 * N + 1, rd = N;

						if(k < m) {
							if(rmn <= x && x <= rmx) continue;
							else if(x < rmn) rd = max(rd, x);
							else ru = min(ru, x);

							if(rmn <= u && u <= rmx) continue;
							else if(u < rmn) rd = max(rd, u);
							else ru = min(ru, u);
						}

						if(k == m && (z || j)) continue;

						ans += (ll)(ru - rmx) * (rmn - rd) * (lu - lmx) * (lmn - ld) * ((k + 1) / 2);
					}
				}
			}

			for(int& i : v) {
				if(i > N) i -= N;
				else i += N;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}