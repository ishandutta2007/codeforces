#include <bits/stdc++.h>

using namespace std;

int N, M;
int ans[303030];

struct Robot {
	int x, dir;
	int id;

	bool operator< (const Robot& o) const {
		return x < o.x;
	}
}A[303030];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i].x);
		for(int i = 1; i <= N; i++) {
			char c; scanf(" %c", &c);
			if(c == 'R') A[i].dir = 1;
			else A[i].dir = -1;
			A[i].id = i;
		}
		sort(A + 1, A + N + 1);

		for(int i = 1; i <= N; i++) ans[i] = -1;

		for(int z = 0; z < 2; z++) {
			vector<int> v, w;
			for(int i = 1; i <= N; i++) {
				if(A[i].x % 2 != z) continue;
				if(A[i].dir == 1) v.push_back(i);
				else {
					if(v.size()) {
						int r = v.back();
						ans[A[r].id] = ans[A[i].id] = (A[i].x - A[r].x) / 2;
						v.pop_back();
					}
					else w.push_back(i);
				}
			}

			reverse(w.begin(), w.end());
			while(w.size() > 1) {
				int a = w.back(); w.pop_back();
				int b = w.back(); w.pop_back();
				ans[A[a].id] = ans[A[b].id] = (A[a].x + A[b].x) / 2;
			}
			while(v.size() > 1) {
				int a = v.back(); v.pop_back();
				int b = v.back(); v.pop_back();
				ans[A[a].id] = ans[A[b].id] = (2 * M - (A[a].x + A[b].x)) / 2;
			}
			if(w.size() && v.size()) {
				int a = w[0], b = v[0];
				ans[A[a].id] = ans[A[b].id] = (2 * M - (A[b].x - A[a].x)) / 2;
			}
		}

		for(int i = 1; i <= N; i++) printf("%d ", ans[i]); puts("");
	}
	return 0;
}