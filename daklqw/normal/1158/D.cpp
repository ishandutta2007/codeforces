#include <bits/stdc++.h>

const int MAXN = 2010;
typedef long long LL;
typedef long double db;
typedef LL VT;
struct vec {
	VT x, y; int id;
	vec() { x = y = 0; }
	vec(VT a, VT b) { x = a, y = b; }
	VT operator ^ (vec b) const { return x * b.y - y * b.x; }
	VT operator * (vec b) const { return x * b.x + y * b.y; }
	VT norm2() const { return x * x + y * y; }
	db norm() const { return sqrt(x * x + y * y); }
	vec operator - (vec b) const { return vec(x - b.x, y - b.y); }
	vec operator + (vec b) const { return vec(x + b.x, y + b.y); }
	vec operator * (db k) const { return vec(x * k, y * k); }
	bool operator < (const vec & b) const {
		return x == b.x ? y < b.y : x < b.x;
	}
	friend std::istream & operator >> (std::istream & in, vec & x) {
		in >> x.x >> x.y;
		return in;
	}
	friend std::ostream & operator << (std::ostream & out, vec & x) {
		out << x.x << ' ' << x.y;
		return out;
	}

} ps[MAXN];
typedef std::vector<vec> VP;
inline VT cross(vec a, vec b, vec c) {
	return (b - a) ^ (c - a);
}
int n;
char buf[MAXN];
int ansl[MAXN];
bool vis[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> ps[i], ps[i].id = i;
	std::cin >> buf + 2;
	std::sort(ps + 1, ps + 1 + n);
	vis[ansl[1] = 1] = true;
	int now = 1;
	for (int i = 2; i < n; ++i) {
		int at = 0;
		for (int j = 1; j <= n; ++j) if (!vis[j]) {
			if (!at) at = j;
			else {
				if ((cross(ps[now], ps[at], ps[j]) < 0) == (buf[i] == 'L'))
					at = j;
			}
		}
		now = at; ansl[i] = at; vis[at] = true;
	}
	for (int i = 1; i <= n; ++i) if (!vis[i]) ansl[n] = i;
	for (int i = 1; i <= n; ++i) std::cout << ps[ansl[i]].id << ' ';
	return 0;
}