#include<bits/stdc++.h>
typedef long long ll;

int n, m;
int a[100005], cnt;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), cnt += a[i];
	while (m--) {
		int typ; scanf("%d", &typ);
		if (typ == 1) {
			int x; scanf("%d", &x);
			cnt -= a[x]; a[x] ^= 1; cnt += a[x];
		}
		else {
			int x; scanf("%d", &x);
			printf("%d\n", cnt >= x);
		}
	}
}