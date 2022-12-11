#include <bits/stdc++.h>

const int MAXN = 100010;

typedef long long LL;
typedef long double db;
typedef db VT;
struct vec {
	VT x, y;
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
	friend std::ostream & operator << (std::ostream & out, vec x) {
		out << '(' << x.x << ',' << x.y << ')';
		return out;
	}
} ps[MAXN];
typedef std::vector<vec> VP;
inline db cross(vec a, vec b, vec c) {
	return (b - a) ^ (c - a);
}
int n; LL T;
struct mat {
	db A[3][3];
	friend mat operator * (mat a, mat b) {
		mat res;
		for (int i = 0; i != 3; ++i)
			for (int j = 0; j != 3; ++j) {
				db t = 0;
				for (int k = 0; k != 3; ++k)
					t += a.A[i][k] * b.A[k][j];
				res.A[i][j] = t;
			}
		return res;
	}
} res;
db M = -1e10;
db make(const mat & A, vec B) {
	return vec(A.A[1][0] * M - A.A[0][0], 1) * B;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> T;
	for (int i = 1; i <= n; ++i) {
		int a, b; db p;
		std::cin >> a >> b >> p;
		M = std::max(M, p * b);
		ps[i] = vec(p, p * a);
	}
	std::sort(ps + 1, ps + 1 + n);
	int top = 0;
	for (int i = 1; i <= n; ++i) {
		vec now = ps[i];
		while (top > 1 && now.x >= ps[top].x && now.y >= ps[top].y) --top;
		while (top > 1 && cross(ps[top - 1], ps[top], now) >= 0) --top;
		ps[++top] = now;
	}
	res.A[1][0] = 0, res.A[2][0] = 1;
	for (int i = 1; i <= top; ++i) {
		static mat B[34];
		memset(B[0].A, 0, sizeof B[0].A);
		vec now = ps[i], nxt = ps[i + 1];
		B[0].A[0][0] = 1 - now.x;
		B[0].A[0][1] = now.x * M;
		B[0].A[0][2] = now.y;
		B[0].A[1][1] = B[0].A[1][2] = B[0].A[2][2] = 1;
		for (int j = 1; j != 34; ++j)
			B[j] = B[j - 1] * B[j - 1];
		for (int j = 33; ~j; --j)
			if ((1ll << j) <= T) {
				mat tmp = B[j] * res;
				if (i == top || make(tmp, now - nxt) >= 0) {
					res = tmp;
					T -= 1ll << j;
				}
			}
		if (T && (i == top || make(res, now - nxt) >= 0))
			--T, res = B[0] * res;
	}
	std::cout << std::fixed << std::setprecision(10);
	std::cout << res.A[0][0] << std::endl;
	return 0;
}