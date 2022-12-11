#include <bits/stdc++.h>

const int MAXN = 1010;
struct vec {
	int x, y, c, id;
	vec() { x = y = 0; }
	vec(int a, int b) { x = a, y = b; }
	vec operator + (vec b) const {
		return vec(x + b.x, y + b.y);
	}
	vec operator - (vec b) const {
		return vec(x - b.x, y - b.y);
	}
	int operator ^ (vec b) const {
		return x * b.y - y * b.x;
	}
	bool operator < (const vec & b) const {
		return x == b.x ? y < b.y : x < b.x;
	}
	friend std::ostream & operator << (std::ostream & out, vec x) {
		out << '(' << x.x << ',' << x.y << ',' << x.c << ',' << x.id << ')';
		return out;
	}
	friend std::istream & operator >> (std::istream & in, vec & x) {
		in >> x.x >> x.y >> x.c;
		return in;
	}
} ;
typedef std::vector<vec> VP;
int cross(vec a, vec b, vec c) {
	return (b - a) ^ (c - a);
}
void polar(VP & li) {
	std::iter_swap(li.begin(), std::min_element(li.begin(), li.end()));
	vec spe = li[0];
	const auto cmp = [spe] (vec a, vec b) {
		return cross(spe, a, b) > 0;
	};
	std::sort(li.begin() + 1, li.end(), cmp);
}
VP convex(VP li) {
	polar(li);
	static vec st[MAXN]; int top = 0;
	for (auto t : li) {
		while (top > 1 && cross(st[top - 1], st[top], t) <= 0) --top;
		st[++top] = t;
	}
	return VP(st + 1, st + 1 + top);
}
std::vector<std::pair<int, int> > ansl;
inline int sgn(int x) { return x < 0 ? -1 : (x > 0); }
inline bool contain(vec A, vec B, vec C, vec O) {
	int x = sgn(cross(A, B, O));
	int y = sgn(cross(B, C, O));
	int z = sgn(cross(C, A, O));
	return x && y && z && x == y && y == z;
}
int n;
VP ps;
void solve(vec A, vec B, vec C) {
	for (int i = 0; i < n; ++i)
		if (contain(A, B, C, ps[i]) && ps[i].c == A.c) {
			ansl.emplace_back(A.id, ps[i].id);
			solve(ps[i], B, C);
			solve(B, A, ps[i]);
			solve(C, A, ps[i]);
			return ;
		}
	for (int i = 0; i < n; ++i)
		if (contain(A, B, C, ps[i]))
			ansl.emplace_back(B.id, ps[i].id);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	ps.resize(n);
	int c1 = 0;
	for (int i = 0; i < n; ++i)
		std::cin >> ps[i], ps[i].id = i, c1 += ps[i].c;
	if (c1 == n || !c1) {
		for (int i = 1; i < n; ++i)
			ansl.emplace_back(0, i);
	} else {
		VP cx = convex(ps); const int S = cx.size();
		auto pr = [S] (int x) { x -= 1; return x + (x >> 31 & S); };
		auto nt = [S] (int x) { x += 1 - S; return x + (x >> 31 & S); };
		int l = -1, r = -1;
		for (int i = 0; i < S; ++i) if (cx[i].c != cx[0].c) {
			r = l = i; int ct = 0;
			while (cx[r].c == cx[l].c) r = nt(r), ++ct;
			for (auto t : cx) ct -= t.c != cx[0].c;
			if (ct) {
				std::cout << "Impossible" << std::endl;
				return 0;
			}
			break;
		}
		if (l == -1) {
			for (int i = 0; i + 1 < S; ++i)
				ansl.emplace_back(cx[i].id, cx[i + 1].id);
			for (int i = 0; i < n; ++i) if (ps[i].c != cx[0].c) {
				for (int j = 0; j < S; ++j)
					solve(ps[i], cx[j], cx[nt(j)]);
				break;
			}
		} else {
			auto solve = [pr, nt, cx] (int l, int r) {
				int now = l, tar = pr(l);
				while (nt(now) != r)  {
					int t = nt(now);
					ansl.emplace_back(cx[now].id, cx[t].id);
					::solve(cx[tar], cx[now], cx[t]);
					now = t;
				}
			};
			solve(l, r), solve(r, l);
		}
	}
	std::cout << ansl.size() << std::endl;
	for (auto t : ansl)
		std::cout << t.first << ' ' << t.second << '\n';
	return 0;
}