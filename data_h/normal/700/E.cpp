#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

#define rank RANK

const int N = 2e5 + 10;
const int INF = 1e9;
const int LOG = 19;

int n;
char s[N];
int rank[N], height[N], sa[N], myLog2[N << 1];
int g[N][LOG];

int cmp(int *x, int a, int b, int d) {
	return x[a] == x[b] && x[a + d] == x[b + d];
}

void doubling(char *a, int n, int m) {
	static int sRank[N << 1], tmpA[N << 1], tmpB[N << 1];
	int *x = tmpA, *y = tmpB;
	for(int i = 0; i < m; ++ i) sRank[i] = 0;
	for(int i = 0; i < n; ++ i) ++ sRank[x[i] = a[i]];
	for(int i = 1; i < m; ++ i) sRank[i] += sRank[i - 1];
	for(int i = n - 1; i >= 0; -- i) sa[-- sRank[x[i]]] = i;

	for(int d = 1, p = 0; p < n; m = p, d <<= 1) {
		p = 0; for(int i = n - d; i < n; ++ i) y[p ++] = i;
		for(int i = 0; i < n; ++ i)
			if (sa[i] >= d) y[p ++] = sa[i] - d;
		for(int i = 0; i < m; ++ i) sRank[i] = 0;
		for(int i = 0; i < n; ++ i) ++ sRank[x[i]];
		for(int i = 1; i < m; ++ i) sRank[i] += sRank[i - 1];
		for(int i = n - 1; i >= 0; -- i) sa[-- sRank[x[y[i]]]] = y[i];
		swap(x, y); x[sa[0]] = 0; p = 1;
		for(int i = 1; i < n; ++ i)
			x[sa[i]] = cmp(y, sa[i], sa[i - 1], d) ? p - 1 : p ++;
	}

	for(int i = 0; i < n; ++ i) rank[sa[i]] = i;
	int cur = 0;
	for(int i = 0; i < n; ++ i) if (rank[i]) {
		if (cur) cur --;
		for( ; a[i + cur] == a[sa[rank[i] - 1] + cur]; ++ cur);
		height[rank[i]] = g[rank[i]][0] = cur;
	}
	for (int j = 0; j + 1 < LOG; j++) {
		for (int i = 1; i < n; i++) {
			g[i][j + 1] = g[i][j];
			if (i + (1 << j) < n) {
				g[i][j + 1] = min(g[i][j + 1], g[i + (1 << j)][j]);
			}
		}
	}
	myLog2[1] = 0;
	for (int i = 2; i <= n; i++) {
		myLog2[i] = myLog2[i / 2] + 1;
	}

}

int lcp(int i, int j) {
	if (i > j) swap(i, j);
	i++;
	assert(i <= j);
	int t = myLog2[j - i + 1];
	return min(g[i][t], g[j - (1 << t) + 1][t]);
}

pair<int, int> tree[N << 2];
int length[N];

pair<int, int> pos_tree[N << 2];

void build(int x, int l, int r) {
	tree[x] = make_pair(0, -1);
	pos_tree[x] = make_pair(INF, l);
	if (l == r) {
		return ;
	} else {
		int mid = l + r >> 1;
		build(x << 1, l, mid);
		build(x << 1 | 1, mid + 1, r);
	}
}

pair<int, int> ask(int x, int l, int r, int pos) {
	if (l == r) {
		return tree[x];
	} else {
		int mid = l + r >> 1;
		if (pos <= mid) {
			return max(tree[x], ask(x << 1, l, mid, pos));
		} else {
			return max(tree[x], ask(x << 1 | 1, mid + 1, r, pos));
		}
	}
}

void modify(int x, int l, int r, int ql, int qr, int end, int chain) {
	if (qr < l || r < ql) {
		return ;
	}
	if (ql <= l && r <= qr) {
		tree[x] = max(tree[x], make_pair(end, chain));
	} else {
		int mid = l + r >> 1;
		modify(x << 1, l, mid, ql, qr, end, chain);
		modify(x << 1 | 1, mid + 1, r, ql, qr, end, chain);
	}
}

void insert(int x, int l, int r, int pos, int tick) {
	if (l == r) {
		pos_tree[x] = make_pair(tick, l);
	} else {
		int mid = (l + r) >> 1;
		if (pos <= mid) insert(x << 1, l, mid, pos, tick);
		else 			insert(x << 1 | 1, mid + 1, r, pos, tick);
		pos_tree[x] = min(pos_tree[x << 1], pos_tree[x << 1 | 1]);
	}
}

pair<int, int> search(int x, int l, int r, int ql, int qr) {
	if (qr < l || r < ql) {
		return make_pair(INF, l);
	} else if (ql <= l && r <= qr) {
		return pos_tree[x];
	} else {
		int mid = l + r >> 1;
		return min(search(x << 1, l, mid, ql, qr),
					search(x << 1 | 1, mid + 1, r, ql, qr));
	}
}

void get_range(int &from, int &to, int j, int length) {
	int l = 0, r = j;
	while (l < r) {
		int mid = l + r >> 1;
		if (lcp(mid, j) < length) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	from = l;
	l = j, r = n;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (lcp(mid, j) < length) {
			r = mid - 1;
		} else {
			l = mid;
		}
	}
	to = l;
}

int main() {
	scanf("%d", &n);
	scanf("%s", s);
	s[n] = s[n + 1] = 0;

	doubling(s, n + 1, 256);

	// for (int i = 0; i <= n; i++) {
	// 	printf("%s\n", s + sa[i]);
	// }

	build(1, 0, n);
	int answer = 0;
	for (int i = n - 1; i >= 0; i--) {
		int j = rank[i];
		int length = 1, chain = 1;
		{
			pair<int, int> tmp = ask(1, 0, n, j);
			if (tmp.second > 0) {
				length = tmp.second;
				chain = tmp.first;

				int from, to;
				get_range(from, to, j, length);
				//printf("--- length = %d from %d to %d\n", length, from, to);
				//printf("sa = %d\n", sa[search(1, 0, n, from, to).second]);
				length = length + sa[search(1, 0, n, from, to).second] - i;
			}
		}
		//printf("suffix = %s length = %d chain = %d\n", s + i, length, chain);

		int from, to;
		get_range(from, to, j, length);
		insert(1, 0, n, j, i); //printf("insert %d\n", j);

		//printf("%d %d\n", from, to);
		modify(1, 0, n, from, to, chain + 1, length);
		answer = max(answer, chain);
	}
	printf("%d\n", answer);
	return 0;
}