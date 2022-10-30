#include<bits/stdc++.h>
using namespace std;
const int N = 1000000+10;

int s[N], g[N];
int L[N], R[N];
int p[N];

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d%d", s+i, g+i);
	L[1] = s[1], R[1] = s[1] + g[1];
	for (int i = 2; i <= n; i ++) {
		L[i] = max(s[i], L[i - 1] - 1), R[i] = min(s[i] + g[i], R[i - 1] + 1);
		if (R[i] < L[i]) return puts("-1"), 0;
	}
	p[n] = R[n];
	for (int i = n - 1; i >= 1; i --) {
		for (p[i] = p[i + 1] + 1; p[i] > p[i + 1] - 2; p[i] --) {
			if (L[i] <= p[i] && p[i] <= R[i]) break;
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i ++) ans += (p[i] - s[i]);
	cout << ans << endl;
	for (int i = 1; i <= n; i ++) printf("%d ", p[i]);
	return 0;
}