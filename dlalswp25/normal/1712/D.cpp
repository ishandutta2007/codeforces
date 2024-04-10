#include <bits/stdc++.h>

using namespace std;

int N, K;
int A[101010];
bool chk[101010];

bool can(int x) {
	int cnt = 0, op = 0;
	for(int i = 1; i <= N; i++) {
		chk[i] = false;
		if(A[i] * 2 < x) { chk[i] = true; op++; }
		else if(A[i] >= x) chk[i] = true;
	}
	for(int i = 1; i <= N; i++) if(chk[i]) cnt++;
	if(!cnt) {
		if(K < op + 2) return false;
		else return true;
	}
	bool fg = false;
	for(int i = 1; i < N; i++) if(chk[i] && chk[i + 1]) fg = true;
	if(K < op + !fg) return false;
	return true;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		int l = 0, r = 1000000000;
		while(l <= r) {
			int m = l + r >> 1;
			if(can(m)) l = m + 1;
			else r = m - 1;
		}
		printf("%d\n", r);
	}
	return 0;
}