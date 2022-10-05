#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
#define lc (o << 1)
#define rc (o << 1 | 1)
#define mid ((l + r) >> 1)
using namespace std;
typedef long long LL;
 
const int maxn = 200005; const LL INF = 1e18;
LL T[maxn<<2], S[maxn<<2], ans = INF, base; int fa[maxn], fb[maxn];
int c0[maxn], c1[maxn], c2[maxn], c3[maxn], c[maxn];
int n, m, K, cnt, a, b, C0, C1, C2, C3, cur1, cur2;
 
int del(int x[maxn], int n) {
	int cnt = 1;
	rep (i, 2, n) if (x[i] != x[cnt]) x[++cnt] = x[i];
	return cnt;
}
 
void update(int o, int l, int r, int x, int y) {
	if (l == r) { T[o] += y; S[o] += y * c[x]; return; }
	if (x <= mid) update(lc, l, mid, x, y);
	else update(rc, mid+1, r, x, y);
	T[o] = T[lc] + T[rc]; S[o] = S[lc] + S[rc];
}
 
LL query(int o, int l, int r, int k) {
	if (l == r) return 1LL * c[l] * k;
	if (k <= T[lc]) return query(lc, l, mid, k);
	return S[lc] + query(rc, mid+1, r, k-T[lc]);
}
 
int main() {
	scanf("%d%d%d", &n, &m, &K);
	rep (i, 1, n) scanf("%d", &c[i]);
	scanf("%d", &a);
	rep (i, 1, a) scanf("%d", &b), fa[b] = 1;
	scanf("%d", &a);
	rep (i, 1, a) scanf("%d", &b), fb[b] = 1;
	
	rep (i, 1, n)
		if (fa[i] && fb[i]) c3[++C3] = c[i];
		else if (fa[i]) c1[++C1] = c[i];
		else if (fb[i]) c2[++C2] = c[i];
		else c0[++C0] = c[i];
	sort(c+1, c+n+1); cnt = del(c, n);
	
	rep (i, 1, C0) c0[i] = lower_bound(c+1, c+cnt+1, c0[i]) - c;
	rep (i, 1, C1) c1[i] = lower_bound(c+1, c+cnt+1, c1[i]) - c;
	rep (i, 1, C2) c2[i] = lower_bound(c+1, c+cnt+1, c2[i]) - c;
	rep (i, 1, C3) c3[i] = lower_bound(c+1, c+cnt+1, c3[i]) - c;
	sort(c0+1, c0+C0+1); sort(c1+1, c1+C1+1);
	sort(c2+1, c2+C2+1); sort(c3+1, c3+C3+1);
	
	rep (i, 1, C0) update(1, 1, cnt, c0[i], 1);
	rep (i, K+1, C1) update(1, 1, cnt, c1[i], 1);
	rep (i, 1, min(K, C1)) base += c[c1[i]], cur1 = i;
	rep (i, K+1, C2) update(1, 1, cnt, c2[i], 1);
	rep (i, 1, min(K, C2)) base += c[c2[i]], cur2 = i;
	rep (i, 1, C3) update(1, 1, cnt, c3[i], 1);
	rep (i, 0, min(C3, K)) {
		if (i + C2 >= K && i + C1 >= K) {
			while (cur2 && i + cur2 > K) {
				update(1, 1, cnt, c2[cur2], 1);
				base -= c[c2[cur2]];
				cur2--;
			}
			while (cur1 && i + cur1 > K) {
				update(1, 1, cnt, c1[cur1], 1);
				base -= c[c1[cur1]];
				cur1--;
			}
			if (K + K - i <= m) {
				ans = min(ans, base + query(1, 1, cnt, m - (K + K - i)));
			}
		}
		if (i+1 <= C3) {
			update(1, 1, cnt, c3[i+1], -1);
			base += c[c3[i+1]];
		}
	}
	if (ans >= INF) puts("-1");
	else printf("%I64d\n", ans);
	
	return 0;
}