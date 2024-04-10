#include <bits/stdc++.h>

using namespace std;

int N;
int st[32][101010];
int A[101010];
bool chk[101010];

int main() {
	scanf("%d", &N);
	int dup = 0;
	for(int i = 1; i <= N; i++) {
		scanf("%d", &st[0][i]);
		if(chk[st[0][i]]) dup++;
		chk[st[0][i]] = true;
	}

	set<int> rem;
	for(int i = 1; i <= N; i++) rem.insert(i);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		if(A[i] <= N) rem.erase(A[i]);
	}

	int mx = *max_element(A + 1, A + N + 1);
	int steps = (mx - N) / dup;

	for(int i = 1; i <= 30; i++) for(int j = 1; j <= N; j++) st[i][j] = st[i - 1][st[i - 1][j]];

	for(int i = 1; i <= N; i++) chk[i] = false;

	for(int i = 1; i <= N; i++) {
		int t = i;
		for(int j = 30; j >= 0; j--) {
			if(~steps & 1 << j) continue;
			t = st[j][t];
		}

		int ans = A[t];
		if(chk[ans]) ans = *rem.lower_bound(ans);
		printf("%d ", ans);
		chk[ans] = true;
		rem.erase(ans);
	}
	puts("");
	return 0;
}