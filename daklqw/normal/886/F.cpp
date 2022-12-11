#include <bits/stdc++.h>

const int MAXN = 2010;
typedef long long LL;
typedef long double db;
typedef int VT;
struct vec {
	VT x, y;
	vec() { x = y = 0; }
	vec(VT a, VT b) { x = a, y = b; }
	LL operator ^ (vec b) const { return (LL) x * b.y - (LL) y * b.x; }
	LL operator * (vec b) const { return (LL) x * b.x + (LL) y * b.y; }
	vec operator - (vec b) const { return vec(x - b.x, y - b.y); }
	vec operator + (vec b) const { return vec(x + b.x, y + b.y); }
	vec operator * (int k) const { return vec(x * k, y * k); }
	friend std::istream & operator >> (std::istream & in, vec & x) {
		in >> x.x >> x.y;
		return in;
	}
	friend std::ostream & operator << (std::ostream & out, vec x) {
		out << '(' << x.x << ',' << x.y << ')';
		return out;
	}
	friend bool operator < (vec a, vec b) {
		return (a ^ b) > 0;
	}
	bool iszero() { return x == 0 && y == 0; }
} ps[MAXN], pt[MAXN];
std::vector<std::pair<vec, vec> > V;
int n;
vec red(vec x) {
	std::swap(x.x, x.y); x.x = -x.x;
	if (x.x < 0) x = x * -1;
	if (x.x == 0 && x.y != 0) x.y = -1;
	return x;
}
int rnk[MAXN];
int li[MAXN * MAXN], bak;
void swap(vec x) {
	++rnk[x.x], --rnk[x.y];
	// std::cout << "SWP " << x << std::endl;
	li[++bak] = x.x;
	li[++bak] = x.y;
}
void bye() {
	std::cout << -1 << std::endl;
	exit(0);
}
std::set<vec> S;
// std::map<vec, int> hav;
vec val[MAXN];
//void add(vec x) { ++hav[x]; }
//void dec(vec x) { if (!--hav[x]) hav.erase(x); }
void upd(int l) {
	if (l < 1 || l > n) return ;
	int r = n - l + 1;
	if (l > r) std::swap(l, r);
	if (r - l < 2) return ;
	// if (!val[l].iszero()) dec(val[l]);
	vec lhs = pt[l + 1] - pt[l];
	vec rhs = pt[r] - pt[r - 1];
	// val[l] = red(lhs - rhs);
	val[l] = lhs - rhs;
	// std::cout << "GET " << lhs << ' ' << rhs << " : " << val[l] << std::endl;
	// if (!val[l].iszero()) add(val[l]);
}
void push() {
	std::sort(li + 1, li + 1 + bak);
	bak = std::unique(li + 1, li + 1 + bak) - li - 1;
	//	std::cout << "PUSH: ";
	for (int i = 1; i <= bak; ++i) {
		pt[rnk[li[i]]] = ps[li[i]];
		// std::cout << li[i] << " -> " << rnk[li[i]] << std::endl;
	}
	for (int i = 1; i <= bak; ++i)
		for (int j = -1; j <= 1; ++j)
			upd(rnk[li[i]] + j);
	bak = 0;
}
int main() {
	// std::cout << "DBG: " << (vec(0, 5) ^ vec(0, -3)) << std::endl;
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> ps[i];
	auto cmp = [] (vec a, vec b) {
		return a.y == b.y ? a.x < b.x : a.y > b.y;
	};
	std::sort(ps + 1, ps + 1 + n, cmp);
	for (int i = 1; i <= n; ++i) rnk[i] = i, li[++bak] = i;
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j) {
			vec t = red(ps[j] - ps[i]);
			if (t.iszero() || t.x == 0) continue;
			V.emplace_back(t, vec(i, j));
		}
	std::sort(V.begin(), V.end());
	V.emplace_back(vec(0, 1), vec(0, 0));
	vec lst(0, -1);
	const int sz = V.size();
	for (int i = 0; i < sz; ) {
		vec spe = V[i].first;
		// calc
		push();
		{
			vec ch(0, 0);
			bool can = true;
			for (int l = 1, r = n; r - l >= 2; ++l, --r) {
				vec lhs = pt[l + 1] - pt[l];
				vec rhs = pt[r] - pt[r - 1];
				// std::cout << l << ' ' << r << " : " << lhs << ' ' << rhs << std::endl;
				vec sl = lhs - rhs;
				if (ch.iszero()) ch = sl;
				else {
					if ((ch ^ sl) != 0) {
						can = false;
						break;
					}
				}
			}
			if (can) {
				if (ch.iszero()) bye();
				ch = red(ch);
				if (!(ch < lst) && ch < spe) {
					// std::cout << "FINAL SLOPE " << ch << std::endl;
					S.insert(ch);
				}
			}
		}
		//	if (hav.size() <= 1) {
		//		if (hav.empty()) bye();
		//		auto ch = hav.begin()->first;
		//		if (!(ch < lst) && ch < spe) {
		//			S.insert(ch);
		//		}
		//	}
		// end
		while (i < sz && (V[i].first ^ spe) == 0)
			swap(V[i++].second);
		lst = spe;
	}
	std::cout << S.size() << std::endl;
	return 0;
}