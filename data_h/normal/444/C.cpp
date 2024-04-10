#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int N = 111111;

struct Sec {
	int l, r, x;
	Sec(int l = 0, int r = 0, int x = 0) : l(l), r(r), x(x) {
	}
	friend inline int operator < (const Sec &a, const Sec &b) {
		return a.l < b.l;
	} 
};

set<Sec> s;

struct Node {
	int l, r;
	long long sum, add;
}tree[N << 2];
int n, m;

void build(int x, int l, int r) {
	tree[x].l = l;
	tree[x].r = r;
	tree[x].sum = tree[x].add = 0;
	if (l == r)
		return;
	int mid = (l + r) / 2;
	build(x << 1, l, mid);
	build(x << 1 | 1, mid + 1, r);
}

void push(int x) {
	long long add = tree[x].add;
	tree[x].add = 0;
	tree[x << 1].add += add;
	tree[x << 1].sum += add * (tree[x << 1].r - tree[x << 1].l + 1);
	tree[x << 1 | 1].add += add;
	tree[x << 1 | 1].sum += add * (tree[x << 1 | 1].r - tree[x << 1 | 1].l + 1);
}

void update(int x) {
	tree[x].sum = tree[x << 1].sum + tree[x << 1 | 1].sum;
}

void insert(int x, int l, int r, int v) {
	if (l > tree[x].r || r < tree[x].l)
		return ;
	if (l <= tree[x].l && tree[x].r <= r) {
		tree[x].add += v;
		tree[x].sum += 1LL * v * (tree[x].r - tree[x].l + 1);
		return ;
	}
	push(x);
	insert(x << 1, l, r, v);
	insert(x << 1 | 1, l, r, v);
	update(x);
}

long long ask(int x, int l, int r) {
	if (l > tree[x].r || r < tree[x].l)
		return 0;
	if (l <= tree[x].l && tree[x].r <= r)
		return tree[x].sum;
	push(x);
	long long res = ask(x << 1, l, r) + ask(x << 1 | 1, l, r);
	update(x);
	return res;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		s.insert(Sec(i, i, i));
	}	
	build(1, 1, n);
	for(int i = 1; i <= m; i++) {
		int opt, l, r, x;
		scanf("%d %d %d", &opt, &l, &r);
		if (opt == 2) {
			printf("%I64d\n", ask(1, l, r));
		} else {
			scanf("%d", &x);
			set<Sec> :: iterator it;
			for(; ;) {
				it = s.lower_bound(Sec(l, 0, 0));
				if (it != s.end() && it->r <= r) {
					Sec tmp = *it;
					s.erase(it);
					insert(1, tmp.l, tmp.r, abs(tmp.x - x))	;
				} else if (it != s.end() && it->l <= r) {
					Sec tmp = *it;
					s.erase(it);
					s.insert(Sec(r + 1, tmp.r, tmp.x));
					insert(1, tmp.l, r, abs(tmp.x - x));
					break;
				} else {
					break;
				}
			}
			it = s.lower_bound(Sec(l, 0, 0));
			if (it != s.begin()) {
				--it;
				if (it->r >= l) {
					Sec tmp = *it;
					s.erase(it);
					s.insert(Sec(tmp.l, l - 1, tmp.x));
					if (tmp.r > r) {
						s.insert(Sec(r + 1, tmp.r, tmp.x));
					}
					insert(1, l, min(tmp.r, r), abs(tmp.x - x));
				}
			}
			s.insert(Sec(l, r, x));
		}
	}
	return 0;
}