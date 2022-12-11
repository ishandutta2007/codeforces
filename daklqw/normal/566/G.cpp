#include <bits/stdc++.h>

const int MAXN = 1e5 + 10;
typedef long long LL;

struct vec {
	int x, y;
	bool operator < (vec b) {
		return x == b.x ? y < b.y : x < b.x;
	}
	LL operator ^ (vec b) {
		return (LL) x * b.y - (LL) y * b.x;
	}
	vec operator - (vec b) {
		return (vec) {x - b.x, y - b.y};
	}
} ps[MAXN], st[MAXN], ori[MAXN];
LL cross(vec a, vec b, vec c) {
	return (b - a) ^ (c - a);
}

int top;
int n, m;

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int t; std::cin >> n >> m >> t >> t;
	for (int i = 1; i <= n; ++i)
		std::cin >> ori[i].x >> ori[i].y;
	for (int i = 1; i <= m; ++i)
		std::cin >> ps[i].x >> ps[i].y;
	std::sort(ps + 1, ps + 1 + m);
	for (int i = 1; i <= m; ++i) {
		while (top && st[top].x <= ps[i].x && st[top].y <= ps[i].y) --top;
		while (top > 1 && cross(st[top - 1], st[top], ps[i]) >= 0) --top;
		st[++top] = ps[i];
	}
	st[0].x = 0, st[0].y = st[1].y;
	st[top + 1].x = st[top].x, st[top + 1].y = 0;
	for (int i = 1; i <= n; ++i) {
		int l = 0, r = top, at = top + 1;
		vec _ = ori[i];
		while (l <= r) {
			int mid = l + r >> 1;
			if (_.x >= st[mid].x) at = mid, l = mid + 1;
			else r = mid - 1;
		}
		bool can = true;
		if (at == top + 1) can = false;
		else {
			if (cross(st[at], _, st[at + 1]) <= 0) can = false;
		}
		if (!can) {
			std::cout << "Max" << std::endl;
			return 0;
		}
	}
	std::cout << "Min" << std::endl;
	return 0;
}