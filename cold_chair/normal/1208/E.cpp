#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 1e6 + 5;

int n, w, m, a[N], p[N], q[N];

ll f[N];
#define low(x) (x & (-x))
void add(int x, ll y) {
	for(; x <= w; x += low(x)) f[x] += y;
}
void add(int x, int y, ll z) {
	if(x > y) return;
	add(x, z); add(y + 1, -z);
}
ll sum(int x) {
	ll s = 0;
	for(; x; x -= low(x)) s += f[x];
	return s;
}

const int inf = 1e9;

#define i0 i + i
#define i1 i + i + 1
int t[N * 4];
void build(int i, int x, int y) {
	if(x == y)  { t[i] = a[x]; return;}
	int m = x + y >> 1;
	build(i0, x, m); build(i1, m + 1, y);
	t[i] = max(t[i1], t[i0]);
}
int pl, pr, px;
void ft(int i, int x, int y) {
	if(y < pl || x > pr) return;
	if(x >= pl && y <= pr) {
		px = max(px, t[i]); return;
	}
	int m = x + y >> 1;
	ft(i0, x, m); ft(i1, m + 1, y);
}

int main() {
	scanf("%d %d", &n, &w);
	fo(ii, 1, n) {
		scanf("%d", &m);
		fo(i, 1, m) {
			scanf("%d", &a[i]);
		}
		build(1, 1, m);
		p[0] = -inf;
		fo(i, 1, m) p[i] = max(p[i - 1], a[i]);
		q[m + 1] = -inf;
		fd(i, m, 1) q[i] = max(q[i + 1], a[i]);
		if(w <= 2 * m) {
			fo(i, 1, w) {
				pl = max(1, i + m - w), pr = min(m, i);
				px = -inf;
				if(i + m - w < 1 || i > m) px = 0;
				ft(1, 1, m);
				add(i, i, px);
			}
		} else {
			fo(i, 1, m) add(i, i, max(0, p[i]));
			fo(i, w - m + 1, w) add(i, i, max(0, q[m - (w - i + 1) + 1]));
			add(m + 1, w - m, max(0, p[m]));
		}
	}
		fo(i, 1, w) pp("%I64d ", sum(i));
}