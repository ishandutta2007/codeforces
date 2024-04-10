#include <bits/stdc++.h>
using namespace std;

struct PT {
    long long x, y;
    PT(long long x = 0, long long y = 0) : x(x), y(y) {};
};

vector<PT> V;

long long calc(long long a, long long b) {
    assert(b > 0);
    if (a >= 0 || a % b == 0) return a / b;
    return a / b - 1;
}
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using VI = vector<int>;
using LL = long long;
struct BI {
	static const int B = 1<<30;
private:
	VI v;

	inline void push(LL x) {
		for (; x; x /= B) v.push_back(x % B);
	}

	inline void pop() {
		while (!v.empty() && !v.back()) v.pop_back();
	}

	void mul_add(LL x, LL y) { // B * x + y <= LONG_LONG_MAX
		for (int i = 0; i < sz(v); i++) {
			y += v[i] * x;
			v[i] = y % B;
			y /= B;
		}
		push(y);
		pop();
	}

public:
	void add(LL x) {
		mul_add(1, x);
	}

	void sub(LL x) {
		x = -x;
		for (int i = 0; i < sz(v); i++) {
			x += v[i];
			v[i] = x % B;
			if (v[i] < 0) v[i] += B;
			x = (x - v[i]) / B;
		}
//		assert(x == 0);
		pop();
	}

	void mul(LL x) { // B * x <= LONG_LONG_MAX
		mul_add(x, 0);
	}

	LL div(int x) {
		LL r = 0;
		for (int i = sz(v) - 1; i >= 0; i--) {
			r = r * B + v[i];
			v[i] = r / x;
			r %= x;
		}
		pop();
		return r;
	}

	int mod(int x) {
		LL r = 0;
		for (int i = sz(v) - 1; i >= 0; i--) r = (r * B + v[i]) % x;
		return r;
	}

	inline bool zero() {
		return v.empty();
	}

	BI(LL x = 0) {
		v.clear();
		push(x);
	}

	BI(const char *s) {
		v.clear();
		for (int i = 0; s[i]; i++) {
			mul(10);
			add(s[i] - '0');
		}
		pop();
	}

	BI(VI vv) : v(vv) {}

	LL to_LL() {
		LL x = 0;
		for (int i = sz(v) - 1; i >= 0; i--) x = x * B + v[i];
		return x;
	}

	VI convert(int base) {
		BI a = *this;
		VI ret;
		while (!a.zero()) ret.push_back(a.div(base));
		return ret;
	}

	void to_str(char *s) {
		VI a = convert(1000000000);
		int sn = 0;
		for (int i = sz(a) - 1; i >= 0; i--) {
			if (i == sz(a) - 1) {
				for (int j = 0, x = a[i]; x; x /= 10)
s[sn++] = x % 10 + '0';
				reverse(s, s + sn);
			} else {
				for (int j = 0, x = a[i]; j < 9; x /= 10, j++)
s[sn++] = x % 10 + '0';
				reverse(s + sn - 9, s + sn);
			}
		}
		if (!sn) s[sn++] = '0';
		s[sn] = 0;
	}

	void print() {
		VI a = convert(1000000000);
		if (zero()) {
			puts("0");
			return;
		}
		for (int i = sz(a) - 1; i >= 0; i--) {
			if (i == sz(a) - 1) {
				printf("%d", a[i]);
			} else {
				printf("%09d", a[i]);
			}
		}
		puts("");
	}

	bool operator<(const BI& b) const {
		int m = sz(v), n = sz(b.v);
		if (m != n) return m < n;
		for (int i = m - 1; i >= 0; i--) {
			if (v[i] != b.v[i]) return v[i] < b.v[i];
		}
		return 0;
	}

	bool operator==(const BI& b) const {
		return v == b.v;
	}

	BI operator+(const BI& b) const {
		BI c;
		int m = sz(v), n = sz(b.v);
		int i, k = max(m, n), r = 0;
		for (i = 0; i < k; i++) {
			if (i < m) r += v[i];
			if (i < n) r += b.v[i];
			c.v.push_back(r % B);
			r /= B;
		}
		c.push(r);
		return c;
	}

	BI operator-(const BI& b) const {
		BI c;
		int m = sz(v), n = sz(b.v);
		int i, r = 0, t;
		for (i = 0; i < m; i++) {
			r += v[i];
			if (i < n) r -= b.v[i];
			t = (r + B) % B;
			c.v.push_back(t);
			r = (r - t) / B;
		}
		c.pop();
		return c;
	}

	BI operator*(const BI& b) const {
		BI c;
		int m = sz(v), n = sz(b.v);
		c.v.resize(m + n);
		for (int i = 0; i < m; i++) {
			LL r = 0;
			for (int j = 0; j < n; j++) {
				r += LL(v[i]) * b.v[j] + c.v[i + j];
				c.v[i + j] = r & B-1;
				r >>= 30;
			}
			c.v[i + n] += r;
		}
		c.pop();
		return c;
	}

	BI operator/(const BI& b) const {
		int m = sz(v), n = sz(b.v);
		if (m < n) return BI();
		BI q, r;
		if (n == 1) {
			q = *this;
			assert(b.v[0] > 0);
			q.div(b.v[0]);
			return q;
		}
		for (int i = m - n + 1; i < m; i++) r.v.push_back(v[i]);
		for (int i = m - n; i >= 0; i--) {
			r.mul_add(B, v[i]);
			LL den = b.v[n - 1];
			LL nom = (sz(r.v) < n ? 0 :
(sz(r.v) == n ? r.v.back() :
(LL)B * r.v.back() + r.v[sz(r.v) - 2]));
			int st = nom / (den + 1), en = nom / den + 1;
			while (en - st > 1) {
				int mid = st + en >> 1;
				BI t = b; t.mul(mid);
				if (r < t) en = mid;
				else st = mid;
			}
			BI t = b; t.mul(st); r = r - t;
			q.v.push_back(st);
		}
		reverse(all(q.v));
		q.pop();
		return q;
	}

/*Fast But Dangerous
BI operator/(const BI& b) const {
	int m = sz(v), n = sz(b.v);
	if (m < n) return BI();
	BI q, r;
	if (n == 1) {
		q = *this;
		assert(b.v[0] > 0);
		q.div(b.v[0]);
		return q;
	}
	for (int i = m - n + 1; i < m; i++) r.v.push_back(v[i]);
	for (int i = m - n; i >= 0; i--) {
		r.mul_add(B, v[i]);
		LL den = b.v[n - 1];
		LL nom = (sz(r.v) < n ? 0 :
(sz(r.v) == n ? r.v.back() :
(LL)B * r.v.back() + r.v[sz(r.v) - 2]));
		int st = nom / (den + 1), en = nom / den + 1;
		while (en - st > 1) {
			int mid = st + en >> 1;
			BI t = b; t.mul(mid);
			if (r < t) en = mid;
			else st = mid;
		}
		BI t = b; t.mul(st); r = r - t;
		q.v.push_back(st);
	}
	reverse(all(q.v));
	q.pop();
	return q;
}
     */

	BI power(int n) {
		BI ret = BI(1), a = *this;
		for (; n; n >>= 1, a = a * a) if (n & 1) ret = ret * a;
		return ret;
	}

	BI root(int m) {
		int n = v.size();
		int k = (n - 1) / m;
		BI q, r;
		for (int i = k; i >= 0; i--) {
			r.v.clear();
			for (int j = i * m; j < n; j++) r.v.push_back(v[j]);
			q.v.push_back(0);
			for (int j = sz(q.v) - 1; j > 0; j--) q.v[j] = q.v[j - 1];
			q.v[0] = 0;
			int st = 0, en = B;
			while (en - st > 1) {
				int mid = st + en >> 1;
				q.v[0] = mid;
				BI t = q.power(m);
				if (!(r < t)) st = mid;
				else en = mid;
			}
			q.v[0] = st;
		}
		return q;
	}
};




struct bigint {
	BI b;
	int sgn;
	bigint(long long x = 0) {
		if (x >= 0) sgn = 1, b = BI(x);
		else sgn = -1, b = BI(-x);
	}
	bigint(char *s) {
		if (s[0] == '-') {
			sgn = -1;
			b = BI(s+1);
		} else {
			sgn = 1;
			b = BI(s);
		}
	}
	bigint(BI b_, int sgn_) : b(b_), sgn(sgn_) {
		if (b.zero()) sgn = 1;
	}
	bigint operator +(const bigint &x) const{
		if (sgn == x.sgn) {
			return bigint(b + x.b, sgn);
		} else {
			if (b < x.b) return bigint(x.b-b, sgn*-1);
			else return bigint(b-x.b, sgn);
		}
	}
	bigint operator -(const bigint &x) const {
		if (sgn != x.sgn) {
			return bigint(b + x.b, sgn);
		} else {
			if (b < x.b) return bigint(x.b-b, sgn*-1);
			else return bigint(b-x.b, sgn);
		}
	}
	bigint operator *(const bigint &x) const {
		return bigint(b * x.b, sgn * x.sgn);
	}
	bigint operator /(const bigint &x) const {
		return bigint(b / x.b, sgn * x.sgn);
	}
	bigint operator %(const bigint &x) const {
		return bigint(b - (b / x.b) * x.b, 1);
	}
	bool operator <(const bigint &x) const {
		if (sgn != x.sgn) return sgn < x.sgn;
		if (sgn > 0) return b < x.b;
		return x.b < b;
	}
	bool operator ==(const bigint &x) const {
		return b == x.b && sgn == x.sgn;
	}
	bigint power(int x) {
		int sss = 1;
		if ((x & 1) && sgn < 0) sss = -1;
		return bigint(b.power(x), sss);
	}
	friend bigint gcd(bigint A, bigint B) {
		return (B.b.zero()) ? A : gcd(B, A % B);
	}
	void print() {
		if (sgn < 0) putchar('-');
		b.print();
	}
};

bool cross(PT p, PT p1, PT p2) {
    bigint dx1(p1.x - p.x);
    bigint dy1(p1.y - p.y);
    bigint dx2(p2.x - p.x);
    bigint dy2(p2.y - p.y);
    if (dx2 * dy1 < dy2 * dx1) return true;
    return false;
}

long long func(PT p, long long x, long long y) {
    return y + x * p.x + p.y;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    long long sz = n;
    V.emplace_back(0, 0);
    long long adds = 0, addb = 0;
    for (int i = 1; i <= m; i++) {
        int op; cin >> op;
        if (op == 1) {
            long long x; cin >> x;
            adds = 0;
            addb = 0;
            sz += x;
            V.clear();
            V.emplace_back(0, 0);
        } else if (op == 2) {
            long long x; cin >> x;
            PT cur = (PT){sz, -addb - adds * sz};
            while (V.size() > 1 && !cross(V[V.size()-2], V.back(), cur)) V.pop_back();
            V.push_back(cur);
            sz += x;
        } else {
            long long b, s; cin >> b >> s;
            addb += b;
            adds += s;
        }
        while (V.size() > 1 && func(V[V.size()-2], adds, addb) <= func(V.back(), adds, addb)) V.pop_back();
        long long x = V.back().x;
        long long y = func(V.back(), adds, addb);
        cout << x + 1 << ' ' << y << endl;
    }
    return 0;
}