#include <bits/stdc++.h>

using namespace std;

vector<int> s[1010];
vector<int> q;
int N, K;

bool chk[1010];
char buf[20];

int query() {
	printf("? %d ", q.size());
	for(int i : q) printf("%d ", i); puts("");
	q.clear();
	fflush(stdout);

	int x; scanf("%d", &x);
	return x;
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &N, &K);
		for(int i = 1; i <= K; i++) {
			s[i].clear();
			int c; scanf("%d", &c);
			for(int j = 0; j < c; j++) {
				int x; scanf("%d", &x);
				s[i].push_back(x);
			}
		}
		for(int i = 1; i <= N; i++) q.push_back(i);
		int mx = query();

		int l = 1, r = N;
		while(l < r) {
			int m = l + r >> 1;
			for(int i = l; i <= m; i++) q.push_back(i);
			int t = query();
			if(t == mx) r = m;
			else l = m + 1;
		}

		int tid = 0, tx;
		for(int i = 1; i <= K; i++) {
			bool ok = false;
			for(int j : s[i]) {
				if(j == l) {
					ok = true;
					break;
				}
			}

			if(ok) {
				tid = i;
				for(int j = 1; j <= N; j++) chk[j] = false;
				for(int j : s[i]) chk[j] = true;
				for(int j = 1; j <= N; j++) if(!chk[j]) q.push_back(j);
				tx = query();
			}
		}

		printf("! ");
		for(int i = 1; i <= K; i++) {
			if(i == tid) printf("%d ", tx);
			else printf("%d ", mx);
		}
		puts(""); fflush(stdout);
		scanf("%s", buf);
		if(buf[0] == 'I') break;
	}
	return 0;
}