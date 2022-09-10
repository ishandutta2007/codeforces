#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <iomanip>
#include <cassert>
#include <string.h>
#include <cstdio>
#include <complex>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef double LD;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LD, LD> PDD;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;
typedef vector<LL> VLL;
typedef complex<LD> base;
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define next fake_next

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i, 0, t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))

const LD PI = acos(-1.0);
const LD EPS = 1e-9;
const LL INF = 1e9;
const LL LINF = 1e18;
const LL mod = 1e9 + 7;
const LL MAX = 1 << 22;

namespace fft {
	typedef double dbl;

	struct num {
		dbl x, y;
		num() { x = y = 0; }
		num(dbl x, dbl y) : x(x), y(y) { }
	};

	inline num operator+(num a, num b) { return num(a.x + b.x, a.y + b.y); }
	inline num operator-(num a, num b) { return num(a.x - b.x, a.y - b.y); }
	inline num operator*(num a, num b) { return num(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
	inline num conj(num a) { return num(a.x, -a.y); }

	int base = 1;
	vector<num> roots = { { 0, 0 },{ 1, 0 } };
	vector<int> rev = { 0, 1 };

	const dbl PI = acosl(-1.0);

	void ensure_base(int nbase) {
		if (nbase <= base) {
			return;
		}
		rev.resize(1 << nbase);
		for (int i = 0; i < (1 << nbase); i++) {
			rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
		}
		roots.resize(1 << nbase);
		while (base < nbase) {
			dbl angle = 2 * PI / (1 << (base + 1));
			//      num z(cos(angle), sin(angle));
			for (int i = 1 << (base - 1); i < (1 << base); i++) {
				roots[i << 1] = roots[i];
				//        roots[(i << 1) + 1] = roots[i] * z;
				dbl angle_i = angle * (2 * i + 1 - (1 << base));
				roots[(i << 1) + 1] = num(cos(angle_i), sin(angle_i));
			}
			base++;
		}
	}

	void fft(vector<num> &a, int n = -1) {
		if (n == -1) {
			n = a.size();
		}
		assert((n & (n - 1)) == 0);
		int zeros = __builtin_ctz(n);
		ensure_base(zeros);
		int shift = base - zeros;
		for (int i = 0; i < n; i++) {
			if (i < (rev[i] >> shift)) {
				swap(a[i], a[rev[i] >> shift]);
			}
		}
		for (int k = 1; k < n; k <<= 1) {
			for (int i = 0; i < n; i += 2 * k) {
				for (int j = 0; j < k; j++) {
					num z = a[i + j + k] * roots[j + k];
					a[i + j + k] = a[i + j] - z;
					a[i + j] = a[i + j] + z;
				}
			}
		}
		/*    for (int len = 1; len < n; len <<= 1) {
		for (int i = 0; i < n; i += 2 * len) {
		for (int j = i, k = i + len; j < i + len; j++, k++) {
		num z = a[k] * roots[k - i];
		a[k] = a[j] - z;
		a[j] = a[j] + z;
		}
		}
		}*/
	}

	vector<num> fa, fb;

	vector<int> multiply(vector<int> &a, vector<int> &b) {
		int need = a.size() + b.size() - 1;
		int nbase = 0;
		while ((1 << nbase) < need) nbase++;
		ensure_base(nbase);
		int sz = 1 << nbase;
		if (sz > (int)fa.size()) {
			fa.resize(sz);
		}
		for (int i = 0; i < sz; i++) {
			int x = (i < (int)a.size() ? a[i] : 0);
			int y = (i < (int)b.size() ? b[i] : 0);
			fa[i] = num(x, y);
		}
		fft(fa, sz);
		num r(0, -0.25 / sz);
		for (int i = 0; i <= (sz >> 1); i++) {
			int j = (sz - i) & (sz - 1);
			num z = (fa[j] * fa[j] - conj(fa[i] * fa[i])) * r;
			if (i != j) {
				fa[j] = (fa[i] * fa[i] - conj(fa[j] * fa[j])) * r;
			}
			fa[i] = z;
		}
		fft(fa, sz);
		vector<int> res(need);
		for (int i = 0; i < need; i++) {
			res[i] = fa[i].x + 0.5;
		}
		return res;
	}

	vector<int> multiply_mod(vector<int> &a, vector<int> &b, int m, int eq = 0) {
		int need = a.size() + b.size() - 1;
		int nbase = 0;
		while ((1 << nbase) < need) nbase++;
		ensure_base(nbase);
		int sz = 1 << nbase;
		if (sz > (int)fa.size()) {
			fa.resize(sz);
		}
		for (int i = 0; i < (int)a.size(); i++) {
			int x = (a[i] % m + m) % m;
			fa[i] = num(x & ((1 << 15) - 1), x >> 15);
		}
		fill(fa.begin() + a.size(), fa.begin() + sz, num{ 0, 0 });
		fft(fa, sz);
		if (sz >(int) fb.size()) {
			fb.resize(sz);
		}
		if (eq) {
			copy(fa.begin(), fa.begin() + sz, fb.begin());
		}
		else {
			for (int i = 0; i < (int)b.size(); i++) {
				int x = (b[i] % m + m) % m;
				fb[i] = num(x & ((1 << 15) - 1), x >> 15);
			}
			fill(fb.begin() + b.size(), fb.begin() + sz, num{ 0, 0 });
			fft(fb, sz);
		}
		dbl ratio = 0.25 / sz;
		num r2(0, -1);
		num r3(ratio, 0);
		num r4(0, -ratio);
		num r5(0, 1);
		for (int i = 0; i <= (sz >> 1); i++) {
			int j = (sz - i) & (sz - 1);
			num a1 = (fa[i] + conj(fa[j]));
			num a2 = (fa[i] - conj(fa[j])) * r2;
			num b1 = (fb[i] + conj(fb[j])) * r3;
			num b2 = (fb[i] - conj(fb[j])) * r4;
			if (i != j) {
				num c1 = (fa[j] + conj(fa[i]));
				num c2 = (fa[j] - conj(fa[i])) * r2;
				num d1 = (fb[j] + conj(fb[i])) * r3;
				num d2 = (fb[j] - conj(fb[i])) * r4;
				fa[i] = c1 * d1 + c2 * d2 * r5;
				fb[i] = c1 * d2 + c2 * d1;
			}
			fa[j] = a1 * b1 + a2 * b2 * r5;
			fb[j] = a1 * b2 + a2 * b1;
		}
		fft(fa, sz);
		fft(fb, sz);
		vector<int> res(need);
		for (int i = 0; i < need; i++) {
			long long aa = fa[i].x + 0.5;
			long long bb = fb[i].x + 0.5;
			long long cc = fa[i].y + 0.5;
			res[i] = (aa + ((bb % m) << 15) + ((cc % m) << 30)) % m;
		}
		return res;
	}

	vector<int> square_mod(vector<int> &a, int m) {
		return multiply_mod(a, a, m, 1);
	}
};
void multiply(vector<int>& a, int b)
{
	int carry = 0;
	FOR(i, 0, SZ(a))
	{
		carry += a[i] * b;
		a[i] = carry % 10;
		carry /= 10;
	}

	while (carry)
	{
		a.push_back(carry % 10);
		carry /= 10;
	}
}

void divide(vector<int>& a, int b)
{
	int carry = 0;
	RFOR(i, SZ(a), 0)
	{
		carry *= 10;
		carry += a[i];
		a[i] = carry / b;
		carry %= b;
	}

	while (SZ(a) > 1 && a.back() == 0)
		a.pop_back();
}

bool cmp(vector<int>& a, vector<int>& b)
{
	if (SZ(a) != SZ(b))
		return SZ(a) < SZ(b);

	RFOR(i, SZ(a), 0)
	{
		if (a[i] < b[i])
			return 1;
		if (a[i] > b[i])
			return 0;
	}

	return 0;
}

vector<int> multiply(vector<int> a)
{
	reverse(ALL(a));
	vector<int> c = fft::multiply(a, a);
	c.resize(SZ(a) + SZ(a) - 1);

	vector<int> res(SZ(c));
	int carry = 0;

	FOR(i, 0, SZ(c))
	{
		res[i] = carry + c[SZ(c) - 1 - i];
		carry = res[i] / 10;
		res[i] %= 10;
	}

	while (carry)
	{
		res.push_back(carry);
		carry /= 10;
	}

	//reverse(ALL(res));
	return res;
}

vector<int> power3;

void get_power3(int pw)
{
	if (pw <= 0)
		return;

	if (pw & 1)
	{
		get_power3(pw - 1);
		multiply(power3, 3);
		return;
	}

	get_power3(pw >> 1);
	power3 = fft::multiply(power3, power3);
	int carry = 0;
	FOR(i, 0, SZ(power3))
	{
		carry += power3[i];
		power3[i] = carry % 10;
		carry /= 10;
	}

	while (carry)
	{
		power3.push_back(carry % 10);
		carry /= 10;
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	string n;
	cin >> n;
	if (n == "1")
	{
		cout << 1 << endl;
		return 0;
	}

	int len = SZ(n);
	vector<int> rev(len);
	FOR(i, 0, len)
		rev[i] = (n[len - 1 - i] - '0');

	int p3 = logl(10) * (len - 1) / logl(3);
	power3.assign(1, 1);
	get_power3(p3);

	int ans = 3 * p3;
	while (cmp(power3, rev))
	{
		if (ans <= 3)
			power3[0] = ans + 1;
		else
		{
			if (ans % 3 == 0) {
				divide(power3, 3);
				multiply(power3, 4);
			}
			else
			{
				divide(power3, 2);
				multiply(power3, 3);
			}
		}

		ans++;
	}

	cout << ans << endl;
	cin >> n;
	return 0;
}