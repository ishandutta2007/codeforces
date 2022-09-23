#include <bits/stdc++.h>

using namespace std;

int N;
int X[70707];
int cnt[70707];
int pos[70707];
int ans[70707];

int qand(int i, int j) {
	printf("AND %d %d\n", i, j); fflush(stdout);
	int ret; scanf("%d", &ret);
	return ret;
}

int qxor(int i, int j) {
	printf("XOR %d %d\n", i, j); fflush(stdout);
	int ret; scanf("%d", &ret);
	return ret;
}

int main() {
	scanf("%d", &N);
	int s = -1, t;

	for(int i = 2; i <= N; i++) {
		X[i] = qxor(1, i);
		if(X[i] == 0) { s = 1; t = i; }
		else if(cnt[X[i]]) {
			s = pos[X[i]]; t = i;
		}

		cnt[X[i]]++;
		pos[X[i]] = i;
	}

	if(s != -1) {
		int a = qand(s, t);
		ans[s] = a;
		for(int i = 1; i <= N; i++) if(i != s) ans[i] = ans[s] ^ X[i] ^ X[s];
		printf("! ");
		for(int i = 1; i <= N; i++) printf("%d ", ans[i]); puts("");
		fflush(stdout);
		return 0;
	}

	int o1 = qand(1, pos[1]);
	int o2 = qand(1, pos[N / 2]);
	ans[1] = (o1 | o2);

	for(int i = 2; i <= N; i++) ans[i] = ans[1] ^ X[i];

	printf("! ");
	for(int i = 1; i <= N; i++) printf("%d ", ans[i]); puts("");
	fflush(stdout);

	return 0;
}