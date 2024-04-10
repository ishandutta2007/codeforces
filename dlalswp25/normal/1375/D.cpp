#include <bits/stdc++.h>

using namespace std;

int N;
int A[1010];

bool fin[1010];
bool ok[1010];
vector<int> ans;

int mex() {
	for(int i = 0; i <= N; i++) ok[i] = false;
	for(int i = 0; i < N; i++) ok[A[i]] = true;
	for(int i = 0; i <= N; i++) if(!ok[i]) return i;
	return -1;
}

void upd(int x, int m) {
	ans.push_back(x + 1);
	A[x] = m;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ans.clear();
		scanf("%d", &N);
		for(int i = 0; i < N; i++) scanf("%d", &A[i]);
		for(int i = 0; i < N; i++) fin[i] = false;

		while(1) {
			int b = -1;
			for(int i = 0; i < N; i++) if(!fin[i]) { b = i; break; }
			if(b == -1) break;
			int m = mex();
			if(m == N) {
				int pos = 0;
				for(int i = 0; i < N; i++) {
					if(A[i] == b) { pos = i; break; }
				}
				upd(pos, N);
				m = mex();
				upd(b, b);
			}
			else {
				upd(m, m);
			}

			for(int i = 0; i < N; i++) if(A[i] == i) fin[i] = true;
		}

		printf("%d\n", ans.size());
		for(int i : ans) printf("%d ", i); puts("");
	}
	return 0;
}