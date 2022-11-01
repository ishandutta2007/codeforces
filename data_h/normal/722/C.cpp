#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <map>

using namespace std;

const int N = 2e6 + 7;

int n;
int a[N], p[N];
int father[N];
long long sum[N], ans[N];
int visit[N];

int find(int x) {
	return father[x] == x ? x : father[x] = find(father[x]);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		visit[i] = 0;
		scanf("%d", &p[i]);
		p[i]--;
	}
	long long cur = 0;
	for (int i = n - 1; i >= 0; i--) {
		int pos = p[i];
		father[pos] = pos;
		visit[pos] = 1;
		sum[pos] = a[pos];
		if (pos > 0 && visit[pos - 1]) {
			int fu = find(pos - 1);
			int fv = find(pos);
			father[fu] = fv;
			sum[fv] += sum[fu];
			sum[fu] = 0;
		}
		if (pos + 1 < n && visit[pos + 1]) {
			int fu = find(pos + 1);
			int fv = find(pos);
			father[fu] = fv;
			sum[fv] += sum[fu];
			sum[fu] = 0;
		}
		ans[i] = cur;
		pos = find(pos);
		cur = max(cur, sum[pos]);
	}
	for (int i = 0; i < n; i++) {
		printf("%I64d\n", ans[i]);
	}
	return 0;
}