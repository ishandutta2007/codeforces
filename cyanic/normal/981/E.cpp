#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long long LL;

const int maxn = 10005;
bitset<maxn> T[maxn<<2];
vector<int> S[maxn<<2];
int n, Q, l, r, x, ans;

#define mid ((l + r) >> 1)
#define lc (o << 1)
#define rc (o << 1 | 1)
void update(int o, int l, int r, int x, int y, int z) {
	if (l == x && y == r) { S[o].push_back(z); return; }
	if (x <= mid) update(lc, l, mid, x, min(y, mid), z);
	if (mid < y) update(rc, mid+1, r, max(mid+1, x), y, z);
}

void solve(int o, int l, int r) {
	for (auto v : S[o])
		T[o] |= T[o] << v;
	if (l == r) return;
	T[lc] = T[o];
	solve(lc, l, mid);
	T[rc] = T[o];
	solve(rc, mid+1, r);
	T[o] = T[lc] | T[rc];
}

int main() {
	scanf("%d%d", &n, &Q);
	rep (i, 1, 4*n) T[i][0] = 1;
	while (Q--) {
		scanf("%d%d%d", &l, &r, &x);
		update(1, 1, n, l, r, x);
	}
	T[1][0] = 1; solve(1, 1, n);
	rep (i, 1, n) ans += T[1][i];
	printf("%d\n", ans);
	rep (i, 1, n) if (T[1][i]) printf("%d ", i);
	return 0;
}