#include <bits/stdc++.h>

using namespace std;

int N, Q;
int A[202020];

int mn[202020];
int mx[202020];
int sz[202020];

vector<int> v;
bool c[202020];

int main() {
	scanf("%d%d", &N, &Q);
	for(int i = 1; i <= 200000; i++) mn[i] = N + 1;

	for(int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		mn[A[i]] = min(mn[A[i]], i);
		mx[A[i]] = max(mx[A[i]], i);
		sz[A[i]]++;
	}

	int p = 1;
	int b;

	int ans = 0;

	while(p <= N) {
		v.clear();
		v.push_back(A[p]);
		c[A[p]] = true;

		b = mx[A[p]]; p++;

		while(p <= b) {
			if(c[A[p]]) { p++; continue; }
			c[A[p]] = true;
			v.push_back(A[p]);
			b = max(b, mx[A[p]]);
			p++; continue;
		}

		int tmp = 0;
		for(int i : v) {
			tmp = max(tmp, sz[i]);
		}
		ans += tmp;
	}
	printf("%d\n", N - ans);
	return 0;
}