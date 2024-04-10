#include<stdio.h>
#include<deque>
using namespace std;

int a[212121], S[212121];
int cc[212121];
int is_er[212121];
int main() {
	int t, tc; scanf("%d", &t);
	for (tc = 0; tc < t; tc++) {
		int n, k, m;
		scanf("%d%d%d", &n, &k, &m);
		int v = k / 2;
		int i, j;
		for (i = 1; i <= n; i++)is_er[i] = 0;
		for (i = 1; i <= n; i++)a[i] = 1;
		for (i = 0; i < m; i++) {
			int x; scanf("%d", &x);
			a[x] = 0;
		}
		int cnt = 0;
		for (i = 1; i <= n; i++) {
			cnt += a[i];
		}
		if (cnt % (v * 2) != 0) {
			puts("NO");
			continue;
		}
		int vv = 0;;
		int l, r;
		for (i = 1; i <= n; i++) {
			S[i] = S[i - 1] + a[i];
		}
		for (i = 1; i <= n; i++) {
			vv += a[i];
			if (vv == v) {
				l = i + 1;
				break;
			}
		}
		vv = 0;
		for (i = n; i >= 1; i--) {
			vv += a[i];
			if (vv == v) {
				r = i - 1;
				break;
			}
		}
		int is_ans;
		if (S[r] - S[l - 1] == (r - l + 1))is_ans = 0;
		else is_ans = 1;
		puts(is_ans ? "YES" : "NO");
	}
	return 0;
}