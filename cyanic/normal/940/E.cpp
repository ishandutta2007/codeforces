#include<bits/stdc++.h>
#define mid ((l + r) >> 1)
#define lc (o << 1)
#define rc (o << 1 | 1)
using namespace std;
typedef long long LL;

const int maxn = 100005;
int T[maxn<<2], a[maxn], n, c;
LL f[maxn], sum;

void build(int o, int l, int r) {
	if (l == r) { T[o] = a[l]; return; }
	build(lc, l, mid); build(rc, mid+1, r);
	T[o] = min(T[lc], T[rc]);
}

int query(int o, int l, int r, int x, int y) {
	if (l == x && y == r) return T[o];
	if (y <= mid) return query(lc, l, mid, x, y);
	if (mid+1 <= x) return query(rc, mid+1, r, x, y);
	return min(query(lc, l, mid, x, mid), query(rc, mid+1, r, mid+1, y));
}

int main() {
	scanf("%d%d", &n, &c);
	for (int i=1; i<=n; i++) scanf("%d", &a[i]), sum += a[i];
	build(1, 1, n);
	for (int i=c; i<=n; i++)
		f[i] = max(f[i-c] + query(1, 1, n, i-c+1, i), f[i-1]);
	printf("%I64d\n", sum - f[n]);
	return 0;
}