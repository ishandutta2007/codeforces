#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e6 + 7;
const int M = 22;

int f[N][M];
int fac[N];

void add(int &a, int b) {
	if ((a += b) >= MOD) {
		a -= MOD;
	}
}

vector<pair<int, int> > factor(int n) {
	vector<pair<int, int> > ret;
	while (n > 1) {
		int c = fac[n], cnt = 0;
		while (n % c == 0) {
			n /= c;
			cnt++;
		}
		ret.push_back({c, cnt});
	}
	return ret;
}

int main() {
	for (int i = 1; i < N; i++) fac[i] = i;
	for (int i = 2; i < N; i++) {
		for (int j = i + i; j < N; j += i) {
			fac[j] = min(fac[j], i);
		}
	}
	for (int j = 0; j < M; j++) {
		f[0][j] = 2;
	}
	f[0][0] = 1;
	for (int i = 1; i < N; i++) {
		int cur = 0;
		for (int j = 0; j < M; j++) {
			add(cur, f[i - 1][j]);
			f[i][j] = cur;
		}
	}
	int q;
	scanf("%d", &q);
	for (; q--; ) {
		int r, n;
		scanf("%d %d", &r, &n);
		vector<pair<int, int> > v = factor(n);
		int ans = 1;
		for (auto w : v) {
			//printf("(%d %d)\n", w.first, w.second);
			ans = 1LL * ans * f[r][w.second] % MOD;
		}
		printf("%d\n", ans);
	}
}