#include <bits/stdc++.h>
using namespace std;

const int N = 220000;
const int M = 1100000;
const int C = 20;
vector<int> A[M], R[M];
long long cn[N], sum[N], dap;
int p[N], c[N], l[N], r[N], pos[N], id[N], pw2[C];
void add(long long *x, int y, long long z) {
	for (; y < N; y += y & -y) x[y] += z;
}

long long get(long long *x, int y) {
	long long ret = 0;
	for (; y; y -= y & -y) ret += x[y];
	return ret;
}

int main() {
	pw2[0] = 1;
	for (int i = 1; i < C; i++) pw2[i] = pw2[i - 1] * 2;
	int n, k, m; scanf("%d%d%d", &n, &k, &m);
	for (int i = 1; i <= m; i++) scanf("%d%d%d%d", l + i, r + i, c + i, p + i);
	for (int i = 1; i <= m; i++) id[i] = i;
	sort(id + 1, id + m + 1, [](int i, int j) {
		return p[i] < p[j];
	});
	for (int i = 1; i <= m; i++) pos[id[i]] = i;
	for (int i = 1; i <= m; i++) {
		A[l[i]].push_back(i);
		R[r[i] + 1].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		for (auto e: A[i]) add(cn, pos[e], c[e]), add(sum, pos[e], c[e] * 1LL * p[e]);
		for (auto e: R[i]) add(cn, pos[e], -c[e]), add(sum, pos[e], -c[e] * 1LL * p[e]);
		if (get(cn, m) <= k) {
			dap += get(sum, m);
			continue;
		}
		int cur = 0;
		int cursum = 0;
		for (int j = C - 1; j >= 0; j--) {
			if (cur + pw2[j] > m) continue;
			if (cursum + cn[cur + pw2[j]] < k) cur += pw2[j], cursum += cn[cur];
		}
		cur++;
		cursum = get(cn, cur);
		dap += (get(sum, cur) - p[id[cur]] * 1LL * (cursum - k));
	}
	printf("%lld\n", dap);
	return 0;
}