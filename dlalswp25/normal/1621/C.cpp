#include <bits/stdc++.h>

using namespace std;

int N;
int P[10101];
bool chk[10101];

int query(int x) {
	printf("? %d\n", x); fflush(stdout);
	int ret; scanf("%d", &ret);
	return ret;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) chk[i] = false;
		for(int i = 1; i <= N; i++) {
			if(chk[i]) continue;
			vector<int> v;
			while(1) {
				int t = query(i);
				v.push_back(t);
				if(chk[t]) break;
				chk[t] = true;
			}
			for(int j = 0; j < (int)v.size() - 1; j++) {
				P[v[j]] = v[j + 1];
			}
		}
		printf("! ");
		for(int i = 1; i <= N; i++) printf("%d ", P[i]); puts("");
		fflush(stdout);
	}
	return 0;
}