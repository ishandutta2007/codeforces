#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 300010
#define MAXS 1000010
#define LL long long
int pri[MAXS], tot, d[MAXS], tree2[MAXN << 2], from[MAXS], n, Q, sums[MAXN], t1, t2, t3;
LL tree1[MAXN << 2];
bool npri[MAXS];
void sieve() {
	d[1] = 1;
	for (int i = 2; i != MAXS; ++i) {
		if (!npri[i]) d[pri[++tot] = i] = 2, from[i] = 1;
		for (int j = 1; j <= tot; ++j) {
			int t = i * pri[j];
			if (t >= MAXS) break;
			npri[t] = true;
			if (i % pri[j] == 0) {
				from[t] = from[i];
				d[t] = d[from[i]] + d[i];
				break;
			}
			from[t] = i;
			d[t] = d[i] << 1;
		}	
	}
}
void update(int u) {
	tree1[u] = tree1[u << 1] + tree1[u << 1 | 1];
	tree2[u] = max(tree2[u << 1], tree2[u << 1 | 1]);
}
void build(int u, int l, int r) { if (l == r) return (void) (tree1[u] = tree2[u] = sums[l]); int mid = l + r >> 1; build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r); update(u); }
LL query(int u, int l, int r, int L, int R) {
	if (L <= l && r <= R) return tree1[u];
	int mid = l + r >> 1; LL res = 0;
	if (L <= mid) res += query(u << 1, l, mid, L, R);
	if (mid < R) res += query(u << 1 | 1, mid + 1, r, L, R);
	return res;
}
void modify(int u, int l, int r) {
	if (tree2[u] <= 2) return ;
	if (l == r) return (void) (tree1[u] = tree2[u] = d[tree1[u]]);
	int mid = l + r >> 1;
	modify(u << 1, l, mid); modify(u << 1 | 1, mid + 1, r);
	update(u);
}
void modify(int u, int l, int r, int L, int R) {
	if (tree2[u] <= 2) return ;
	if (L <= l && r <= R) return (void) modify(u, l, r);
	int mid = l + r >> 1;
	if (L <= mid) modify(u << 1, l, mid, L, R);
	if (mid < R) modify(u << 1 | 1, mid + 1, r, L, R);
	update(u);
}
int main() {
	sieve(); 
	scanf("%d%d", &n, &Q);
	for (int i = 1; i <= n; ++i) scanf("%d", &sums[i]);
	build(1, 1, n);
	while (Q --> 0) {
		scanf("%d%d%d", &t1, &t2, &t3);
		if (t1 == 1) modify(1, 1, n, t2, t3);
		else printf("%lld\n", query(1, 1, n, t2, t3));
	}
	return 0;
}