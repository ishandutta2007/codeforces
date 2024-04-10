#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 100005;
LL v[maxn], t[maxn], s[maxn], f[maxn], g[maxn];
int n, l, r, mid;

int main() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++) scanf("%I64d", &v[i]);
	for (int i=1; i<=n; i++) {
		scanf("%I64d", &t[i]);
		s[i] = s[i-1] + t[i];
	}
	for (int i=1; i<=n; i++) {
		l = i - 1; r = n;
		while (l < r) {
			mid = (l + r + 1) >> 1;
			if ((s[mid] - s[i-1]) <= v[i]) l = mid;
			else r = mid - 1;
		}
		f[i]++; f[l+1]--;
		g[l+1] += v[i] - (s[l] - s[i-1]);
	}
	for (int i=1; i<=n; i++) {
		f[i] += f[i-1];
		printf("%I64d ", f[i] * t[i] + g[i]);
	}
	return 0;
}