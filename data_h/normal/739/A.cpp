#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>
#include <cstring>
#include <string>

using namespace std;

const int N = 1e5 + 7;

int n, m;
int l[N], r[N];

int main() {
	scanf("%d %d", &n, &m);
	int min_v = N;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &l[i], &r[i]);
		min_v = min(min_v, r[i] - l[i] + 1);
	}
	printf("%d\n", min_v);
	for (int i = 0; i < n; i++) {
		printf("%d%c", i % min_v, i + 1 == n ? '\n' : ' ');
	}
	return 0;
}