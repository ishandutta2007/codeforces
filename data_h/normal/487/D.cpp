#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 100005, M = 15, TIMES = 10;;

int n, m, q;
char table[N][M];

struct Node {
	pair<int, int> go[M];
	Node() {}
};

Node tree[N << 2];

void update(int x, int l, int r) {
	int lc = (x << 1), rc = (x << 1 | 1);
	int mid = (l + r) >> 1;
	for(int i = 1; i <= m; i++) {
		if (tree[rc].go[i].second >= 1 && tree[rc].go[i].second <= m && tree[rc].go[i].first == mid + 1 && table[mid + 1][tree[rc].go[i].second] == '^') {
			tree[x].go[i] = tree[lc].go[tree[rc].go[i].second];
		} else {
			tree[x].go[i] = tree[rc].go[i];
		}
	}
}

void init(int x, int pos) {
	for(int i = 1; i <= m; i++) {
		int cx = pos, cy = i;
		for(int times = TIMES; times; times--) {
			if (cy < 1 || cy > m) {
				break;
			} else if (table[cx][cy] == '^') {
				break;
			} else if (table[cx][cy] == '<') {
				cy--;
			} else {
				cy++;
			}
		}
		tree[x].go[i] = make_pair(cx, cy);
	}
}

void build(int x, int l, int r) {
	if (l == r) {
		init(x, l);
	} else {
		int mid = (l + r) >> 1;
		build(x << 1, l, mid);
		build(x << 1 | 1, mid + 1, r);
		update(x, l, r);
	}
}

void modify(int x, int l, int r, int p) {
	if (l == r) {
		init(x, l);
	} else {
		int mid = (l + r) >> 1;
		if (p <= mid) {
			modify(x << 1, l, mid, p);
		} else {
			modify(x << 1 | 1, mid + 1, r, p);
		}
		update(x, l, r);
	}
}

pair<int, int> query(int x, int l, int r, int cx, int cy) {
	if (r == cx) {
		return tree[x].go[cy];
	}

	int mid = (l + r) >> 1;
	if (cx <= mid) {
		return query(x << 1, l, mid, cx, cy);
	} else {
		pair<int, int> ret = query(x << 1 | 1, mid + 1, r, cx, cy);
		if (ret.first > mid + 1 || ret.second > m || ret.second < 1 || table[ret.first][ret.second] != '^') {
			return ret;
		}
		return query(x << 1, l, mid, ret.first - 1, ret.second);
	}
}

void print(pair<int, int> answer) {
	if (answer.first == 1 && answer.second >= 1 && answer.second <= m && table[answer.first][answer.second] == '^') {
		answer.first--;
	}
	if (answer.second <= m && answer.second >= 1 && answer.first > 0) {
		printf("-1 -1\n");
	} else {
		printf("%d %d\n", answer.first, answer.second);
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 1; i <= n; i++) {
		scanf("%s", table[i] + 1);
	}
	build(1, 1, n);
	for(int i = 1; i <= q; i++) {
		static char buffer[N];
		int x, y;
		scanf("%s %d %d", buffer, &x, &y);
		if (buffer[0] == 'A') {
			print(query(1, 1, n, x, y));
		} else {
			scanf("%s", buffer);
			table[x][y] = buffer[0];
			modify(1, 1, n, x);
		}
	}
	return 0;
}