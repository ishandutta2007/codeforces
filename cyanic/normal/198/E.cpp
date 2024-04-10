#include<bits/stdc++.h>
#define mp make_pair
#define lc (o << 1)
#define rc (o << 1 | 1)
#define mid ((l + r) >> 1)
using namespace std;
typedef pair<int,int> pii;
typedef long long LL;

const int maxn = 250005;
int x[maxn], y[maxn], m[maxn], p[maxn], rr[maxn];
int T[maxn<<2], q[maxn][2]; LL xx[maxn];
int X, Y, P, R, n, cnt, head, tail;
set<pii> s[maxn]; set<pii>::iterator it;

inline LL dist2(int x, int y) {
	return 1LL * x * x + 1LL * y * y;
}

void update(int o, int l, int r, int x, int y, int z) {
	if (l == r) { 
		s[l].insert(mp(y, z)); T[o] = min(T[o], y);
		return;
	}
	if (x <= mid) update(lc, l, mid, x, y, z);
	else update(rc, mid+1, r, x, y, z);
	T[o] = min(T[lc], T[rc]);
}

void query(int o, int l, int r, int x, int y, int z) {
	if (T[o] > z) return;
	if (l == r) {
		if (s[l].empty()) return;
		it = s[l].begin();
		while (it != s[l].end() && it->first <= z) {
			q[tail][0] = rr[it->second]; q[tail++][1] = p[it->second];
			s[l].erase(it++);
		}
		if (s[l].empty()) T[o] = 1e9;
		else T[o] = s[l].begin()->first;
		return;
	}
	if (y <= mid) query(lc, l, mid, x, y, z); 
	else if (mid < x) query(rc, mid+1, r, x, y, z);
	else {
		query(lc, l, mid, x, mid, z);
		query(rc, mid+1, r, mid+1, y, z);
	}
	T[o] = min(T[lc], T[rc]);
}

int main() {
	scanf("%d%d%d%d%d", &X, &Y, &P, &R, &n);
	for (int i=1; i<=n; i++) {
		scanf("%d%d%d%d%d", &x[i], &y[i], &m[i], &p[i], &rr[i]);
		xx[++cnt] = dist2(x[i] - X, y[i] - Y);
	}
	sort(xx+1, xx+cnt+1); cnt = unique(xx+1, xx+cnt+1)-xx-1;
	memset(T, 0x3f, sizeof T);
	for (int i=1; i<=n; i++)
		update(1, 1, cnt, lower_bound(xx+1, xx+cnt+1, dist2(x[i] - X, y[i] - Y)) - xx, m[i], i);
	q[tail][0] = R; q[tail++][1] = P;
	while (head < tail) {
		R = q[head][0]; P = q[head++][1];
		query(1, 1, cnt, 1, upper_bound(xx+1, xx+cnt+1, 1LL * R * R) - xx - 1, P);
	}
	printf("%d\n", tail - 1);
	return 0;
}