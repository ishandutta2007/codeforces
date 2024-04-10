#include <bits/stdc++.h>
using namespace std;

double p[64], q[64], b[64];
int a[64][64];

void solve(int st, int en) {
	if (en == st+1) {
		p[st] = 1;
		return;
	}
	int mid = st + en >> 1;
	solve(st, mid);
	solve(mid, en);
	for (int i = st; i < en; i++) q[i] = 0;
	for (int i = st; i < mid; i++) {
		for (int j = mid; j < en; j++) {
			q[i] += p[j] * a[i][j] / 100;
			q[j] += p[i] * a[j][i] / 100;
		}
	}
	for (int i = st; i < en; i++) p[i] *= q[i];
	double l = *max_element(b + st, b + mid);
	double r = *max_element(b + mid, b + en);
	for (int i = st; i < mid; i++) b[i] += r + p[i] * (mid - st);
	for (int i = mid; i < en; i++) b[i] += l + p[i] * (mid - st);
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < 1<<n; i++) for (int j = 0; j < 1<<n; j++) scanf("%d", &a[i][j]);
	solve(0, 1<<n);
	double ans = *max_element(b, b + (1<<n));
	printf("%.12lf\n", ans);
	return 0;
}