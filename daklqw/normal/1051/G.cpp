#include <bits/stdc++.h>

const int MAXN = 200010;
const int MAXP = MAXN * 20;
typedef long long LL;
int ls[MAXP], rs[MAXP], tot;
struct info {
	int a; LL b;
} tree[MAXP];
void mdf(int & u, int l, int r, int tar) {
	if (!u) u = ++tot;
	++tree[u].a, tree[u].b += tar;
	if (l == r) return ;
	int mid = l + r >> 1;
	if (tar <= mid) mdf(ls[u], l, mid, tar);
	else mdf(rs[u], mid + 1, r, tar);
}
LL ans;
int merge(int x, int y) {
	if (!x || !y) return x | y;
	ans += tree[ls[x]].b * tree[rs[y]].a;
	ans += tree[ls[y]].b * tree[rs[x]].a;
	ls[x] = merge(ls[x], ls[y]);
	rs[x] = merge(rs[x], rs[y]);
	tree[x].a += tree[y].a;
	tree[x].b += tree[y].b;
	return x;
}
struct itv {
	int l, r, rt;
	bool operator < (itv b) const {
		return l == b.l ? rt < b.rt : l < b.l;
	}
} ;
std::set<itv> S;
void ins(itv A) {
	auto it = S.insert(A).first, t = it;
	itv B; B.l = -1;
	if (++t != S.end() && A.r + 1 >= t->l) B = *t;
	else if ((t = it) != S.begin() && (--t)->r + 1 >= A.l)
		B = A, A = *t;
	if (B.l == -1) return ;
	S.erase(A), S.erase(B);
	ans -= tree[B.rt].b * (B.l - A.l);
	A.r += tree[B.rt].a;
	A.rt = merge(A.rt, B.rt);
	ins(A);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int Q, n; std::cin >> Q; n = Q;
	while (Q --> 0) {
		int x, y; std::cin >> x >> y;
		int tr = 0;
		mdf(tr, 1, n, y);
		ins((itv) {x, x, tr});
		std::cout << ans << '\n';
	}
	return 0;
}