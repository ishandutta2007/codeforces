#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>
#include <complex>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef double DB;

#define pb push_back
#define mset(a, b) memset(a, b, sizeof a)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))
#define cnti(x) (__builtin_popcount(x))
#define cntl(x) (__builtin_popcountll(x))
#define clzi(x) (__builtin_clz(x))
#define clzl(x) (__builtin_clzll(x))
#define ctzi(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))

#define X first
#define Y second

#define Error(x) cout << #x << " = " << x << endl

const int MAXN = 5011;
int c[MAXN], a[MAXN][MAXN];
int x[MAXN];
vector<int> res[1111111];
int l[1111111], ans[1111111];

class BI {
private:
	static const int B = 1 << 30;
	VI v;
	
	inline void push(LL x) {
		for (; x; x /= B) v.pb(x % B);
	}
	
	inline void pop() {
		while (!v.empty() && !v.back()) v.pop_back();
	}
	
	void mul_add(LL x, LL y) {
		for (int i = 0; i < sz(v); i++) {
			y += v[i] * x;
			v[i] = y % B;
			y /= B;
		}
		push(y);
		pop();
	}
	
public:
	void add(int x) {
		mul_add(1, x);
	}
	
	void mul(int x) {
		mul_add(x, 0);
	}
	
	void div(int x) {
		LL r = 0;
		for (int i = sz(v) - 1; i >= 0; i--) {
			r = r * B + v[i];
			v[i] = r / x;
			r %= x;
		}
		pop();
	}
	
	int mod(int x) {
		LL r = 0;
		for (int i = sz(v) - 1; i >= 0; i--) {
			r = (r * B + v[i]) % x;
		}
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
		int i, j, tp;
		v.clear();
		for (i = 0; s[i]; i++) {
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
	
	void to_str(char *s) {
		int k = 0;
		BI c = *this;
		while (!c.zero()) {
			s[k++] = '0' + c.mod(10);
			c.div(10);
		}
		reverse(s, s + k);
		s[k] = 0;
	}
	
	void print() {
		char t[2500]; to_str(t);
		printf("str = %s\n", t);
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
			c.v.pb(r % B);
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
			c.v.pb(t);
			r = (r - t) / B;
		}
		c.pop();
		return c;
	}
	
	BI operator*(const BI& b) const {
		BI c;
		int m = sz(v), n = sz(b.v);
		int i, j;
		c.v.resize(m + n);
		for (i = 0; i < m; i++) {
			LL r = 0;
			for (j = 0; j < n; j++) {
				r += LL(v[i]) * b.v[j] + c.v[i + j];
				c.v[i + j] = r & 1073741823;
				r >>= 30;
			}
			c.v[i + n] += r;
		}
		c.pop();
		return c;
	}
	
	BI operator/(const BI& b) const {
		BI q, r, t;
		int m = sz(v), n = sz(b.v);
		if (m < n) return q;
		int i, st, en, md;
		for (i = m - n + 1; i < m; i++) r.v.pb(v[i]);
		for (i = m - n; i >= 0; i--) {
			r.mul_add(B, v[i]);
			st = 0, en = B;
			while (st + 1 < en) {
				md = (st + en) / 2;
				t = b;
				t.mul(md);
				if (r < t) en = md;
				else st = md;
			}
			t = b;
			t.mul(st);
			r = r - t;
			q.v.pb(st);
		}
		reverse(all(q.v));
		q.pop();
		return q;
	}
	
	BI Pow(int k) {
		BI ret = BI("1");
		BI m = BI(v);
		if (m == ret) return ret;
		while (1) {
			if (k % 2) ret = ret * m;
			k /= 2;
			if (!k) break;
			m = m * m;
		}
		return ret;
	}
	
	
} pp;

int main() {
	
	int n, m, p;
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 0; i < n; i++) scanf("%d", l + i);
	
	a[1][1] = 1;
	for (int i = 2; i < MAXN; i++) {
		a[i][1] = 0;
		for (int j = 2; j <= i; j++) {
			a[i][j] = (1LL * a[i - 1][j - 1] * j + 1LL * a[i - 1][j] * (j - 1)) % p;
		}
	}
	c[0] = 1;
	pp = BI(1);
	for (int i = 1; i <= min(MAXN - 1, m); i++) {
		pp.mul(m - i + 1);
		pp.div(i);
		c[i] = pp.mod(p);
	}
	for (int i = 0; i < n; i++) {
		res[i].push_back(0);
		for (int j = 1; j <= min(m, l[i]); j++) {
			if (i == 0) {
				res[i].push_back(a[l[i]][j]);
			} else {
				if (j > l[i - 1]) res[i].push_back(1LL * ans[i - 1] * a[l[i]][j] % p);
				else res[i].push_back((1LL * (ans[i - 1] - res[i - 1][j]) * a[l[i]][j] % p + p) % p);
			}
			ans[i] = (1LL * res[i][j] * c[j] + ans[i]) % p;
		}
	}
	cout<<ans[n - 1]<<endl;
	return 0;
}