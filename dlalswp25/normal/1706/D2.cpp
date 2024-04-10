#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

const int MX = 100000;

int N, K;
int A[101010];
int cur[101010];
vector<int> V[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		for(int i = 0; i <= MX; i++) V[i].clear();
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		int mx = 0;
		for(int i = 1; i <= N; i++) {
			V[A[i] / K].push_back(i);
			cur[i] = K;
			mx = max(mx, A[i] / K);
		}
		int ans = 1010101010;

		for(int mn = 0; mn <= MX; mn++) {
			bool fin = false;
			for(int i : V[mn]) {
				ans = min(ans, mx - mn);
				if(cur[i] == 1) { fin = true; break; }
				if(mn == A[i] / (cur[i] - 1)) {
					if(!mn) cur[i] = A[i];
					else cur[i] = A[i] / (mn + 1);
				}
				else cur[i]--;
				mx = max(mx, A[i] / cur[i]);
				V[A[i] / cur[i]].push_back(i);
			}
			if(fin) break;
			V[mn].clear();
			V[mn].shrink_to_fit();
		}
		printf("%d\n", ans);
	}
	return 0;
}