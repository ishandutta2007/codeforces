#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
int D[1010];
bool chk[1010];
int C[1010];

int query(int u) {
	printf("? %d\n", u);
	fflush(stdout);
	int ret; scanf("%d", &ret);
	return ret;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		vector<pii> V;
		for(int i = 1; i <= N; i++) {
			scanf("%d", &D[i]);
			V.emplace_back(D[i], i);
		}
		for(int i = 1; i <= N; i++) {
			chk[i] = false; C[i] = 0;
		}
		sort(V.begin(), V.end());
		reverse(V.begin(), V.end());
		for(pii i : V) {
			int x = i.second;
			if(chk[x]) continue;
			vector<int> tmp = {x};
			chk[x] = true; C[x] = x;
			for(int j = 0; j < D[x]; j++) {
				int t = query(x);
				if(chk[t]) {
					for(int k : tmp) C[k] = C[t];
					break;
				}
				chk[t] = true;
				C[t] = x;
				tmp.push_back(t);
			}
		}
		printf("! ");
		for(int i = 1; i <= N; i++) printf("%d ", C[i]); puts("");
		fflush(stdout);
	}
	return 0;
}