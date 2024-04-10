#include <bits/stdc++.h>

using namespace std;

int N;
char A[404040];

int mn[25];
int tot[25];
int mp[25][404040];

int D[1050505][2];

int f(int state, int more) {
	int& ret = D[state][more];
	if(ret != -1) return ret;
	if(state == (1 << N) - 1 || !more) return ret = 0;
	int sum = 0;
	for(int i = 0; i < N; i++) if(state & 1 << i) sum += tot[i];
	for(int i = 0; i < N; i++) {
		if(state & 1 << i) continue;
		int nxtm = (sum + mn[i] >= 0);
		ret = max(ret, mp[i][sum] + f(state | 1 << i, nxtm));
	}
	return ret;
}

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf("%s", A + 1);
		int s = 0, m = 0;
		int M = strlen(A + 1);
		for(int j = 1; j <= M; j++) {
			if(A[j] == '(') s++;
			else s--;
			if(m >= s) mp[i][-s]++;
			m = min(m, s);
		}
		mn[i] = m; tot[i] = s;
	}

	for(int i = 0; i < 1 << N; i++) D[i][0] = D[i][1] = -1;

	printf("%d\n", f(0, 1));

	return 0;
}