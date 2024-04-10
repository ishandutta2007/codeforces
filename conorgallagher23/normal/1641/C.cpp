#include <bits/stdc++.h>
#define mid (l + r >> 1)
#define ls (rt << 1)
#define rs (rt << 1 | 1) 
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int N = 200005;

int n, X, a[N], q, hd, t[N << 2];
set< int > s;
inline int pre(int x) {
	auto it = s.lower_bound(x);
	it--; return *it;
}
inline int suf(int x) {
	auto it = s.upper_bound(x);
	return *it;
}
void mdf(int rt, int l, int r, int pos, int val) {
	t[rt] = max(t[rt], val); if (l == r) return;
	(pos <= mid) ? mdf(ls, l, mid, pos, val) : mdf(rs, mid + 1, r, pos, val);
}
inline int qry(int rt, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) return t[rt];
	int ret = 0;
	if (ql <= mid) ret = max(ret, qry(ls, l, mid, ql, qr));
	if (qr > mid) ret = max(ret, qry(rs, mid + 1, r, ql, qr));
	return ret;
}
int main() {
	scanf("%d%d", &n, &q);
	for (int i = 0; i <= n + 1; i++) s.insert(i), a[i] = 1;
	while (q--) {
		int opt, l, r, x;
		scanf("%d", &opt);
		if (!opt) {
			scanf("%d%d%d", &l, &r, &x);
			if (!x) {
				while (1) {
					auto it = s.lower_bound(l);
					if ((*it) > r) break;
					a[*it] = 0; s.erase(it);
				}
			} else mdf(1, 1, n, r, l);
		} else {
			scanf("%d", &x);
			if (!a[x]) puts("NO");
			else {
				int l = pre(x), r = suf(x);
				if (qry(1, 1, n, x, r - 1) > l) puts("YES");
				else puts("N/A");
			}
		}
	}	
	return 0;
}