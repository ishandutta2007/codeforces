#include <bits/stdc++.h>
using namespace std;
int n, t, a[500009];
long long solvel(int x) {
	long long ret = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] < x) ret += x - a[i];
	}
	return ret;
}
long long solver(int x) {
	long long ret = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] > x) ret += a[i] - x;
	}
	return ret;
}
int main() {
	scanf("%d %d", &n, &t);
	long long sum = 0;
	for(int i = 0; i < n; i++) scanf("%d", &a[i]), sum += a[i];
	int pl = (sum + n - 1) / n, pr = sum / n;
	int l = 0, r = pr + 1;
	while(r - l > 1) {
		int m = (l + r) >> 1;
		if(solvel(m) > t) r = m;
		else l = m;
	}
	while(solvel(l) <= t && l <= pr) l++; l--;
	int l2 = pl, r2 = 1000000009;
	while(r2 - l2 > 1) {
		int m = (l2 + r2) >> 1;
		if(solver(m) > t) l2 = m;
		else r2 = m;
	}
	while(solver(r2) <= t && r2 >= pl) r2--; r2++;
	printf("%d\n", r2 - l);
	return 0;
}