#include <bits/stdc++.h>

const int MAXN = 100010;
typedef long long LL;
typedef long double db;
typedef LL VT;
struct vec {
	VT x, y;
	vec() { x = y = 0; }
	vec(VT a, VT b) { x = a, y = b; }
	VT operator ^ (vec b) const { return x * b.y - y * b.x; }
	VT operator * (vec b) const { return x * b.x + y * b.y; }
	VT norm2() const { return x * x + y * y; }
	vec operator - (vec b) const { return vec(x - b.x, y - b.y); }
	vec operator + (vec b) const { return vec(x + b.x, y + b.y); }
	vec operator * (int k) const { return vec(x * k, y * k); }
	friend bool operator < (const vec & a, const vec & b) {
		return (a ^ b) > 0;
	}
	friend std::istream & operator >> (std::istream & in, vec & x) {
		in >> x.x >> x.y;
		return in;
	}
	friend std::ostream & operator << (std::ostream & out, vec x) {
		out << '(' << x.x << ',' << x.y << ')';
		return out;
	}
} ps[MAXN], qs[MAXN], cs[110];
int ts[MAXN], A[MAXN];
LL ansl[MAXN];
inline LL cross(vec a, vec b, vec c) {
	return (b - a) ^ (c - a);
}
int K, n, Q;

bool polar(vec x) {
	return x.y == 0 ? x.x < 0 : x.y < 0;
}
bool polarcmp(vec a, vec b) {
	return polar(a) == polar(b) ? a < b : polar(a) < polar(b);
}
const int MAXL = MAXN * 3;
LL tree[MAXL]; int bitsz;
void add(int x, int v) {
	for (; x <= bitsz; x += x & -x) tree[x] += v;
}
LL qry(int x) {
	LL res = 0;
	for (; x; x &= x - 1) res += tree[x];
	return res;
}
struct _ {
	int pol, dis, tar, coef;
	bool operator < (const _ & b) const {
		return pol < b.pol;
	}
} qrys[MAXL]; int bak;
typedef std::pair<LL, int> DL;
typedef std::pair<vec, int> VL;
template<typename T> int discretization(T arr, int L, int * tar) {
	std::sort(arr + 1, arr + 1 + L);
	int rnk = 0;
	for (int i = 1; i <= L; ++i) {
		rnk += !(i != 1 &&
			   !(arr[i - 1].first < arr[i].first) &&
			   !(arr[i].first < arr[i - 1].first));
		tar[arr[i].second] = rnk;
	}
	return rnk;
}
inline int sgn(LL x) { return x < 0 ? -1 : x > 0; }
LL tmp[MAXN], col[MAXN];
LL get(vec x, vec y) {
	return y.x ? std::abs(y ^ x) : x.x;
}
int rec[21][MAXN];
bool close[21][MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> K >> n >> Q;
	for (int i = 1; i <= K; ++i)
		std::cin >> cs[i], cs[i + K] = cs[i] * -1;
	for (int i = 1; i <= n; ++i) std::cin >> ps[i] >> A[i];
	for (int i = 1; i <= Q; ++i) std::cin >> qs[i] >> ts[i];
	K <<= 1;
	std::sort(cs + 1, cs + 1 + K, polarcmp);
	vec sm;
	for (int i = 1; i <= K; ++i)
		sm = sm + (cs[i] = cs[i - 1] + cs[i]);
	assert(sm.x % (K / 2) == 0); assert(sm.y % (K / 2) == 0);
	sm.x /= K / 2, sm.y /= K / 2;
	for (int i = 1; i <= K; ++i) cs[i] = cs[i] * 2 - sm;
	cs[K + 1] = cs[1];
	vec ori(-2e9, -2e9);
	for (int i = 1; i <= Q; ++i) {
		for (int j = 1; j <= K; ++j) {
			vec x = cs[j] * ts[i] + qs[i], y = cs[j + 1] * ts[i] + qs[i];
			rec[j][i] = sgn(cross(ori, x, y));
		}
		for (int j = 1; j <= K; ++j)
			if (rec[j == K ? 1 : j + 1][i] != rec[j][i])
				close[j][i] = true;
	}
	for (int T = 1; T <= K; ++T) {
		vec X = cs[T], Y = cs[T + 1], D = X - Y;
		if (D.x < 0) D = D * -1;
		static VL tv[MAXL]; static DL td[MAXL];
		static int nv[MAXL], nd[MAXL];
		bak = 0;
		for (int i = 1; i <= n; ++i) {
			++bak, tv[bak] = VL(ps[i] - ori, bak);
			td[bak] = DL(get(ps[i] - ori, D), bak);
			qrys[bak].tar = 0, qrys[bak].coef = A[i];
		}
		for (int i = 1; i <= Q; ++i) {
			vec x = X * ts[i] + qs[i], y = Y * ts[i] + qs[i];
			++bak, tv[bak] = VL(x - ori, bak);
			td[bak] = DL(get(x - ori, D), bak);
			qrys[bak].tar = i, qrys[bak].coef = 1;
			++bak, tv[bak] = VL(y - ori, bak);
			td[bak] = DL(get(y - ori, D), bak);
			qrys[bak].tar = i, qrys[bak].coef = -1;
		}
		int vsz = discretization(tv, bak, nv);
		bitsz = discretization(td, bak, nd);
		for (int i = 1; i <= bak; ++i) {
			qrys[i].pol = nv[i];
			qrys[i].dis = nd[i];
		}
		for (int i = 1; i <= bak; ++i) if (int u = qrys[i].tar) {
			if (rec[T][u] == 1) --qrys[i].pol;
			if (qrys[i].coef == -1 && close[T][u])
				qrys[i].pol += rec[T][u];
		}
		std::sort(qrys + 1, qrys + 1 + bak);
		int L = 1, R = 1;
		for (int i = 1; i <= vsz; ++i) {
			while (L <= bak && qrys[L].pol < i) ++L;
			while (R <= bak && qrys[R].pol <= i) ++R;
			for (int j = L; j < R; ++j) if (qrys[j].tar == 0)
				add(qrys[j].dis, qrys[j].coef);
			for (int j = L; j < R; ++j) if (qrys[j].tar > 0) {
				LL a = qry(qrys[j].dis), b = qry(qrys[j].dis - 1);
				tmp[qrys[j].tar] += a * qrys[j].coef;
				col[qrys[j].tar] += (a - b) * qrys[j].coef;
			}
			L = R;
		}
		for (int i = 1; i <= Q; ++i) {
			tmp[i] = std::abs(tmp[i]);
			col[i] = std::abs(col[i]);
			if (rec[T][i] == -1) tmp[i] -= col[i];
			ansl[i] += tmp[i] * rec[T][i];
			tmp[i] = col[i] = 0;
		}
		memset(tree, 0, bitsz + 1 << 3);
	}
	for (int i = 1; i <= Q; ++i) std::cout << ansl[i] << '\n';
	return 0;
}