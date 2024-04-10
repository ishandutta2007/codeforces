#include <bits/stdc++.h>

using namespace std;

int N;
char A[202020];
int P[202020];

vector<int> v[30];

struct FWT {
	int T[202020];

	void upd(int x) {
		for(int i = x; i <= N; i += i&-i) T[i]++;
	}
	int get(int x) {
		int ret = 0;
		for(int i = x; i; i -= i&-i) ret += T[i];
		return ret;
	}
}fwt;

int main() {
	scanf("%d", &N);
	scanf("%s", A + 1);

	for(int i = 1; i <= N; i++) v[A[i] - 'a'].push_back(i);
	for(int i = 0; i < 26; i++) {
		int m = v[i].size();
		for(int j = 0; j < m; j++) {
			P[v[i][j]] = N - v[i][m - 1 - j] + 1;
		}
	}

	long long ans = 0;
	for(int i = 1; i <= N; i++) {
		ans += i - 1 - fwt.get(P[i]);
		fwt.upd(P[i]);
	}
	printf("%lld\n", ans);

	return 0;
}